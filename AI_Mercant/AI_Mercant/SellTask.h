#pragma once
#include "TaskNode.h"

class Merchant;
class GameDay;

class SellTask : public TaskNode {
	Merchant* merchant;
	GameDay* day;
	int merchandise;
public:
	SellTask();
	SellTask(BehaviorTree* tree, FlowNode* nodeParent);
	~SellTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

