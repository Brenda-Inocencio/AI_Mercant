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
		furnitures = _blackBoard->furnitures;
	}
}

void BuyFurnituresTask::Tick(float dt) {
	TaskNode::Tick(dt);
	newFurnitures = furnitures + 1;
	EndExecute();
}

void BuyFurnituresTask::EndExecute() {
	if (newFurnitures > furnitures) {
		parent->OnChildEnd(ENodeState::Success);
	}
	else {
		parent->OnChildEnd(ENodeState::Failure);
	}
}
