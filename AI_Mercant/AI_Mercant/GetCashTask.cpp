#include "GetCashTask.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"

GetCashTask::GetCashTask() : GetCashTask(nullptr, nullptr) {
}

GetCashTask::GetCashTask(BehaviorTree* tree, FlowNode* nodeParent) : TaskNode(tree, nodeParent) {
}

GetCashTask::~GetCashTask() {
}

void GetCashTask::BeginExecute() {
	MerchantBlackBoard* _blackBoard = static_cast<MerchantBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		merchant = _blackBoard->merchant;
		cash = merchant->GetCash();
	}
}

void GetCashTask::Tick(float dt) {
	TaskNode::Tick(dt);
	if (merchant->canSell) {
		merchant->Cash(1); // 1 = le nb de marchandise vendues
	}
	EndExecute();
}

void GetCashTask::EndExecute() {
	if (merchant->GetCash() > cash) {
		parent->OnChildEnd(ENodeState::Success);
	}
}
