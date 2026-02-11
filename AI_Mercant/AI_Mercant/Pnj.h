#pragma once
#include <SFML/Graphics.hpp>
#include "Training.h"
#include <vector>
#include <string>

#define SPEED 40

class BlackBoard;
class BehaviorTree;
class Shop;

class Pnj {
protected:
public:
	BlackBoard* blackBoard;
	BehaviorTree* behaviorTree;

	Pnj();
	virtual ~Pnj();
};


class Merchant : public Pnj {
protected:
	float cash;
	float price;
	int merchandise;
	int salesNumber;
	Training* Price;
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
	sf::Texture* texture;
	sf::Sprite* sprite;
	sf::Vector2f pos;
	float width;
	float height;
	float cash;

	sf::Vector2f SetPos(int position);
public:
	bool canBuy;
	bool inShop;

	Customer();
	Customer(int position); 
	virtual ~Customer();
	void Buy(Merchant* merchant, int sales);
	void SpendCash(Merchant* merchant, int sales);
	void MoveTo(Shop* shop, float dt);
	void Render(sf::RenderWindow& window);
	inline float GetCash() { return cash; }
};
