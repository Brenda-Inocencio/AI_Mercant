#pragma once
#include "TaskNode.h"
#include <vector>

class Customer;
class Merchant;
class Shop;

class GiveCashTask : public TaskNode {
	float cash;
	Customer* customer;
	Merchant* merchant;
	std::vector<Shop*> shops;
public:
	GiveCashTask();
	GiveCashTask(BehaviorTree* tree, FlowNode* nodeParent);
	~GiveCashTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

