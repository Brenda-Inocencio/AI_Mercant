#include "Node.h"

#include "BehaviorTree.h"

BaseNode::BaseNode() : BaseNode(nullptr) {
}

BaseNode::BaseNode(BehaviorTree* tree) : ownerTree(tree) {
}

BaseNode::~BaseNode() {
}

void BaseNode::BeginExecute() {
}

void BaseNode::Tick(float dt) {
}

void BaseNode::EndExecute() {
}

BlackBoard* BaseNode::GetBlackBoard() {
	return GetBehaviorTree()->GetBlackBoard();
}

BehaviorTree* BaseNode::GetBehaviorTree() {
	return ownerTree;
}

Node::Node() : Node(nullptr, nullptr) {
}

Node::Node(BehaviorTree* tree, FlowNode* nodeParent) : BaseNode(tree), parent(nodeParent) {
}

Node::~Node() {
}



RootNode::RootNode() : RootNode(nullptr, nullptr) {
}

RootNode::RootNode(BehaviorTree* tree, BaseNode* nodeChild) : BaseNode(tree), child(nodeChild) {
}

RootNode::~RootNode()
{
}

void RootNode::BeginExecute() {
	child->BeginExecute();
}

void RootNode::Tick(float dt) {
	child->Tick(dt);
}
