#pragma once
#include "TaskNode.h"
#include "Pnj.h"

class SellTask : public TaskNode {
	Merchant* merchant;
public:
	SellTask();
	SellTask(BehaviorTree* tree, FlowNode* nodeParent, Merchant* _merchant);
	~SellTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

