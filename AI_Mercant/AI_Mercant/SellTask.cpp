#include "SellTask.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"
#include "Pnj.h"
#include "GameDay.h" 

SellTask::SellTask() : SellTask(nullptr, nullptr) {
}

SellTask::SellTask(BehaviorTree* tree, FlowNode* nodeParent) : TaskNode(tree, nodeParent) {
}

SellTask::~SellTask() {
}

void SellTask::BeginExecute() {
	MerchantBlackBoard* _blackBoard = static_cast<MerchantBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		merchant = _blackBoard->merchant;
		merchandise = merchant->GetMerchandise();
		day = _blackBoard->day;
	}
}

void SellTask::Tick(float dt) {
	TaskNode::Tick(dt);
	if (day->m_phase == DayPhase::Day && merchant->client) {
		merchant->SellMerchandise();
	}
	EndExecute();
}

void SellTask::EndExecute() {
	if (day->m_phase == DayPhase::Day && merchandise > merchant->GetMerchandise()) {
		parent->OnChildEnd(ENodeState::Success);
	}
	else {
		parent->OnChildEnd(ENodeState::Failure);
	}
}
