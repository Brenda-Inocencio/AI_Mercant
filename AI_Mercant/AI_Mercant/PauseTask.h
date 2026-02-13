#pragma once
#include "TaskNode.h"

class GameDay;

class PauseTask : public TaskNode {
	GameDay* day;
public:
	PauseTask();
	PauseTask(BehaviorTree* tree, FlowNode* nodeParent);
	~PauseTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

