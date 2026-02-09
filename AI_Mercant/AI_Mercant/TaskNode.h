#pragma once
#include "Node.h"

class TaskNode : public Node {
public:
	TaskNode();
	TaskNode(BehaviorTree* tree, FlowNode* nodeParent);
	virtual ~TaskNode() override;
};

