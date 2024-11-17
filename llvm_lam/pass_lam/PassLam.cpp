#include "stdlib.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Pass.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

const uint64_t LAM_MASK = ~(0x3fffull << 48);

namespace {
class LamModulePass : public PassInfoMixin<LamModulePass> {
public:
  PreservedAnalyses run(Module &M, ModuleAnalysisManager &) {
    for (Function &F : M) {
      if (F.isDeclaration())
        continue;
      errs() << "Function: " << F.getName() << "\n";
      for (BasicBlock &BB : F) {
        for (Instruction &I : BB) {
          if (I.getOpcode() == Instruction::IntToPtr) {
            BinaryOperator *MaskInst = BinaryOperator::CreateAnd(
                I.getOperand(0),
                ConstantInt::get(I.getOperand(0)->getType(), LAM_MASK));
            printf("%lx\n", LAM_MASK);
            MaskInst->insertBefore(&I);
          }
        }
      }
    }
    for (Function &F : M) {
      for (BasicBlock &BB : F) {
        for (Instruction &I : BB) {
          errs() << "  " << I << I.getOperand(0)->getName() << "\n";
        }
      }
    }
    return PreservedAnalyses::all();
  }

  static bool isRequired() { return true; }
};
} // namespace
  //
llvm::PassPluginLibraryInfo getLamPassInfo() {
  return {LLVM_PLUGIN_API_VERSION, "LAM", LLVM_VERSION_STRING,
          [](PassBuilder &PB) {
            PB.registerPipelineParsingCallback(
                [](StringRef Name, ModulePassManager &MPM,
                   ArrayRef<PassBuilder::PipelineElement>) {
                  if (Name == "lam-module") {
                    MPM.addPass(LamModulePass());
                    return true;
                  }
                  return false;
                });
          }};
}

extern "C" LLVM_ATTRIBUTE_WEAK ::llvm::PassPluginLibraryInfo
llvmGetPassPluginInfo() {
  return getLamPassInfo();
}
