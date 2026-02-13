#include "Pnj.h"
#include "Shop.h"
#include "BehaviorTree.h"
#include "GameDay.h"

Pnj::Pnj() {
}

Pnj::~Pnj() {
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
Customer::Customer() : Customer(0, {}) {
}

//position : 0 -> Top; 1 -> Left; 2 -> Right; 3 -> Bottom
Customer::Customer(int position, const std::vector<Shop*>& shops) : inShop(false), width(12), height(24), exit(false) { 
	blackBoard = new CustomerBlackBoard();
	blackBoard->customer = this;
	blackBoard->shops = shops;
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
	if (blackBoard) {
		delete blackBoard;
		blackBoard = nullptr;
	}
}

void Customer::Buy(Merchant* merchant) {
	merchant->Sell();
}


void Customer::MoveToShop(Shop* shop, float dt) { 
	if (!inShop) {
		if (!(pos.x >= shop->GetPosX() && pos.x + width <= shop->GetRightX() &&
			pos.y >= shop->GetPosY() && pos.y + height <= shop->GetBottomY())) {
			if (pos.x + width > shop->GetRightX()) {
				pos.x -= SPEED * dt;
				if (pos.x < shop->GetPosX()) {
					pos.x = shop->GetPosX();
				}
			}
			else if (pos.x < shop->GetPosX()) {
				pos.x += SPEED * dt;
				if (pos.x + width > shop->GetRightX()) {
					pos.x = shop->GetRightX() - width;
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
				if (pos.y + height > shop->GetBottomY()) {
					pos.y = shop->GetBottomY()- height;
				}
			}
		}
		if (pos.x + width >= shop->GetPosX() && pos.x <= shop->GetRightX() &&
			pos.y + height >= shop->GetPosY() && pos.y <= shop->GetBottomY()) {
			inShop = true;
		}
	}
}

void Customer::MoveToExit(int posistion, float dt) {
	dest = SetPos(posistion);
	if (pos != dest) {
		if (pos.x > dest.x) {
			pos.x -= SPEED * dt;
			if (pos.x < dest.x) {
				pos.x = dest.x;
			}
		}
		else if (pos.x < dest.x) {
			pos.x += SPEED * dt;
			if (pos.x + width > dest.x) {
				pos.x = dest.x;
			}
		}
		if (pos.y > dest.y) {
			pos.y -= SPEED * dt;
			if (pos.y < dest.y) {
				pos.y = dest.y;
			}
		}
		else if (pos.y < dest.y) {
			pos.y += SPEED * dt;
			if (pos.y + height > dest.y) {
				pos.y = dest.y;
			}
		}
	}
	if (pos == dest) {
		exit = true;
	}
}

void Customer::Render(sf::RenderWindow& window) {
	sprite->setPosition(pos);
	window.draw(*sprite);
}


//Merchants
Merchant::Merchant() : Merchant(nullptr) {
}

Merchant::Merchant(GameDay* day) : cash(1000), price(3), merchandise(0), salesNumber(0),
	canBuy(false), client(false), canSell(false) {
	blackBoard = new MerchantBlackBoard();
	blackBoard->merchant = this;
	blackBoard->day = day;
	behaviorTree = new MerchantBehaviorTree(blackBoard);
	behaviorTree->BuildTree();
	Price = nullptr;
}

Merchant::~Merchant() {
	if (Price) {
		delete Price;
		Price = nullptr;
	}
	if (blackBoard) {
		delete blackBoard;
		blackBoard = nullptr;
	}
}

void Merchant::Sell() {
	if (merchandise - 1 >= 0) {
		client = true;
	}
	else if (merchandise <= 0) {
		canSell = false;
	}
}

void Merchant::SellMerchandise() {
	if (client) {
		merchandise -= 1;
		salesNumber += 1;
	}
}

void Merchant::Cash() {
	cash += price;
	client = false;
}

void Merchant::Order(int newFurnitures) {
	if (cash - newFurnitures * 2 >= 0) {
		canBuy = true;
	}
	else {
		canBuy = false;
	}
}

void Merchant::SpendCash(int buyMerchandise) {
	if (cash - buyMerchandise * 2 >= 0) {
		cash -= buyMerchandise * 2;
		canBuy = true;
	}
	else {
		canBuy = false;
	}
}

void Merchant::GetFurnitures(int buyMerchandise) {
	merchandise += buyMerchandise;
}

void Merchant::UpdatePrice(int newPrice) {
Price: (new Training())->updateLeaning();
}


Saler::Saler(GameDay* day) {
	blackBoard->day = day;
}
Saler::~Saler() {
}


Baker::Baker(GameDay* day) {
	blackBoard->day = day;
}
Baker::~Baker() {
}


Butcher::Butcher(GameDay* day) {
	blackBoard->day = day;
}
Butcher::~Butcher() {
}


Waiter::Waiter(GameDay* day) {
	blackBoard->day = day;
}
Waiter::~Waiter() {
}


Pharmacist::Pharmacist(GameDay* day) {
	blackBoard->day = day;
}
Pharmacist::~Pharmacist() {
}


Hairdressers::Hairdressers(GameDay* day) {
	blackBoard->day = day;
}
Hairdressers::~Hairdressers() {
}

