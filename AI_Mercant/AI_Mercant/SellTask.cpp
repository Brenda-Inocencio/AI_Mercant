#include "SellTask.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"

SellTask::SellTask() : SellTask(nullptr, nullptr) {
}

SellTask::SellTask(BehaviorTree* tree, FlowNode* nodeParent) : TaskNode(tree, nodeParent){
}

SellTask::~SellTask() {
}

void SellTask::BeginExecute() {
	MerchantBlackBoard* _blackBoard = static_cast<MerchantBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		furnitures = _blackBoard->furnitures;
	}
}

void SellTask::Tick(float dt) {
	TaskNode::Tick(dt);
	furnitures -= 1;
	EndExecute();
}

void SellTask::EndExecute() {
	if (furnitures >= 0) {
		parent->OnChildEnd(ENodeState::Success);
	}
	else {
		parent->OnChildEnd(ENodeState::Failure);
	}
}
