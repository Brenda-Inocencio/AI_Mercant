#pragma once
#include <vector>

class Node {
public:
    Node() = default;
    virtual ~Node() {};

    virtual void Tick(float dt) {};
    virtual void Begin() {}
};

class RootNode : public Node {
public:
    Node* childNode;
public:
    RootNode(Node* _childNode);
    virtual ~RootNode();

    void Tick(float dt) override;
};

class FluxNode : public Node {
public:
    std::vector<Node*> childNodes;
    Node* parentNode;
    Node* actualNode = nullptr;
public:
    FluxNode(Node* _parentNode, std::vector<Node*> _childNodes);
    virtual ~FluxNode();

    void Tick(float dt) override;
    virtual void OnNodeEnd();
};

class TaskNode : public Node {
public:
    FluxNode* parentNode;
    float actualTime;
    float _time;
public:
    TaskNode(FluxNode* _parentNode);
    virtual ~TaskNode();

    void Begin() override;
    void Tick(float dt) override;
};