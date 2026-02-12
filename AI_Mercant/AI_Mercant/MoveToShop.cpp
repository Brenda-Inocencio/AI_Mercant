#include "MoveToShop.h"
#include <valarray>
#include <random>
#include <iostream>
#include "BehaviorTree.h"
#include "FlowNode.h"
#include "Shop.h"

MoveToShop::MoveToShop() : MoveToShop(nullptr, nullptr){ 
}

MoveToShop::MoveToShop(BehaviorTree* tree, FlowNode* nodeParent) : TaskNode(tree, nodeParent), chooseShop(false) {//variable aleatoire
}

MoveToShop::~MoveToShop() {
}

void MoveToShop::BeginExecute() {
	CustomerBlackBoard* _blackBoard = static_cast<CustomerBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		customer = _blackBoard->customer;
		shops = _blackBoard->shops;
	}
	if (!chooseShop) {
		std::random_device m_rd;
		std::mt19937 m_gen(m_rd());

		std::uniform_int_distribution<int> dis(0, shops.size() - 1);
		shop = dis(m_gen);
		chooseShop = true;
		std::cout << shops[shop]->String() << "\n";
		std::cout << shops[shop]->GetPosX() << shops[shop]->GetPosY();
	}

}

void MoveToShop::Tick(float dt) {
	TaskNode::Tick(dt);

	if (!customer->inShop) {
		customer->MoveToShop(shops[shop], dt);
		return;
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
