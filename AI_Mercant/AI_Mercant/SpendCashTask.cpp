#include "SpendCashTask.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"

SpendCashTask::SpendCashTask() : SpendCashTask(nullptr, nullptr) {
}

SpendCashTask::SpendCashTask(BehaviorTree* tree, FlowNode* nodeParent) : TaskNode(tree, nodeParent) {
}

SpendCashTask::~SpendCashTask() {
}

void SpendCashTask::BeginExecute() {
	MerchantBlackBoard* _blackBoard = static_cast<MerchantBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		cash = _blackBoard->cash;
		price = _blackBoard->furnituresPrice;
	}
}

void SpendCashTask::Tick(float dt) {
	TaskNode::Tick(dt);
	newCash = cash + price;
	EndExecute();
}

void SpendCashTask::EndExecute() {
	if (newCash < cash) {
		parent->OnChildEnd(ENodeState::Success);
	}
	else {
		parent->OnChildEnd(ENodeState::Failure);
	}
}
