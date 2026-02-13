#pragma once
#include <SFML/Graphics.hpp>
#include "Training.h"
#include <vector>

#define SPEED 40

class MerchantBlackBoard;
class CustomerBlackBoard;
class BehaviorTree;
class Shop;
class Customer;
class GameDay;

class Pnj {
public:
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
	MerchantBlackBoard* blackBoard;
public:
	bool canSell;
	bool client;
	bool canBuy;
public:
	Merchant();
	Merchant(GameDay* day);
	virtual ~Merchant();
	virtual void Sell();
	virtual void SellMerchandise();
	virtual void Cash();
	virtual void Order(int newFurnitures);
	virtual void SpendCash(int buyMerchandise);
	virtual void GetFurnitures(int buyMerchandise);
	virtual void UpdatePrice(int newPrice);
	inline virtual float GetPrice() { return price; }
	inline virtual float GetCash() { return cash; }
	inline virtual int GetMerchandise() { return merchandise; }
};

class Saler : public Merchant { 
protected:
public:
	Saler(GameDay* day);
	virtual ~Saler();
};

class Baker : public Merchant {
protected:
public:
	Baker(GameDay* day);
	virtual ~Baker();
};

class Butcher : public Merchant {
protected:
public:
	Butcher(GameDay* day);
	virtual ~Butcher();
};

class Waiter : public Merchant {
protected:
public:
	Waiter(GameDay* day);
	virtual ~Waiter();
};

class Pharmacist : public Merchant {
protected:
public:
	Pharmacist(GameDay* day);
	virtual ~Pharmacist();
};

class Hairdressers : public Merchant {
protected:
public:
	Hairdressers(GameDay* day);
	virtual ~Hairdressers();
};


class Customer : public Pnj {
protected:
	CustomerBlackBoard* blackBoard;
	sf::Texture* texture;
	sf::Sprite* sprite;
	sf::Vector2f pos;
	sf::Vector2f dest;
	float width;
	float height;

	sf::Vector2f SetPos(int position);
public:
	bool inShop;
	bool exit;

	Customer();
	Customer(int position, const std::vector<Shop*>& shops);
	virtual ~Customer();
	void Buy(Merchant* merchant);
	void MoveToShop(Shop* shop, float dt);
	void MoveToExit(int posistion, float dt);
	void Render(sf::RenderWindow& window); 
	inline float GetPosX() { return pos.x; }
	inline float GetRightX() { return pos.x + width; }
	inline float GetPosY() { return pos.y; }
	inline float GetBottomY() { return pos.y + height; }
};
