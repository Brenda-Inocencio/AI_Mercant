#pragma once
#include "TaskNode.h"

class PauseTask : public TaskNode {
public:
	PauseTask();
	PauseTask(BehaviorTree* tree, FlowNode* nodeParent);
	~PauseTask() override;

	void BeginExecute() override;
	void Tick(float dt) override;
	void EndExecute() override;

};

