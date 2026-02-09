#include "BehaviorTree.h"

#include "FallBack.h"
#include "Node.h"
#include "Sequence.h"
#include "SellTask.h"
#include "GetCashTask.h"
#include "SpendCashTask.h"
#include "BuyFurnituresTask.h"
#include "PauseTask.h"

BehaviorTree::BehaviorTree() : BehaviorTree(nullptr) {

}

BehaviorTree::BehaviorTree(Blackboard* BB) : internBlackBoard(BB) {

}

BehaviorTree::~BehaviorTree() {

}

void BehaviorTree::BeginExecute() {
    root->BeginExecute();
}

void BehaviorTree::Tick(float dt) {
    root->Tick(dt);
}

void BehaviorTree::BuildTree() {
    root = new RootNode();
    allSubNodes.push_back(root);
}

void BehaviorTree::CleanTree() {
    for (auto node : allSubNodes) {
        delete node;
        node = nullptr;
    }
    allSubNodes.clear();
}

Blackboard* BehaviorTree::GetBlackBoard()
{
    return internBlackBoard;
}

MerchantBehaviorTree::MerchantBehaviorTree() : MerchantBehaviorTree(nullptr) {
}

MerchantBehaviorTree::MerchantBehaviorTree(Blackboard* BB) : BehaviorTree(BB) {
}

MerchantBehaviorTree::~MerchantBehaviorTree() {
}

void MerchantBehaviorTree::BuildTree() {
    BehaviorTree::BuildTree();

    FallBack* fallBack1 = new FallBack(this, nullptr, {});
    root->child = fallBack1;

    Sequence* sequence1 = new Sequence(this, fallBack1, {});
    fallBack1->AddChild(sequence1);

    SellTask* task1 = new SellTask(this, sequence1);

    GetCashTask* task2 = new GetCashTask(this, sequence1);

    Sequence* sequence2 = new Sequence(this, fallBack1, {});
    fallBack1->AddChild(sequence2);

    SpendCashTask* task3 = new SpendCashTask(this, sequence2);
    
    BuyFurnituresTask* task4 = new BuyFurnituresTask(this, sequence2);

    PauseTask* task5 = new PauseTask(this, fallBack1);
    
    allSubNodes.push_back(task1);
    allSubNodes.push_back(task2);
    allSubNodes.push_back(sequence1);
    allSubNodes.push_back(task3);
    allSubNodes.push_back(task4);
    allSubNodes.push_back(sequence2);
    allSubNodes.push_back(task5);
    allSubNodes.push_back(fallBack1);
}

CostumerBehaviorTree::CostumerBehaviorTree() : CostumerBehaviorTree(nullptr) {
}

CostumerBehaviorTree::CostumerBehaviorTree(Blackboard* BB) : BehaviorTree(BB) {
}

CostumerBehaviorTree::~CostumerBehaviorTree() {
}

void CostumerBehaviorTree::BuildTree() {
    BehaviorTree::BuildTree();

    FallBack* fallBack1 = new FallBack(this, nullptr, {});
    root->child = fallBack1;

    Sequence* sequence1 = new Sequence(this, fallBack1, {});
    fallBack1->AddChild(sequence1);

    //task


    //AllSubNodes.push_back(Task1);
    allSubNodes.push_back(sequence1);
    allSubNodes.push_back(fallBack1);
}
