#pragma once
#include "TaskNode.h"
#include <vector>

class Customer;
class Merchant;
class Shop;

class BuyTask : public TaskNode {
	Customer* customer;
	Merchant* merchant;
	std::vector<Shop*> shops;
public:
	BuyTask();
	BuyTask(BehaviorTree* tree, FlowNode* nodeParent);
	~BuyTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

