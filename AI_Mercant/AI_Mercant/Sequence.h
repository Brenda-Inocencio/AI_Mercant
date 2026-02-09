#pragma once
#include <vector>

#include "FlowNode.h"

class Sequence : public FlowNode {
public:
	Sequence();
	Sequence(BehaviorTree* tree, FlowNode* nodeParent, const std::vector<Node*>& nodeChilds);
	virtual ~Sequence() override;

	virtual void OnChildEnd(ENodeState childResult) override;
};

