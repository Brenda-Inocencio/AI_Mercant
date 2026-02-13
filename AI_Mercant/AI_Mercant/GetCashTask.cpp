#include "GetCashTask.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"
#include "Pnj.h"
#include "GameDay.h"

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
		day = _blackBoard->day;
		cash = merchant->GetCash();
	}
}

void GetCashTask::Tick(float dt) {
	TaskNode::Tick(dt);
	if (day->m_phase == DayPhase::Day && merchant->canSell) {
		merchant->Cash();
	}
	EndExecute();
}

void GetCashTask::EndExecute() {
	if (day->m_phase == DayPhase::Day && merchant->GetCash() > cash) {
		parent->OnChildEnd(ENodeState::Success);
	}
}
