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
#include "MoveToShop.h"
#include "MoveToExit.h"

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

    //Morning
    Sequence* morning = new Sequence(this, fallBack1, {});
    fallBack1->AddChild(morning);

    //recup fournitures

    //Day
    FallBack* day = new FallBack(this, fallBack1, {});
    fallBack1->AddChild(day);

    Sequence* sequence1 = new Sequence(this, day, {});
    day->AddChild(sequence1);

    SellTask* sell = new SellTask(this, sequence1);
    sequence1->AddChild(sell);

    GetCashTask* getCash = new GetCashTask(this, sequence1);
    sequence1->AddChild(getCash);

    PauseTask* pause = new PauseTask(this, day);
    day->AddChild(pause);

    Sequence* evening = new Sequence(this, fallBack1, {});
    fallBack1->AddChild(evening);

    SpendCashTask* spendCash = new SpendCashTask(this, evening);
    evening->AddChild(spendCash);

    BuyFurnituresTask* buyFurnitures = new BuyFurnituresTask(this, evening);
    evening->AddChild(buyFurnitures);

    //allSubNodes.push_back(getFurnitures);
    allSubNodes.push_back(morning);
    allSubNodes.push_back(sell);
    allSubNodes.push_back(getCash);
    allSubNodes.push_back(sequence1);
    allSubNodes.push_back(pause);
    allSubNodes.push_back(day);
    allSubNodes.push_back(spendCash);
    allSubNodes.push_back(buyFurnitures);
    allSubNodes.push_back(evening);
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

    BuyTask* buy = new BuyTask(this, sequence1);
    sequence1->AddChild(buy);

    MoveToExit* moveToExit = new MoveToExit(this, sequence1);
    sequence1->AddChild(moveToExit);

    MoveToShop* moveToShop = new MoveToShop(this, fallBack1);
    fallBack1->AddChild(moveToShop);

    allSubNodes.push_back(buy);
    allSubNodes.push_back(moveToExit);
    allSubNodes.push_back(sequence1);
    allSubNodes.push_back(moveToShop);
    allSubNodes.push_back(fallBack1);
}
