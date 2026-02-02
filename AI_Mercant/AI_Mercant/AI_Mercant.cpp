#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

class Node {
public:
    Node() = default;
    virtual ~Node() {};

    virtual void Tick(float DeltaTime) {};
    virtual void Begin() {}
};

class RootNode : public Node {
public:
    RootNode() = default;
    virtual ~RootNode() {};

    void Tick(float DeltaTime) override {
        if (ChildNode != nullptr)
        {
            ChildNode->Tick(DeltaTime);
        }
    }
public:
    Node* ChildNode;
};

class FluxNode : public Node {
public:
    FluxNode() = default;
    virtual ~FluxNode() {};

    void Tick(float DeltaTime) override
    {
        if (ActualNode == nullptr) {
            ActualNode = ChildNodes.front();
            ActualNode->Begin();
        }
        ActualNode->Tick(DeltaTime);
    }   
    virtual void OnNodeEnd() {
        auto It = std::find(ChildNodes.begin(), ChildNodes.end(), ActualNode);
        if (It != ChildNodes.end()) {
            int Index = std::distance(ChildNodes.begin(), It);
            if (Index < ChildNodes.size() - 1) {
                Index++;
            }
            else {
                Index = 0;
            }
            ActualNode = ChildNodes[Index];
            ActualNode->Begin();
        }
    }
public:
    std::vector<Node*> ChildNodes;
    Node* ActualNode = nullptr;
};

class TaskNode : public Node {
public:
    TaskNode() = default;
    virtual ~TaskNode() {};
    void Begin() override {
        ActualTime = Time;
    }
    void Tick(float DeltaTime) override {
        ActualTime = ActualTime - DeltaTime;
        if (ActualTime <= 0.0f) {
            ParentNode->OnNodeEnd();
        }
        else {
            std::cout << ActualTime << std::endl;
        }
    }
public:
    FluxNode* ParentNode;
    float ActualTime;
    float Time;
};

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");

    // Load a sprite to display
    const sf::Texture texture("block.png");
    sf::Sprite sprite(texture);

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        while (const auto event = window.pollEvent()) {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Update the window
        window.display();
    }
}