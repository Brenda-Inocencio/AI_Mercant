#pragma once

#include "FlowNode.h"

class FallBack : public FlowNode {
public:
	FallBack();
	FallBack(BehaviorTree* tree, FlowNode* nodeParent, const std::vector<Node*>& nodeChilds);
	virtual ~FallBack() override;

	virtual void OnChildEnd(ENodeState childResult) override;
};

