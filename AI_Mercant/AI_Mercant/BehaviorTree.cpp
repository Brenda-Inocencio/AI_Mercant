#include "BehaviorTree.h"
#include <iostream>

RootNode::RootNode(Node* _childNode) {
    childNode = _childNode;
}

RootNode::~RootNode() {
    if (childNode) {
        delete childNode;
        childNode = nullptr;
    }
}

void RootNode::Tick(float dt) {
    if (childNode != nullptr) {
        childNode->Tick(dt);
    }
}

FluxNode::FluxNode(Node* _parentNode, std::vector<Node*> _childNodes) {
    parentNode = _parentNode;
    childNodes = _childNodes;
}

FluxNode::~FluxNode() {
    for (int i = 0; i < childNodes.size(); i++) {
        if (childNodes[i]) {
            delete childNodes[i];
            childNodes[i] = nullptr;
        }
    }
    if (parentNode) {
        delete parentNode;
        parentNode = nullptr;
    }
    if (actualNode) {
        delete actualNode;
        actualNode = nullptr;
    }
}

void FluxNode:: Tick(float DeltaTime) {
    if (actualNode == nullptr) {
        actualNode = childNodes.front();
        actualNode->Begin();
    }
    actualNode->Tick(DeltaTime);
}

void FluxNode::OnNodeEnd() {
    auto It = std::find(childNodes.begin(), childNodes.end(), actualNode);
    if (It != childNodes.end()) {
        int Index = std::distance(childNodes.begin(), It);
        if (Index < childNodes.size() - 1) {
            Index++;
        }
        else {
            Index = 0;
        }
        actualNode = childNodes[Index];
        actualNode->Begin();
    }
}

TaskNode::TaskNode(FluxNode* _parentNode) {
    parentNode = _parentNode;
}

TaskNode::~TaskNode() {
    if (parentNode) {
        delete parentNode;
        parentNode = nullptr;
    }
}

void TaskNode::Begin() {
    actualTime = _time;
}

void TaskNode::Tick(float dt) {
    actualTime = actualTime - dt;
    if (actualTime <= 0.0f) {
        parentNode->OnNodeEnd();
    }
    else {
        std::cout << actualTime << std::endl;
    }
}