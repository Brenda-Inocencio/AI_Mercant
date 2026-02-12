#include "GiveCashTask.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"
#include "Pnj.h"
#include "Shop.h"

GiveCashTask::GiveCashTask() : GiveCashTask(nullptr, nullptr) {
}

GiveCashTask::GiveCashTask(BehaviorTree* tree, FlowNode* nodeParent) : TaskNode(tree, nodeParent) {
}

GiveCashTask::~GiveCashTask() {
}

void GiveCashTask::BeginExecute() {
	CustomerBlackBoard* _blackBoard = static_cast<CustomerBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		customer = _blackBoard->customer;
		shops = _blackBoard->shops;
		cash = customer->GetCash();
		if (customer->inShop) {
			for (int i = 0; i < shops.size(); i++) {
				if (customer->GetPosX() >= shops[i]->GetPosX() && customer->GetRightX() <= shops[i]->GetRightX() &&
					customer->GetPosY() >= shops[i]->GetPosY() && customer->GetBottomY() <= shops[i]->GetBottomY()) {
					merchant = shops[i]->GetMerchant();
				}
			}
		}
	}
}

void GiveCashTask::Tick(float dt) {
	TaskNode::Tick(dt);
	if (customer->canBuy) {
		customer->SpendCash(merchant, 1);  // 1 = le nb de marchandise achetees
	}
	EndExecute();
}

void GiveCashTask::EndExecute() {
	if (customer->GetCash() < cash) {
		parent->OnChildEnd(ENodeState::Success);
	}
}
