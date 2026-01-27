#pragma once
#define MERCHANT_STATES 3

class RootNode;
class Node;

class Pnj {
protected:
	RootNode* PnjRoot;
	Node* AIState;
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

class Mercant : private Pnj {
protected:
	int cash;
	std::vector <Node*> nodes;
	FluxNode* states;
public:
	Mercant();
	virtual ~Mercant() {};
};

class Baker : protected Mercant {
protected:
	int bread;
public:
	Baker() = default;
	virtual ~Baker() {};
};

class Butcher : protected Mercant {
protected:
	int meat;
public:
	Butcher() = default;
	virtual ~Butcher() {};
};