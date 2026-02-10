#include "BuyFurnituresTask.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"

BuyFurnituresTask::BuyFurnituresTask() : BuyFurnituresTask(nullptr, nullptr) {
}

BuyFurnituresTask::BuyFurnituresTask(BehaviorTree* tree, FlowNode* nodeParent) : TaskNode(tree, nodeParent) {
}

BuyFurnituresTask::~BuyFurnituresTask() {
}

void BuyFurnituresTask::BeginExecute() {
	MerchantBlackBoard* _blackBoard = static_cast<MerchantBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		merchant = _blackBoard->merchant;
	}
}

void BuyFurnituresTask::Tick(float dt) {
	TaskNode::Tick(dt);
	merchant->Order(10); // 1 = nb de fourniture achete
	EndExecute();
}

void BuyFurnituresTask::EndExecute() {
	if (merchant->canBuy) {
		parent->OnChildEnd(ENodeState::Success);
	}
	else {
		parent->OnChildEnd(ENodeState::Failure);
	}
}
