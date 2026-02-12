#include "BuyTask.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"
#include "Pnj.h"
#include "Shop.h"

BuyTask::BuyTask() : BuyTask(nullptr, nullptr) {
}

BuyTask::BuyTask(BehaviorTree* tree, FlowNode* nodeParent) : TaskNode(tree, nodeParent) {
}

BuyTask::~BuyTask() {
}

void BuyTask::BeginExecute() {
	CustomerBlackBoard* _blackBoard = static_cast<CustomerBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		customer = _blackBoard->customer;	
		shops = _blackBoard->shops;
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

void BuyTask::Tick(float dt) {
	TaskNode::Tick(dt);
	if (customer->inShop) {
		if (customer->canBuy) {
			customer->Buy(merchant, 1); // 1 = le nb de marchandise achetees
		}
	}
	EndExecute();
}

void BuyTask::EndExecute() {
	if (customer->canBuy) {
		parent->OnChildEnd(ENodeState::Success);
	}
	else {
		parent->OnChildEnd(ENodeState::Failure);
	}
}

