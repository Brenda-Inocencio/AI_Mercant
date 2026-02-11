#include "MoveToShop.h"
#include <valarray>
#include "BehaviorTree.h"
#include "FlowNode.h"
#include "shop.h"

MoveToShop::MoveToShop() : MoveToShop(nullptr, nullptr){ 
}

MoveToShop::MoveToShop(BehaviorTree* tree, FlowNode* nodeParent) : TaskNode(tree, nodeParent), shop(0) {//variable aleatoire
}

MoveToShop::~MoveToShop() {
}

void MoveToShop::BeginExecute() {
	CustomerBlackBoard* _blackBoard = static_cast<CustomerBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		shops = _blackBoard->shops;
	}
}

void MoveToShop::Tick(float dt) {
	TaskNode::Tick(dt);
	if (!customer->inShop) {
		customer->MoveTo(shops[shop], dt);  
	}
	EndExecute();
}

void MoveToShop::EndExecute() {
	if (customer->inShop) {
		parent->OnChildEnd(ENodeState::Success);
	}
	else {
		parent->OnChildEnd(ENodeState::Failure);
	}
}
