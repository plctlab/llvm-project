#ifndef LLVM_TRANSFORMS_VECTORPREDICATION_H
#define LLVM_TRANSFORMS_VECTORPREDICATION_H

#include "llvm/ADT/MapVector.h"
#include "llvm/IR/PassManager.h"

namespace llvm {

using InstToMaskEVLMap = DenseMap<Instruction *, std::pair<Value *, Value *>>;

struct BlockData {
  // Vector that stores all vector predicated memory writing operations found in
  // the basic block. If after phase 1 is empty, then the basic block can be
  // skipped by following phases.
  SmallVector<Instruction *> MemoryWritingVPInstructions;

  // Store all instructions of the basic block (in the same order as they are
  // found), assigning to each the list of users. Skip PHIs and terminators.
  MapVector<Instruction *, SmallPtrSet<Instruction *, 4>> TopologicalGraph;

  // Map each full-length vector operation eligible to be transformed to a
  // vector predication one with the (mask,evl) pair of its first vector
  // predicated memory writing operation user.
  InstToMaskEVLMap VecOpsToTransform;

  // Ordered list representing the reverse order of how the basic block has to
  // be transformed due to the new vector predicated instructions.
  SmallVector<Instruction *> NewBBReverseOrder;

  BlockData() = default;
};

class VectorPredicationPass : public PassInfoMixin<VectorPredicationPass> {
private:
  // List of instructions to be replaced by the new VP operations and that later
  // should be removed, if possible.
  DenseMap<Instruction *, Value *> OldInstructionsToRemove;

  void analyseBasicBlock(BasicBlock &BB, BlockData &BBInfo);
  void findCandidateVectorOperations(BasicBlock &BB, BlockData &BBInfo);
  void addNewUsersToMasksAndEVLs(BasicBlock &BB, BlockData &BBInfo);
  void buildNewBasicBlockSchedule(BasicBlock &BB, BlockData &BBInfo);
  void emitNewBasicBlockSchedule(BasicBlock &BB, BlockData &BBInfo);
  void transformCandidateVectorOperations(BasicBlock &BB, BlockData &BBInfo);

  void removeOldInstructions();

public:
  PreservedAnalyses run(Function &F, FunctionAnalysisManager &AM);
  static StringRef name() { return "VectorPredicationPass"; }
};

} // namespace llvm

#endif // LLVM_TRANSFORMS_VECTORPREDICATION_H
