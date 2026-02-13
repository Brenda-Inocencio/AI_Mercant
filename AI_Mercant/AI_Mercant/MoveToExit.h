#pragma once
#include "TaskNode.h"

class Customer;

class MoveToExit : public TaskNode {
	int dest;
	bool chooseDest;
	Customer* customer;
public:
	MoveToExit();
	MoveToExit(BehaviorTree* tree, FlowNode* nodeParent);
	~MoveToExit() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

