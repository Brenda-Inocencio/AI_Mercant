#include "BuyFurnituresTask.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"
#include "Pnj.h"
#include "GameDay.h"

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
		day = _blackBoard->day;
	}
}

void BuyFurnituresTask::Tick(float dt) {
	TaskNode::Tick(dt);
	if (day->m_phase == DayPhase::Evening) {
		merchant->Order(10);
	}
	EndExecute();
}

void BuyFurnituresTask::EndExecute() {
	if (day->m_phase == DayPhase::Evening && merchant->canBuy) {
		parent->OnChildEnd(ENodeState::Success);
	}
	else {
		parent->OnChildEnd(ENodeState::Failure);
	}
}
