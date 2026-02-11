#include "Pnj.h"
#include "Shop.h"
#include "BehaviorTree.h"

Pnj::Pnj() {
}

Pnj::~Pnj() {
	if (blackBoard) {
		delete blackBoard;
		blackBoard = nullptr;
	}
	if (behaviorTree) {
		delete behaviorTree;
		behaviorTree = nullptr;
	}
}


sf::Vector2f Customer::SetPos(int position) {
	switch (position) {
	case 0:
		return sf::Vector2f(400.f, -20.f);
		break;
	case 1:
		return sf::Vector2f(0.f, 250.f);
		break;
	case 2:
		return sf::Vector2f(800.f, 250.f);
		break;
	case 3:
		return sf::Vector2f(400.f, 520.f);
		break;
	default:
		break;
	}
}

//Customers
Customer::Customer() : Customer(0) {
}

Customer::Customer(int position) : cash(100), canBuy(false), inShop(false), width(12), height(24) { // cash en aleatoire?
	//pos : 0 -> Top; 1 -> Left; 2 -> Right; 3 -> Bottom
	blackBoard = new CustomerBlackBoard();
	behaviorTree = new CustomerBehaviorTree(blackBoard);
	behaviorTree->BuildTree();
	pos = SetPos(position);
	

	texture = new sf::Texture("Gars1.png");
	sprite = new sf::Sprite(*texture);
	sprite->setPosition(pos);
	sprite->setScale(sf::Vector2(2.f, 2.f));
}

Customer::~Customer() {
	if (texture) {
		delete texture;
		texture = nullptr;
	}
	if (sprite) {
		delete sprite;
		sprite = nullptr;
	}
}

void Customer::Buy(Merchant* merchant, int sales) {
	if (cash - merchant->GetPrice() * sales >= 0) {
		canBuy = true;
	}
}

void Customer::SpendCash(Merchant* merchant, int sales) {
	if (cash - merchant->GetPrice() * sales >= 0) {
		cash -= merchant->GetPrice() * sales;
	}
}

void Customer::MoveTo(Shop* shop, float dt) { // risque erreur de link
	if (!inShop) {
		if (pos != shop->GetPosition()) {
			if (pos.x + width > shop->GetRightX()) {
				pos.x -= SPEED * dt;
				if (pos.x < shop->GetPosX()) {
					pos.x = shop->GetPosX();
				}
			}
			else if (pos.x < shop->GetPosX()) {
				pos.x += SPEED * dt;
				if (pos.x + width > shop->GetRightX()) {
					pos.x = shop->GetRightX();
				}
			}
			if (pos.y + height > shop->GetBottomY()) {
				pos.y -= SPEED * dt;
				if (pos.y < shop->GetPosY()) {
					pos.y = shop->GetPosY();
				}
			}
			else if (pos.y < shop->GetPosY()) {
				pos.y += SPEED * dt;
				if (pos.y > shop->GetBottomY()) {
					pos.y = shop->GetBottomY();
				}
			}
		}
		if (pos.x >= shop->GetPosX() && pos.x + width <= shop->GetRightX() &&
			pos.y >= shop->GetPosY() && pos.y + height <= shop->GetBottomY()) {
			inShop = true;
		}
	}
}

void Customer::Render(sf::RenderWindow& window) {
	window.draw(*sprite);
}


//Merchants
Merchant::Merchant() : cash(1000), price(3), merchandise(0), salesNumber(0), canBuy(false), canSell(false) { // price varible determiner par apprentissage
	blackBoard = new MerchantBlackBoard();
	behaviorTree = new MerchantBehaviorTree(blackBoard);
	behaviorTree->BuildTree();
	Price = nullptr;
}

Merchant::~Merchant() {
	if (Price) {
		delete Price;
		Price = nullptr;
	}
}

void Merchant::Sell(int sales) {
	if (merchandise - sales >= 0) {
		merchandise -= sales;
		salesNumber += sales;
		canSell = true;
	}
	else if (merchandise <= 0) {
		canSell = false;
	}
}

void Merchant::Cash(int sellMerchandise) {
	cash += sellMerchandise * price;
}

void Merchant::Order(int newFurnitures) {
	if (cash - newFurnitures * price >= 0) {
		cash -= newFurnitures * price;
		canBuy = true;
	}
	else {
		canBuy = false;
	}
}

void Merchant::SpendCash(int buyMerchandise) {
	if (cash - buyMerchandise * price >= 0) {
		cash -= buyMerchandise * price;
		merchandise += buyMerchandise;
	}
}

void Merchant::UpdatePrice(int newPrice) {
Price: (new Training())->updateLeaning();
}


Saler::Saler() {
}
Saler::~Saler() {
}


Baker::Baker() {
}
Baker::~Baker() {
}


Butcher::Butcher() {
}
Butcher::~Butcher() {
}


Waiter::Waiter() {
}
Waiter::~Waiter() {
}


Pharmacist::Pharmacist() {
}
Pharmacist::~Pharmacist() {
}


Hairdressers::Hairdressers() {
}
Hairdressers::~Hairdressers() {
}

