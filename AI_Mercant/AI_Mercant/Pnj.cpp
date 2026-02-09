#include "Pnj.h"
#include "BehaviorTree.h"

Pnj::Pnj() {
}

Pnj::~Pnj() {
}


//Costumers
Costumer::Costumer() {
	cash = 100;
}

void Costumer::buy(Merchant* merchant, int sales) {
	if (cash - merchant->GetPrice() >= 0) {
		cash -= merchant->GetPrice();
		merchant->Sell(sales);
	}
}


//Merchants
Merchant::Merchant() {
	cash = 1000;
	price = 3;
	Price = nullptr;
	salesNumber = 0;
	noStock = true;
}

Merchant::~Merchant() {
	if (Price) {
		delete Price;
		Price = nullptr;
	}
}


Saler::Saler() {
	furnitures = 0;
}

Saler::~Saler() {
}

void Saler::Sell(int sales) {
	if (furnitures - sales < 0) {
		noStock = true;
	}
	else if (furnitures - sales >= 0) {
		furnitures -= sales;
		salesNumber += sales;
	}
}

void Saler::Order(int newFurnitures) {
	if (cash - newFurnitures * 2 >= 0) {
		cash -= newFurnitures * 2;
		furnitures += newFurnitures;
	}
	if (furnitures >= 0) {
		noStock = false;
	}
}


void Saler::UpdatePrice(float newPrice) {
	Price : (new Training())->updateLeaning();
}


Baker::Baker() {
	breads = 0;
}

Baker::~Baker() {
}

void Baker::Sell(int sales) {
	if (breads - sales < 0) {
		noStock = true;
	}
	else if (breads - sales >= 0) {
		breads -= sales;
		salesNumber += sales;
		cash += sales * 3;
	}
}

void Baker::Order(int newFurnitures) {
	if (cash - newFurnitures * 2 >= 0) {
		cash -= newFurnitures * 2;
		breads += newFurnitures;
	}
	if (breads >= 0) {
		noStock = false;
	}
}

void Baker::UpdatePrice(int newPrice) {
	Price: (new Training())->updateLeaning();
}

Butcher::Butcher() {
	meats = 0;
}

Butcher::~Butcher() {
}

void Butcher::Sell(int sales) {
	if (meats - sales < 0) {
		noStock = true;
	}
	else if (meats - sales >= 0) {
		meats -= sales;
		salesNumber += sales;
		cash += sales * 3;
	}
}

void Butcher::Order(int newFurnitures) {
	if (cash - newFurnitures * 2 >= 0) {
		cash -= newFurnitures * 2;
		meats += newFurnitures;
	}
	if (meats >= 0) {
		noStock = false;
	}
}

void Butcher::UpdatePrice(int newPrice) {
	Price: (new Training())->updateLeaning();
}


Waiter::Waiter() {
	coffees = 0;
}

Waiter::~Waiter() {
}

void Waiter::Sell(int sales) {
	if (coffees - sales < 0) {
		noStock = true;
	}
	else if (coffees - sales >= 0) {
		coffees -= sales;
		salesNumber += sales;
		cash += sales * 3;
	}
}

void Waiter::Order(int newFurnitures) {
	if (cash - newFurnitures * 2 >= 0) {
		cash -= newFurnitures * 2;
		coffees += newFurnitures;
	}
	if (coffees >= 0) {
		noStock = false;
	}
}

void Waiter::UpdatePrice(int newPrice) {
	Price: (new Training())->updateLeaning();
}


Hairdressers::Hairdressers() {
	hair = 0;
}

Hairdressers::~Hairdressers() {
}

void Hairdressers::Sell(int sales) {
	if (hair - sales < 0) {
		noStock = true;
	}
	else if (hair - sales >= 0) {
		hair -= sales;
		salesNumber += sales;
		cash += sales * 3;
	}
}

void Hairdressers::Order(int newFurnitures) {
	if (cash - newFurnitures * 2 >= 0) {
		cash -= newFurnitures * 2;
		hair += newFurnitures;
	}
	if (hair >= 0) {
		noStock = false;
	}
}

void Hairdressers::UpdatePrice(int newPrice) {
	Price: (new Training())->updateLeaning();
}