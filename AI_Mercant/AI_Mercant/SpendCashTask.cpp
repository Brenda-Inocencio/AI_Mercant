#include "SpendCashTask.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"

SpendCashTask::SpendCashTask() : SpendCashTask(nullptr, nullptr, nullptr) {
}

SpendCashTask::SpendCashTask(BehaviorTree* tree, FlowNode* nodeParent, Merchant* _merchant) : TaskNode(tree, nodeParent), merchant(_merchant) {
}

SpendCashTask::~SpendCashTask() {
}

void SpendCashTask::BeginExecute() {
	MerchantBlackBoard* _blackBoard = static_cast<MerchantBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		merchant = _blackBoard->merchant;
		cash = merchant->GetCash();
	}
}

void SpendCashTask::Tick(float dt) {
	TaskNode::Tick(dt);
	if (merchant->canBuy) {
		merchant->SpendCash(10);  // 1 = le nb de marchandise
	}
	EndExecute();
}

void SpendCashTask::EndExecute() {
	if (merchant->GetCash() < cash) {
		parent->OnChildEnd(ENodeState::Success);
	}
}
