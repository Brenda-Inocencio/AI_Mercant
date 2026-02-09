#include "FallBack.h"

FallBack::FallBack() : FallBack(nullptr, nullptr, {}) {
}

FallBack::FallBack(BehaviorTree* tree, FlowNode* nodeParent, const std::vector<Node*>& nodeChilds) : FlowNode(tree, nodeParent, nodeChilds) {
}

FallBack::~FallBack() {
}

void FallBack::OnChildEnd(ENodeState childResult) {
	if (childResult == ENodeState::Failure) {
		FlowNode::OnChildEnd(childResult);
		if (currentExecuteChild != nullptr) {
			currentExecuteChild->BeginExecute();
		}
		else {
			if (parent != nullptr) {
				parent->OnChildEnd(ENodeState::Success);
			}
			else {
				currentExecuteChild = *childs.begin();
				currentExecuteChild->BeginExecute();
			}
		}
	}
	else {
		if (parent != nullptr) {
			parent->OnChildEnd(ENodeState::Failure);
		}
		else {
			currentExecuteChild = *childs.begin();
			currentExecuteChild->BeginExecute();
		}
	}
}
