#pragma once
class Blackboard;
class FlowNode;
class BehaviorTree;

enum class ENodeState {
	Unknow = 0,
	Success = 1,
	Failure = 2,
};


class BaseNode {
public:
	BaseNode();
	BaseNode(BehaviorTree* tree);
	virtual ~BaseNode();

	virtual void BeginExecute();
	virtual void Tick(float dt);
	virtual void EndExecute();


	Blackboard* GetBlackBoard();
	BehaviorTree* GetBehaviorTree();
protected:
	BehaviorTree* ownerTree;
};


class Node : public BaseNode {
public:
	Node();
	Node(BehaviorTree* tree, FlowNode* nodeParent);
	virtual ~Node() override;


protected:
	FlowNode* parent;
};


class RootNode : public BaseNode {
public:
	RootNode();
	RootNode(BehaviorTree* tree, BaseNode* nodeChild);
	virtual ~RootNode() override;

	void BeginExecute() override;
	void Tick(float dt) override;

	BaseNode* child;
};


