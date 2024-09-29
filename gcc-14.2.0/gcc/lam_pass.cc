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

void handle_integer_cst(pretty_printer *pp, gimple *stmt, tree *rhs) {
  if (TREE_INT_CST_LOW(*rhs) & LAM_MASK)
    error("LAM offset overflowed at %s:%d\n", gimple_filename(stmt),
          gimple_lineno(stmt));
}

void handle_lam_component_ref(pretty_printer *pp, gimple *stmt, tree *rhs) {
  tree off = component_ref_field_offset(*rhs);
  if (TREE_CODE(off) == INTEGER_CST) {
    handle_integer_cst(pp, stmt, &off);
  } else {
    pp_printf(pp, "Unhandled offset type %s\n",
              get_tree_code_name(TREE_CODE(off)));
  }
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
    if (op == COMPONENT_REF) {
      handle_lam_component_ref(pp, stmt, &rhs1);
    } else if (op == INTEGER_CST) {
      handle_integer_cst(pp, stmt, &rhs1);
    } else if (op == CALL_EXPR) {

    } else if (op == SSA_NAME) {
      // SSA_NAME must a valid pointer type.
      return;
    } else {
      pp_printf(pp, "Unhandled RHS%s \n", get_tree_code_name(op));
    }

  } else if (is_gimple_call(stmt)) {

  } else if (gimple_code(stmt) == GIMPLE_PHI) {
    // PHI node must be a valid pointer type.
    return;
  } else {
    pp_printf(pp, "Unhandled stmt %s\n", gimple_code_name[gimple_code(stmt)]);
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
