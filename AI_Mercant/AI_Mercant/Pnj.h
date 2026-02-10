#pragma once

#include "Training.h"
#include <vector>
#include <string>

class Pnj {
protected:
public:
	Pnj();
	virtual ~Pnj();
};


class Merchant : private Pnj {
protected:
	float cash;
	float price;
	int merchandise;
	int salesNumber;
	Training* Price;
	std::string pnj;
public:
	bool canSell;
	bool canBuy;
public:
	Merchant();
	virtual ~Merchant();
	virtual void Sell(int sales);
	virtual void Cash(int sellMerchandise);
	virtual void Order(int newFurnitures);
	virtual void SpendCash(int buyMerchandise);
	virtual void UpdatePrice(int newPrice);
	inline virtual float GetPrice() { return price; }
	inline virtual float GetCash() { return cash; }
	inline virtual int GetMerchandise() { return merchandise; }
	inline virtual std::string String() { return pnj; }
};

class Saler : public Merchant { 
protected:
public:
	Saler();
	virtual ~Saler();
};

class Baker : public Merchant {
protected:
public:
	Baker();
	virtual ~Baker();
};

class Butcher : public Merchant {
protected:
public:
	Butcher();
	virtual ~Butcher();
};

class Waiter : public Merchant {
protected:
public:
	Waiter();
	virtual ~Waiter();
};

class Pharmacist : public Merchant {
protected:
public:
	Pharmacist();
	virtual ~Pharmacist();
};

class Hairdressers : public Merchant {
protected:
public:
	Hairdressers();
	virtual ~Hairdressers();
};


class Customer : public Pnj {
protected:
	float cash;
public:
	bool canBuy;
public:
	Customer();
	virtual ~Customer() {};
	void Buy(Merchant* merchant, int sales);
	void SpendCash(Merchant* merchant, int sales);
	inline float GetCash() { return cash; }
};
