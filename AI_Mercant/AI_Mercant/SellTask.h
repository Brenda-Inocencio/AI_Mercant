#pragma once
#include "TaskNode.h"
#include "Pnj.h"

class SellTask : public TaskNode {
	Merchant* merchant;
public:
	SellTask();
	SellTask(BehaviorTree* tree, FlowNode* nodeParent);
	~SellTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

