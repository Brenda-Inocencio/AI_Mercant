#include "MoveToExit.h"
#include <valarray>
#include <random>
#include <iostream>
#include "BehaviorTree.h"
#include "FlowNode.h"
#include "Pnj.h"

MoveToExit::MoveToExit() : MoveToExit(nullptr, nullptr) {
}

MoveToExit::MoveToExit(BehaviorTree* tree, FlowNode* nodeParent) : TaskNode(tree, nodeParent), chooseDest(false) {//variable aleatoire
}

MoveToExit::~MoveToExit() {
}

void MoveToExit::BeginExecute() {
	CustomerBlackBoard* _blackBoard = static_cast<CustomerBlackBoard*>(GetBlackBoard());
	if (_blackBoard != nullptr) {
		customer = _blackBoard->customer;
	}
	if (!chooseDest) {
		std::random_device m_rd;
		std::mt19937 m_gen(m_rd());

		std::uniform_int_distribution<int> dis(0, 3);
		dest = dis(m_gen);
		chooseDest = true;
	}
}

void MoveToExit::Tick(float dt) {
	TaskNode::Tick(dt);

	if (!customer->exit) {
		customer->MoveToExit(dest, dt);
		return;
	}
	EndExecute();
}

void MoveToExit::EndExecute() {
	if (customer->exit) {
		parent->OnChildEnd(ENodeState::Success);
	}
	else {
		parent->OnChildEnd(ENodeState::Failure);
	}
}
