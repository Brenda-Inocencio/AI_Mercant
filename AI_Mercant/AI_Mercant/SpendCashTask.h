#pragma once
#include "TaskNode.h"

class Merchant;
class GameDay;

class SpendCashTask : public TaskNode {
	float cash;
	Merchant* merchant;
	GameDay* day;
public:
	SpendCashTask();
	SpendCashTask(BehaviorTree* tree, FlowNode* nodeParent);
	~SpendCashTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

