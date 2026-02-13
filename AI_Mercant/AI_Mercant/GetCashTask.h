#pragma once
#include "TaskNode.h"

class Merchant;
class GameDay;

class GetCashTask : public TaskNode {
	float cash;
	Merchant* merchant;
	GameDay* day;
public:
	GetCashTask();
	GetCashTask(BehaviorTree* tree, FlowNode* nodeParent);
	~GetCashTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

