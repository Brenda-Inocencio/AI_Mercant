#pragma once
#include "TaskNode.h"
#include "Pnj.h"

class Shop;

class MoveToShop : public TaskNode {
	std::vector<Shop*> shops;
	int shop;
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

