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
#define STATES 3
#define SELL 0
#define ORDER 1
#define PAUSE 2


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
protected:
	int cash;
	std::vector<Node*> merchantType;
	FluxNode* merchants;
public:
	Merchant();
	virtual ~Merchant() {};
};

class Saler : protected Merchant { 
protected:
	int furnitures;
	std::vector<Node*> stateType;
	FluxNode* states;
public:
	Saler();
	virtual ~Saler();
};

class Baker : protected Merchant { 
protected:
	int bread;
	std::vector<Node*> stateType;
	FluxNode* states;
public:
	Baker();
	virtual ~Baker();
};

class Butcher : protected Merchant {
protected:
	int meat;
	std::vector<Node*> stateType;
	FluxNode* states;
public:
	Butcher();
	virtual ~Butcher();
};

class Waiter : protected Merchant {
protected:
	int cofee;
	std::vector<Node*> stateType;
	FluxNode* states;
public:
	Waiter();
	virtual ~Waiter();
};

class Hairdressers : protected Merchant {
protected:
	int Hair;
	std::vector<Node*> stateType;
	FluxNode* states;
public:
	Hairdressers();
	virtual ~Hairdressers();
};