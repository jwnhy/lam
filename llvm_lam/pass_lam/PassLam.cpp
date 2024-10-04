#include "llvm/IR/Function.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Pass.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace {

class LamModPass : public PassInfoMixin<LamModPass> {
public:
  PreservedAnalyses run(Module &M, ModulePassManager &) {
    errs() << M.getName() << "\n";
    return PreservedAnalyses::all();
  }

  static bool isRequired() { return true; }
};

} // namespace
  //
llvm::PassPluginLibraryInfo getLamModPassInfo() {
  return {LLVM_PLUGIN_API_VERSION, "LamMod", LLVM_VERSION_STRING,
          [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef Name, ModulePassManager &MPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                  if (Name == "lam-mod") {
                    MPM.addPass(LamModPass());
                    return true;
                  }
                  return false;
                });
          }};
}

extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo llvmGetPassPluginInfo() {
  return getLamModPassInfo();
}
