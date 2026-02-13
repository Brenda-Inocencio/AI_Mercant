#pragma once
#include "TaskNode.h"

class Merchant;
class GameDay;

class BuyFurnituresTask : public TaskNode {
	Merchant* merchant;
	GameDay* day;
public:
	BuyFurnituresTask();
	BuyFurnituresTask(BehaviorTree* tree, FlowNode* nodeParent);
	~BuyFurnituresTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

