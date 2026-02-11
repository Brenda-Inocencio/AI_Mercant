#include "BehaviorTree.h"

#include "FallBack.h"
#include "Node.h"
#include "Sequence.h"
#include "SellTask.h"
#include "GetCashTask.h"
#include "SpendCashTask.h"
#include "BuyFurnituresTask.h"
#include "PauseTask.h"
#include "BuyTask.h"
#include "GiveCashTask.h"
#include "MoveToShop.h"

BehaviorTree::BehaviorTree() : BehaviorTree(nullptr) {

}

BehaviorTree::BehaviorTree(BlackBoard* BB) : internBlackBoard(BB) {

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

BlackBoard* BehaviorTree::GetBlackBoard() {
    return internBlackBoard;
}

MerchantBehaviorTree::MerchantBehaviorTree() : MerchantBehaviorTree(nullptr) {
}

MerchantBehaviorTree::MerchantBehaviorTree(BlackBoard* BB) : BehaviorTree(BB) {
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
    sequence1->AddChild(task1);

    GetCashTask* task2 = new GetCashTask(this, sequence1);
    sequence1->AddChild(task2);

    Sequence* sequence2 = new Sequence(this, fallBack1, {});
    fallBack1->AddChild(sequence2);

    SpendCashTask* task3 = new SpendCashTask(this, sequence2);
    sequence2->AddChild(task3);

    BuyFurnituresTask* task4 = new BuyFurnituresTask(this, sequence2);
    sequence2->AddChild(task4);

    PauseTask* task5 = new PauseTask(this, fallBack1);
    fallBack1->AddChild(task5);

    allSubNodes.push_back(task1);
    allSubNodes.push_back(task2);
    allSubNodes.push_back(sequence1);
    allSubNodes.push_back(task3);
    allSubNodes.push_back(task4);
    allSubNodes.push_back(sequence2);
    allSubNodes.push_back(task5);
    allSubNodes.push_back(fallBack1);
}

CustomerBehaviorTree::CustomerBehaviorTree() : CustomerBehaviorTree(nullptr) {
}

CustomerBehaviorTree::CustomerBehaviorTree(BlackBoard* BB) : BehaviorTree(BB) {
}

CustomerBehaviorTree::~CustomerBehaviorTree() {
}

void CustomerBehaviorTree::BuildTree() {
    BehaviorTree::BuildTree();

    FallBack* fallBack1 = new FallBack(this, nullptr, {});
    root->child = fallBack1;

    Sequence* sequence1 = new Sequence(this, fallBack1, {});
    fallBack1->AddChild(sequence1);

    BuyTask* task1 = new BuyTask(this, sequence1);
    sequence1->AddChild(task1);

    GiveCashTask* task2 = new GiveCashTask(this, sequence1);
    sequence1->AddChild(task2);

    MoveToShop* task3 = new MoveToShop(this, fallBack1);
    fallBack1->AddChild(task3);

    allSubNodes.push_back(task1);
    allSubNodes.push_back(task2);
    allSubNodes.push_back(sequence1);
    allSubNodes.push_back(task3);
    allSubNodes.push_back(fallBack1);
}
