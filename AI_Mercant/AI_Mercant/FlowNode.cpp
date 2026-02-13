#include "FlowNode.h"

FlowNode::FlowNode() : FlowNode(nullptr, nullptr, {}) {
}

FlowNode::FlowNode(BehaviorTree* tree, FlowNode* nodeParent, const std::vector<Node*>& nodeChilds) : Node(tree, nodeParent), childs(nodeChilds) {
}

FlowNode::~FlowNode() {
}

void FlowNode::OnChildEnd(ENodeState childResult) {
	auto It = std::find(childs.begin(), childs.end(), currentExecuteChild);
	if (It != childs.end()) {
		int Index = std::distance(childs.begin(), It) + 1;
		if (Index < childs.size()) {
			currentExecuteChild = childs[Index];
		}
		else {
			currentExecuteChild = nullptr;
		}
	}
}

void FlowNode::BeginExecute() {
	currentExecuteChild = *childs.begin();
	if (currentExecuteChild != nullptr) {
		currentExecuteChild->BeginExecute();
	}
}

void FlowNode::Tick(float dt) {
	currentExecuteChild->Tick(dt);
	Node::Tick(dt);
}

void FlowNode::AddChild(Node* child) {
	childs.push_back(child);
}
