#include "Pnj.h"
#include "BehaviorTree.h"

Pnj::Pnj() {
	AIState = new Node;
	PnjRoot = new RootNode(AIState);
}

Pnj::~Pnj() {
	if (PnjRoot) {
		delete PnjRoot; PnjRoot = nullptr;
	}
	if (AIState) {
		delete AIState; AIState = nullptr;
	}
}

Mercant::Mercant() {
	nodes.clear();
	for (int i = 0; i < MERCHANT_STATES; i++) {
		nodes.push_back(new Node);
	}
	states = new FluxNode(AIState, nodes);
}

Mercant::~Mercant() {
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i]) {
			delete nodes[i];
			nodes[i] = nullptr;
		}
	}
}