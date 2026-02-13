#include "PauseTask.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"

PauseTask::PauseTask() : PauseTask(nullptr, nullptr) {
}

PauseTask::PauseTask(BehaviorTree* tree, FlowNode* nodeParent) : TaskNode(tree, nodeParent) {
}

PauseTask::~PauseTask() {
}

void PauseTask::BeginExecute() {
	MerchantBlackBoard* _blackBoard = static_cast<MerchantBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		day = _blackBoard->day;
	}
}

void PauseTask::Tick(float dt) {
	TaskNode::Tick(dt);
	EndExecute();
}

void PauseTask::EndExecute() {
	if (day->m_phase == DayPhase::Day) {
		parent->OnChildEnd(ENodeState::Success);
	}
	else {
		parent->OnChildEnd(ENodeState::Failure);
	}
}
