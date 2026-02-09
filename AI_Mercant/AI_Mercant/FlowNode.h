#pragma once
#include <vector>

#include "Node.h"

class FlowNode : public Node {
public:
	FlowNode();
	FlowNode(BehaviorTree* tree, FlowNode* nodeParent, const std::vector<Node*>& nodeChilds);
	virtual ~FlowNode() override;

	virtual void OnChildEnd(ENodeState childResult);

	virtual void BeginExecute() override;
	virtual void Tick(float dt) override;

	void AddChild(Node* child);

protected:
	std::vector<Node*> childs;
	Node* currentExecuteChild;
};

