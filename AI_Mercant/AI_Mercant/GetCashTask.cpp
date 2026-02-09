#include "GetCashTask.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"

GetCashTask::GetCashTask() : GetCashTask(nullptr, nullptr) {
}

GetCashTask::GetCashTask(BehaviorTree* tree, FlowNode* nodeParent) : TaskNode(tree, nodeParent){
}

GetCashTask::~GetCashTask() {
}

void GetCashTask::BeginExecute() {
	MerchantBlackBoard* _blackBoard = static_cast<MerchantBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		cash = _blackBoard->cash;
		price = _blackBoard->price;
	}
}

void GetCashTask::Tick(float dt) {
	TaskNode::Tick(dt);
	newCash = cash + price;
	EndExecute();
}

void GetCashTask::EndExecute() {
	if (newCash > cash) {
		parent->OnChildEnd(ENodeState::Success);
	}
	else {
		parent->OnChildEnd(ENodeState::Failure);
	}
}
