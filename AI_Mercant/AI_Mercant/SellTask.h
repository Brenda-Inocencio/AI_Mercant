#pragma once
#include "TaskNode.h"

class SellTask : public TaskNode {
	float cash;
	float price;
	int furnitures;
public:
	SellTask();
	SellTask(BehaviorTree* tree, FlowNode* nodeParent);
	~SellTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

