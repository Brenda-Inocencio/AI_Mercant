#pragma once
#include "TaskNode.h"
#include "Pnj.h"

class BuyFurnituresTask : public TaskNode {
	int merchandise;
	int furnitures;
	Merchant* merchant;
public:
	BuyFurnituresTask();
	BuyFurnituresTask(BehaviorTree* tree, FlowNode* nodeParent, Merchant* _merchant);
	~BuyFurnituresTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

