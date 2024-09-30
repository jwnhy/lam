#include "config.h"
#include "errors.h"
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "rtl.h"
#include "c-family/c-common.h"
#include "gimple.h"
#include "cfghooks.h"
#include "tree-pass.h"
#include "memmodel.h"
#include "tm_p.h"
#include "ssa.h"
#include "cgraph.h"
#include "tree-pretty-print.h"
#include "stor-layout.h"
#include "cfganal.h"
#include "gimple-iterator.h"
#include "output.h"
#include "cfgloop.h"
#include "ubsan.h"
#include "expr.h"
#include "stringpool.h"
#include "attribs.h"
#include "asan.h"
#include "gimplify-me.h"
#include "dfp.h"
#include "builtins.h"
#include "tree-object-size.h"
#include "tree-cfg.h"
#include "gimple-fold.h"
#include "varasm.h"
#include "realmpfr.h"
#include "target.h"
#include "langhooks.h"
#include "pretty-print.h"
#include "gimple-pretty-print.h"

namespace {
const pass_data pass_data_lam = {
    GIMPLE_PASS, "lam", OPTGROUP_NONE,   TV_NONE, (PROP_cfg | PROP_ssa), 0,
    0,           0,     TODO_update_ssa,
};
};

const unsigned long long LAM_MASK = (0x7fffULL << 47);

class pass_lam : public gimple_opt_pass {
public:
  pass_lam(gcc::context *ctxt) : gimple_opt_pass(pass_data_lam, ctxt) {}

  unsigned int execute(function *fun) final override;
};

bool is_special_cst(tree t) {
  return TREE_CODE(t) == INTEGER_CST &&
         ((TREE_INT_CST_LOW(t) & LAM_MASK) == LAM_MASK);
}

void handle_integer_cst(gimple_stmt_iterator *gsi, tree *rhs,
                        bool strict = true) {
  gimple *stmt = gsi_stmt(*gsi);
  if (!(TREE_INT_CST_LOW(*rhs) & LAM_MASK))
    return;
  if (strict) {
    error("LAM offset overflowed with 0x%lx at %s:%d\n", TREE_INT_CST_LOW(*rhs),
          gimple_filename(stmt), gimple_lineno(stmt));
  }
}

void handle_pointer_plus(gimple_stmt_iterator *gsi) {
  gimple *stmt = gsi_stmt(*gsi);
  tree lhs = gimple_assign_lhs(stmt);
  tree lhstype = TREE_TYPE(lhs);
  tree rhs1 = gimple_assign_rhs1(stmt);
  tree llu_type = long_long_unsigned_type_node;

  tree rhs_int_expr = fold_build1(NOP_EXPR, llu_type, rhs1);
  tree rhs1_int = make_ssa_name(llu_type);
  gimple *rhs_conv_stmt = gimple_build_assign(rhs1_int, rhs_int_expr);
  gsi_insert_before(gsi, rhs_conv_stmt, GSI_SAME_STMT);

  tree mask = build_int_cstu(llu_type, LAM_MASK);
  tree save_node = make_ssa_name(llu_type);
  tree save_expr = build2(BIT_AND_EXPR, llu_type, rhs1_int, mask);
  gimple *save_stmt = gimple_build_assign(save_node, save_expr);
  gsi_insert_before(gsi, save_stmt, GSI_SAME_STMT);

  tree replaced_lhs = make_ssa_name(lhstype);
  gimple_assign_set_lhs(stmt, replaced_lhs);

  tree lhs_int_expr = fold_build1(NOP_EXPR, llu_type, replaced_lhs);
  tree lhs_int = make_ssa_name(llu_type);
  gimple *lhs_conv_stmt = gimple_build_assign(lhs_int, lhs_int_expr);
  gsi_insert_after(gsi, lhs_conv_stmt, GSI_LAST_NEW_STMT);

  tree inv_mask = build_int_cstu(llu_type, ~LAM_MASK);
  tree clear_node = make_ssa_name(llu_type);
  tree clear_expr = build2(BIT_AND_EXPR, llu_type, lhs_int, inv_mask);
  gimple *clear_stmt = gimple_build_assign(clear_node, clear_expr);
  gsi_insert_after(gsi, clear_stmt, GSI_LAST_NEW_STMT);

  tree restore_expr = build2(BIT_IOR_EXPR, lhstype, clear_node, lhs_int);
  tree lhs_int_ssa = make_ssa_name(llu_type);
  gimple *restore_stmt = gimple_build_assign(lhs_int_ssa, restore_expr);
  gsi_insert_after(gsi, restore_stmt, GSI_LAST_NEW_STMT);

  tree lhs_ptr_expr = fold_build1(NOP_EXPR, lhstype, lhs_int);
  gimple *lhs_ptr_stmt = gimple_build_assign(lhs, lhs_ptr_expr);
  gsi_insert_after(gsi, lhs_ptr_stmt, GSI_LAST_NEW_STMT);

  update_stmt(stmt);
}

void handle_lam_stmt(pretty_printer *pp, gimple_stmt_iterator *gsi) {
  gimple *stmt = gsi_stmt(*gsi);
  if (is_gimple_assign(stmt)) {
    tree lhs = gimple_assign_lhs(stmt);
    tree lhstype = TREE_TYPE(lhs);
    if (!POINTER_TYPE_P(lhstype))
      return;
    tree_code op = gimple_assign_rhs_code(stmt);
    tree rhs1 = gimple_assign_rhs1(stmt);
    if (op == INTEGER_CST) {
      // not a special constant, e.g., -1
      if (!is_special_cst(rhs1))
        handle_integer_cst(gsi, &rhs1);
    } else if (op == POINTER_PLUS_EXPR) {
      handle_pointer_plus(gsi);
    } else if (op == ADDR_EXPR) {
      tree inner = TREE_OPERAND(rhs1, 0);
    } else if (op == CALL_EXPR || op == SSA_NAME || op == COMPONENT_REF ||
               op == POINTER_DIFF_EXPR) {
      return;
    } else {
      pp_printf(pp, "Unhandled RHS%s \n", get_tree_code_name(op));
    }
  } else if (is_gimple_call(stmt)) {

  } else if (gimple_code(stmt) == GIMPLE_PHI) {
    // PHI node must be a valid pointer type.
    return;
  } else {
    pp_printf(pp, "Unhandled stmt %s \n", gimple_code_name[gimple_code(stmt)]);
  }
}

unsigned int pass_lam::execute(function *fun) {
  pretty_printer pp;
  FILE *f = fopen("lam_pass.log", "a+");
  pp.buffer->stream = f;

  basic_block bb;
  gimple_stmt_iterator gsi;
  unsigned int ret = 0;

  FOR_EACH_BB_FN(bb, fun) {
    for (gsi = gsi_start_bb(bb); !gsi_end_p(gsi); gsi_next(&gsi)) {
      gimple *stmt = gsi_stmt(gsi);
      if (is_gimple_debug(stmt) || gimple_clobber_p(stmt)) {
        continue;
      }
      handle_lam_stmt(&pp, &gsi);
    }
  }
  pp_flush(&pp);
  fclose(f);

  return ret;
}

gimple_opt_pass *make_pass_lam(gcc::context *ctxt) {
  return new pass_lam(ctxt);
}
