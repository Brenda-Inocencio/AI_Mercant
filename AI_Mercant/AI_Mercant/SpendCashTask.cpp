#include "SpendCashTask.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"
#include "Pnj.h"
#include "GameDay.h"

SpendCashTask::SpendCashTask() : SpendCashTask(nullptr, nullptr) {
}

SpendCashTask::SpendCashTask(BehaviorTree* tree, FlowNode* nodeParent) : TaskNode(tree, nodeParent) {
}

SpendCashTask::~SpendCashTask() {
}

void SpendCashTask::BeginExecute() {
	MerchantBlackBoard* _blackBoard = static_cast<MerchantBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		merchant = _blackBoard->merchant;
		day = _blackBoard->day;
		cash = merchant->GetCash();
	}
}

void SpendCashTask::Tick(float dt) {
	TaskNode::Tick(dt);
	if (day->m_phase == DayPhase::Evening && merchant->canBuy) {
		merchant->SpendCash(10);
	}
	EndExecute();
}

void SpendCashTask::EndExecute() {
	if (day->m_phase == DayPhase::Evening && merchant->GetCash() < cash) {
		parent->OnChildEnd(ENodeState::Success);
	}
	else { 
		parent->OnChildEnd(ENodeState::Failure); 
	}
}
