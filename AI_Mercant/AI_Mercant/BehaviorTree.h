#pragma once
#include <vector>
#include "Pnj.h"

class RootNode;
class BaseNode;

class BlackBoard {
public:

};

class BehaviorTree {
public:
	BehaviorTree();
	BehaviorTree(BlackBoard* BB);
	virtual ~BehaviorTree();

	void BeginExecute();
	void Tick(float DeltaTime);

	virtual void BuildTree();
	void CleanTree();

	BlackBoard* GetBlackBoard();
protected:
	BlackBoard* internBlackBoard;
	RootNode* root;
	std::vector<BaseNode*> allSubNodes;
};

class MerchantBlackBoard : public BlackBoard {
public:
	Merchant* merchant;
	Customer* customer;
};

class CustomerBlackBoard: public BlackBoard {
public:
	Customer* customer;
	std::vector<Shop*> shops;
};

class MerchantBehaviorTree : public BehaviorTree {
public:
	MerchantBehaviorTree();
	MerchantBehaviorTree(BlackBoard* BB);
	virtual ~MerchantBehaviorTree();

	virtual void BuildTree() override;
};

class CustomerBehaviorTree: public BehaviorTree{
public:
	CustomerBehaviorTree();
	CustomerBehaviorTree(BlackBoard* BB);
	virtual ~CustomerBehaviorTree();

	virtual void BuildTree() override;
};
