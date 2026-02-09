#pragma once
#include "TaskNode.h"

class BuyFurnituresTask : public TaskNode {
	int furnitures;
	int newFurnitures;
public:
	BuyFurnituresTask();
	BuyFurnituresTask(BehaviorTree* tree, FlowNode* nodeParent);
	~BuyFurnituresTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

