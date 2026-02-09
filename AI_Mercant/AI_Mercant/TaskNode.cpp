#include "TaskNode.h"

TaskNode::TaskNode() : TaskNode(nullptr, nullptr) {
}

TaskNode::TaskNode(BehaviorTree* tree, FlowNode* nodeParent) : Node(tree, nodeParent) {
}

TaskNode::~TaskNode()
{
}
