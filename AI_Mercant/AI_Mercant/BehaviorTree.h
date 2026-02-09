#pragma once
#include <vector>

class RootNode;
class BaseNode;

class Blackboard {
public:

};

class BehaviorTree {
public:
	BehaviorTree();
	BehaviorTree(Blackboard* BB);
	virtual ~BehaviorTree();

	void BeginExecute();
	void Tick(float DeltaTime);

	virtual void BuildTree();
	void CleanTree();

	Blackboard* GetBlackBoard();
protected:
	Blackboard* internBlackBoard;
	RootNode* root;
	std::vector<BaseNode*> allSubNodes;
};

class MerchantBlackBoard : public Blackboard {
public:
	float cash;
	float price;
	float furnituresPrice;
	int furnitures;
};

class MerchantBehaviorTree : public BehaviorTree {
public:
	MerchantBehaviorTree();
	MerchantBehaviorTree(Blackboard* BB);
	virtual ~MerchantBehaviorTree();

	virtual void BuildTree() override;
};

class CostumerBehaviorTree: public BehaviorTree{
public:
	CostumerBehaviorTree();
	CostumerBehaviorTree(Blackboard* BB);
	virtual ~CostumerBehaviorTree();

	virtual void BuildTree() override;
};
