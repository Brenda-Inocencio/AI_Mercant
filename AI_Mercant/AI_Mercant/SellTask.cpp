#include "SellTask.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"

SellTask::SellTask() : SellTask(nullptr, nullptr, nullptr) {
}

SellTask::SellTask(BehaviorTree* tree, FlowNode* nodeParent, Merchant* _merchant) : TaskNode(tree, nodeParent), merchant(_merchant) {
}

SellTask::~SellTask() {
}

void SellTask::BeginExecute() {
	MerchantBlackBoard* _blackBoard = static_cast<MerchantBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		merchant = _blackBoard->merchant;
	}
}

void SellTask::Tick(float dt) {
	TaskNode::Tick(dt);
	merchant->Sell(1); //1 = le nb de marchandise vendues
	EndExecute();
}

void SellTask::EndExecute() {
	if (merchant->canSell) {
		parent->OnChildEnd(ENodeState::Success);
	}
	else {
		parent->OnChildEnd(ENodeState::Failure);
	}
}
