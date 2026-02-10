#pragma once
#include "TaskNode.h"
#include "Pnj.h"

class BuyTask : public TaskNode {
	Customer* customer;
	Merchant* merchant;
public:
	BuyTask();
	BuyTask(BehaviorTree* tree, FlowNode* nodeParent, Customer* _customer);
	~BuyTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

