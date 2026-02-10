#pragma once
#include <vector>
#include "Pnj.h"

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
	Merchant* merchant;
	Customer* customer;
};

class CustomerBlackBoard: public Blackboard{
public:
	Customer* customer;
	Merchant* merchant;
};

class MerchantBehaviorTree : public BehaviorTree {
public:
	MerchantBehaviorTree();
	MerchantBehaviorTree(Blackboard* BB);
	virtual ~MerchantBehaviorTree();

	virtual void BuildTree() override;
};

class CustomerBehaviorTree: public BehaviorTree{
public:
	CustomerBehaviorTree();
	CustomerBehaviorTree(Blackboard* BB);
	virtual ~CustomerBehaviorTree();

	virtual void BuildTree() override;
};
