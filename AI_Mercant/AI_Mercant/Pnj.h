#pragma once
#define AI_TYPE 2
#define COSTUMERS 0
#define MERCHANT 1
#define MERCHANT_NUMBERS 6
#define SALER 0
#define BAKER 1
#define BUTCHER 2
#define WAITER 3
#define PHARMACIST 4
#define HAIRDRESSERS 5


#include <vector>
class RootNode;
class Node;

class Pnj {
	RootNode* PnjRoot;
	Node* AI;
protected:
	std::vector<Node*> pnjType;
	FluxNode* AIType;
public:
	Pnj();
	virtual ~Pnj();
};

class Costumer : protected Pnj {
protected:
public:
	Costumer() = default;
	virtual ~Costumer() {};
};

class Merchant : private Pnj {
	std::vector<Node*> nodes;
protected:
	int cash;
	FluxNode* states;
public:
	Merchant();
	virtual ~Merchant() {};
};

class Baker : protected Merchant { //TODO: finir arbre
protected:
	int bread;
	FluxNode* merchantType;
public:
	Baker();
	virtual ~Baker() {};
};

class Butcher : protected Merchant {
protected:
	int meat;
public:
	Butcher() = default;
	virtual ~Butcher() {};
};