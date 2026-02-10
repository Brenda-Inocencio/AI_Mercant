#pragma once
#include "TaskNode.h"
#include "Pnj.h"

class SpendCashTask : public TaskNode {
	float cash;
	Merchant* merchant;
public:
	SpendCashTask();
	SpendCashTask(BehaviorTree* tree, FlowNode* nodeParent, Merchant* _merchant);
	~SpendCashTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

