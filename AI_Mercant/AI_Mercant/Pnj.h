#pragma once
#define AI_TYPE 2
#define COSTUMERS 0
#define COSTUMER_TASKS 2
#define BUY 0
#define LEAVE 1
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

#include "Training.h"
#include <vector>

class RootNode;
class FluxNode;
class Node;

class Pnj {
	RootNode* pnjRoot;
	Node* AI;
protected:
	std::vector<Node*> pnjType;
	FluxNode* AIType;
public:
	Pnj();
	virtual ~Pnj();
};


class Merchant : private Pnj {
protected:
	int cash;
	int price;
	int salesNumber;
	bool noStock;
	std::vector<Node*> merchantType;
	FluxNode* merchants;
	Training* Price;
public:
	Merchant();
	virtual ~Merchant();
	virtual void Sell(int sales) {};
	virtual void Order(int newFurnitures) {};
	virtual void UpdatePrice(int newPrice) {};
	inline virtual int GetPrice() { return price; }
};

class Saler : protected Merchant { 
protected:
	int furnitures;
	std::vector<Node*> stateType;
	FluxNode* states;
public:
	Saler();
	virtual ~Saler();
	void Sell(int sales) override;
	void Order(int newFurnitures) override;
	void UpdatePrice(float newPrice);
};

class Baker : protected Merchant { 
protected:
	int breads;
	std::vector<Node*> stateType;
	FluxNode* states;
public:
	Baker();
	virtual ~Baker();
	void Sell(int sales) override;
	void Order(int newFurnitures) override;
	void UpdatePrice(int newPrice) override;
};

class Butcher : protected Merchant {
protected:
	int meats;
	std::vector<Node*> stateType;
	FluxNode* states;
public:
	Butcher();
	virtual ~Butcher();
	void Sell(int sales) override;
	void Order(int newFurnitures) override;
	void UpdatePrice(int newPrice) override;
};

class Waiter : protected Merchant {
protected:
	int coffees;
	std::vector<Node*> stateType;
	FluxNode* states;
public:
	Waiter();
	virtual ~Waiter();
	void Sell(int sales) override;
	void Order(int newFurnitures) override;
	void UpdatePrice(int newPrice) override;
};

class Hairdressers : protected Merchant {
protected:
	int hair;
	std::vector<Node*> stateType;
	FluxNode* states;
public:
	Hairdressers();
	virtual ~Hairdressers();
	void Sell(int sales) override;
	void Order(int newFurnitures) override;
	void UpdatePrice(int newPrice) override;
};


class Costumer : protected Pnj {
protected:
	int cash;
	FluxNode* costumers;
	std::vector<Node*> tasks;
public:
	Costumer();
	virtual ~Costumer() {};
	void buy(Merchant* merchant, int sales);
};
