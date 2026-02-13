#include "GetFurnitures.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"
#include "Pnj.h"
#include "GameDay.h"

GetFurnitures::GetFurnitures() : GetFurnitures(nullptr, nullptr) {
}

GetFurnitures::GetFurnitures(BehaviorTree* tree, FlowNode* nodeParent) : TaskNode(tree, nodeParent) {
}

GetFurnitures::~GetFurnitures() {
}

void GetFurnitures::BeginExecute() {
	MerchantBlackBoard* _blackBoard = static_cast<MerchantBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		day = _blackBoard->day;
		merchant = _blackBoard->merchant;
		merchandise = merchant->GetMerchandise();
	}
}

void GetFurnitures::Tick(float dt) {
	TaskNode::Tick(dt);
	if (day->m_phase == DayPhase::Morning) {
		merchant->GetFurnitures(10);
	}
	EndExecute();
}

void GetFurnitures::EndExecute() {
	if (day->m_phase == DayPhase::Morning && merchandise < merchant->GetMerchandise()) {
		parent->OnChildEnd(ENodeState::Success);
	}
	else {
		parent->OnChildEnd(ENodeState::Failure);
	}
}
