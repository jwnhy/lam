#include "llvm/IR/Function.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {

class LamModPass : public ModulePass {
public:
  LamModPass() : ModulePass(ID) {}

  bool runOnModule(Module &M) override;

  static char ID;
};
} // namespace

char LamModPass::ID = 0;

bool LamModPass::runOnModule(Module &M) {
  errs() << M.getName() << "\n";
  return false;
}

static RegisterPass<LamModPass> RegLamModPass("lammod",
                                              "LAM Module Pass", false, false);
