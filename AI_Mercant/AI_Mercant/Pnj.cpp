#include "Pnj.h"
#include "BehaviorTree.h"

Pnj::Pnj() {
	AI = new Node();
	PnjRoot = new RootNode(AI);
	pnjType.clear();
	for (int i = 0; i < AI_TYPE; i++) {
		pnjType.push_back(new Node);
	}
	AIType = new FluxNode(AI, pnjType);
}

Pnj::~Pnj() {
	if (PnjRoot) {
		delete PnjRoot; PnjRoot = nullptr;
	}
	if (AI) {
		delete AI; AI = nullptr;
	}
	for (int i = 0; i < pnjType.size(); i++) {
		if (pnjType[i]) {
			delete pnjType[i];
			pnjType[i] = nullptr;
		}
	}
}

Merchant::Merchant() {
	nodes.clear();
	for (int i = 0; i < MERCHANT_STATES; i++) {
		nodes.push_back(new Node);
	}
	states = new FluxNode(pnjType[MERCHANT], nodes);
}

Merchant::~Merchant() {
	for (int i = 0; i < nodes.size(); i++) {
		if (nodes[i]) {
			delete nodes[i];
			nodes[i] = nullptr;
		}
	}
}

Baker::Baker() {

}
