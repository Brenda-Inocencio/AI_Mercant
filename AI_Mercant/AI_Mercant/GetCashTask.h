#pragma once
#include "TaskNode.h"
#include "Pnj.h"

class GetCashTask : public TaskNode {
	float cash;
	Merchant* merchant;
public:
	GetCashTask();
	GetCashTask(BehaviorTree* tree, FlowNode* nodeParent);
	~GetCashTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

