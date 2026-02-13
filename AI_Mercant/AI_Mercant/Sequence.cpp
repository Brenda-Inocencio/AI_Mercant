#include "Sequence.h"

Sequence::Sequence() : Sequence(nullptr, nullptr, {}) {
}

Sequence::Sequence(BehaviorTree* tree, FlowNode* nodeParent, const std::vector<Node*>& nodeChilds) : FlowNode(tree, nodeParent, nodeChilds) {
}

Sequence::~Sequence() {
}

void Sequence::OnChildEnd(ENodeState childResult) {
	if (childResult == ENodeState::Success) {
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
