#pragma once
#include "TaskNode.h"
#include "Pnj.h"

class GiveCashTask : public TaskNode {
	float cash;
	Customer* customer;
	Merchant* merchant;
public:
	GiveCashTask();
	GiveCashTask(BehaviorTree* tree, FlowNode* nodeParent);
	~GiveCashTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

