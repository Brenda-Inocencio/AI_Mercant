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
	pnjType.clear();
}

Merchant::Merchant() {
	merchantType.clear();
	for (int i = 0; i < MERCHANT_NUMBERS; i++) {
		merchantType.push_back(new Node);
	}
	merchants = new FluxNode(pnjType[MERCHANT], merchantType);
}

Merchant::~Merchant() {
	for (int i = 0; i < merchantType.size(); i++) {
		if (merchantType[i]) {
			delete merchantType[i];
			merchantType[i] = nullptr;
		}
	}
	merchantType.clear();
	if (merchants) {
		delete merchants; 
		merchants = nullptr;
	}
}

Saler::Saler() {
	stateType.clear();
	for (int i = 0; i < STATES; i++) {
		stateType.push_back(new Node);
	}
	states = new FluxNode(merchantType[SALER], stateType);
}

Saler::~Saler() {
	for (int i = 0; i < stateType.size(); i++) {
		if (stateType[i]) {
			delete stateType[i];
			stateType[i] = nullptr;
		}
	}
	stateType.clear();
	if (states) {
		delete states;
		states = nullptr;
	}
}

Baker::Baker() {
	stateType.clear();
	for (int i = 0; i < STATES; i++) {
		stateType.push_back(new Node);
	}
	states = new FluxNode(merchantType[BAKER], stateType);
}

Baker::~Baker() {
	for (int i = 0; i < stateType.size(); i++) {
		if (stateType[i]) {
			delete stateType[i];
			stateType[i] = nullptr;
		}
	}
	stateType.clear();
	if (states) {
		delete states;
		states = nullptr;
	}
}

Butcher::Butcher() {
	stateType.clear();
	for (int i = 0; i < STATES; i++) {
		stateType.push_back(new Node);
	}
	states = new FluxNode(merchantType[BUTCHER], stateType);
}

Butcher::~Butcher() {
	for (int i = 0; i < stateType.size(); i++) {
		if (stateType[i]) {
			delete stateType[i];
			stateType[i] = nullptr;
		}
	}
	stateType.clear();
	if (states) {
		delete states;
		states = nullptr;
	}
}

Waiter::Waiter() {
	stateType.clear();
	for (int i = 0; i < STATES; i++) {
		stateType.push_back(new Node);
	}
	states = new FluxNode(merchantType[WAITER], stateType);
}

Waiter::~Waiter() {
	for (int i = 0; i < stateType.size(); i++) {
		if (stateType[i]) {
			delete stateType[i];
			stateType[i] = nullptr;
		}
	}
	stateType.clear();
	if (states) {
		delete states;
		states = nullptr;
	}
}

Hairdressers::Hairdressers() {
	stateType.clear();
	for (int i = 0; i < STATES; i++) {
		stateType.push_back(new Node);
	}
	states = new FluxNode(merchantType[HAIRDRESSERS], stateType);
}

Hairdressers::~Hairdressers() {
	for (int i = 0; i < stateType.size(); i++) {
		if (stateType[i]) {
			delete stateType[i];
			stateType[i] = nullptr;
		}
	}
	stateType.clear();
	if (states) {
		delete states;
		states = nullptr;
	}
}
