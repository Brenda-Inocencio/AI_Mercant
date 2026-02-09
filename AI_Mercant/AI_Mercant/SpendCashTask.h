#pragma once
#include "TaskNode.h"

class SpendCashTask : public TaskNode {
	float newCash;
	float cash;
	float price;
public:
	SpendCashTask();
	SpendCashTask(BehaviorTree* tree, FlowNode* nodeParent);
	~SpendCashTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

