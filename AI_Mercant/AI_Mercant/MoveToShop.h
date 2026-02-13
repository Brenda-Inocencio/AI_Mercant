#pragma once
#include "TaskNode.h"
#include <vector>

class Shop;
class Merchant;
class Customer;

class MoveToShop : public TaskNode {
	std::vector<Shop*> shops;
	int shop;
	bool chooseShop;
	Customer* customer;
	Merchant* merchant;
public:
	MoveToShop();
	MoveToShop(BehaviorTree* tree, FlowNode* nodeParent);
	~MoveToShop() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

