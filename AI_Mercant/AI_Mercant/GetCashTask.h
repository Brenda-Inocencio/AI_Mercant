#pragma once
#include "TaskNode.h"

class GetCashTask : public TaskNode {
	float newCash;
	float cash;
	float price;
public:
	GetCashTask();
	GetCashTask(BehaviorTree* tree, FlowNode* nodeParent);
	~GetCashTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

