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
				if (customer->GetRightX() >= shops[i]->GetPosX() && customer->GetPosX() <= shops[i]->GetRightX() &&
					customer->GetBottomY() >= shops[i]->GetPosY() && customer->GetPosY() <= shops[i]->GetBottomY()) {
					merchant = shops[i]->merchant;
				}
			}
		}
	}
}

void BuyTask::Tick(float dt) {
	TaskNode::Tick(dt);
	if (customer->inShop) {
		customer->Buy(merchant); 
	}
	EndExecute();
}

void BuyTask::EndExecute() {
	if (customer->inShop) {
		parent->OnChildEnd(ENodeState::Success);
	}
	else {
		parent->OnChildEnd(ENodeState::Failure);
	}
}

