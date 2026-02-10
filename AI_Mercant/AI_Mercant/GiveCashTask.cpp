#include "GiveCashTask.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"

GiveCashTask::GiveCashTask() : GiveCashTask(nullptr, nullptr) {
}

GiveCashTask::GiveCashTask(BehaviorTree* tree, FlowNode* nodeParent) : TaskNode(tree, nodeParent) {
}

GiveCashTask::~GiveCashTask() {
}

void GiveCashTask::BeginExecute() {
	CustomerBlackBoard* _blackBoard = static_cast<CustomerBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		customer = _blackBoard->customer;
		merchant = _blackBoard->merchant;
		cash = customer->GetCash();
	}
}

void GiveCashTask::Tick(float dt) {
	TaskNode::Tick(dt);
	if (customer->canBuy) {
		customer->SpendCash(merchant, 1);  // 1 = le nb de marchandise achetees
	}
	EndExecute();
}

void GiveCashTask::EndExecute() {
	if (customer->GetCash() < cash) {
		parent->OnChildEnd(ENodeState::Success);
	}
}
