#include "Pnj.h"
#include "BehaviorTree.h"

Pnj::Pnj() {
}

Pnj::~Pnj() {
}


//Customers
Customer::Customer() {
	cash = 100;
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


//Merchants
Merchant::Merchant() {
	cash = 1000;
	price = 3;
	Price = nullptr;
	salesNumber = 0;
	canSell = false;
	canBuy = false;
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
	else {
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


Hairdressers::Hairdressers() {
}

Hairdressers::~Hairdressers() {
}