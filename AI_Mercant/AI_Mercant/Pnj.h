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
class Pnj {
protected:
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
public:
	Costumer();
	virtual ~Costumer() {};
	void buy(Merchant* merchant, int sales);
};
