#include "BuyTask.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"

BuyTask::BuyTask() : BuyTask(nullptr, nullptr, nullptr) {
}

BuyTask::BuyTask(BehaviorTree* tree, FlowNode* nodeParent, Customer* _customer) : TaskNode(tree, nodeParent), customer(_customer) {
}

BuyTask::~BuyTask() {
}

void BuyTask::BeginExecute() {
	CustomerBlackBoard* _blackBoard = static_cast<CustomerBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		customer = _blackBoard->customer;
		merchant = _blackBoard->merchant;
	}
}

void BuyTask::Tick(float dt) {
	TaskNode::Tick(dt);
	if (customer->canBuy) {
		customer->Buy(merchant, 1); // 1 = le nb de marchandise achetees
	}
	EndExecute();
}

void BuyTask::EndExecute() {
	if (customer->canBuy) {
		parent->OnChildEnd(ENodeState::Success);
	}
	else {
		parent->OnChildEnd(ENodeState::Failure);
	}
}
