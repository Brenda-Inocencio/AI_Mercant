#include "Pnj.h"
#include "BehaviorTree.h"

Pnj::Pnj() {
	AI = new Node();
	pnjRoot = new RootNode(AI);
	pnjType.clear();
	for (int i = 0; i < AI_TYPE; i++) {
		pnjType.push_back(new Node());
	}
	AIType = new FluxNode(AI, pnjType);
}

Pnj::~Pnj() {
	if (pnjRoot) {
		delete pnjRoot; 
		pnjRoot = nullptr;
	}
	if (AI) {
		delete AI; 
		AI = nullptr;
	}
	for (int i = 0; i < pnjType.size(); i++) {
		if (pnjType[i]) {
			delete pnjType[i];
			pnjType[i] = nullptr;
		}
	}
	pnjType.clear();
}


//Costumers
Costumer::Costumer(sf::Vector2f position) {
	cash = 100;

	tasks.clear();
	for (int i = 0; i < COSTUMER_TASKS; i++) {
		tasks.push_back(new Node());
	}

	costumers = new FluxNode(pnjType[COSTUMERS], tasks);

	shape.setRadius(20.f);
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(sf::Vector2f(400.f, 0.f));
	
	pos = position;
	width = 12.f;
	height = 24.f;
	color = sf::Color::Yellow;
	rect = sf::RectangleShape(sf::Vector2f(width, height));
	rect.setFillColor(color);

	texture = new sf::Texture("Gars1.png");
	sprite = new sf::Sprite(*texture);
	sprite->setPosition(position);
	sprite->setScale(sf::Vector2(2.f, 2.f));
}

void Costumer::buy(Merchant* merchant, int sales) {
	if (cash >= merchant->GetPrice()) {
		cash -= merchant->GetPrice();
		merchant->Sell(sales);
	}
}

void Costumer::Render(sf::RenderWindow& window) {
	window.draw(rect);
	window.draw(*sprite);
}

Costumer::~Costumer() {
	delete texture;
	texture = nullptr;
	delete sprite;
	sprite = nullptr;
}

//Merchants
Merchant::Merchant() {
	cash = 1000;
	price = 3;
	salesNumber = 0;
	noStock = true;
	merchantType.clear();
	for (int i = 0; i < MERCHANT_NUMBERS; i++) {
		merchantType.push_back(new Node());
	}
	merchants = new FluxNode(pnjType[MERCHANT], merchantType);
}

Merchant::~Merchant() {
	for (int i = 0; i < merchantType.size(); i++) {
		if (merchantType[i]) {
			delete merchantType[i];
			merchantType[i] = nullptr;
		}
	}
	merchantType.clear();
	if (merchants) {
		delete merchants; 
		merchants = nullptr;
		delete Price;
		Price = nullptr;
	}
}


Saler::Saler() {
	furnitures = 0;
	Price = nullptr;
	stateType.clear();
	for (int i = 0; i < STATES; i++) {
		stateType.push_back(new Node());
	}
	states = new FluxNode(merchantType[SALER], stateType);
}

Saler::~Saler() {
	for (int i = 0; i < stateType.size(); i++) {
		if (stateType[i]) {
			delete stateType[i];
			stateType[i] = nullptr;
		}
	}
	stateType.clear();
	if (states) {
		delete states;
		states = nullptr;
	}
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
	stateType.clear();
	for (int i = 0; i < STATES; i++) {
		stateType.push_back(new Node());
	}
	states = new FluxNode(merchantType[BAKER], stateType);
}

Baker::~Baker() {
	for (int i = 0; i < stateType.size(); i++) {
		if (stateType[i]) {
			delete stateType[i];
			stateType[i] = nullptr;
		}
	}
	stateType.clear();
	if (states) {
		delete states;
		states = nullptr;
	}
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
	stateType.clear();
	for (int i = 0; i < STATES; i++) {
		stateType.push_back(new Node());
	}
	states = new FluxNode(merchantType[BUTCHER], stateType);
}

Butcher::~Butcher() {
	for (int i = 0; i < stateType.size(); i++) {
		if (stateType[i]) {
			delete stateType[i];
			stateType[i] = nullptr;
		}
	}
	stateType.clear();
	if (states) {
		delete states;
		states = nullptr;
	}
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
	stateType.clear();
	for (int i = 0; i < STATES; i++) {
		stateType.push_back(new Node());
	}
	states = new FluxNode(merchantType[WAITER], stateType);
}

Waiter::~Waiter() {
	for (int i = 0; i < stateType.size(); i++) {
		if (stateType[i]) {
			delete stateType[i];
			stateType[i] = nullptr;
		}
	}
	stateType.clear();
	if (states) {
		delete states;
		states = nullptr;
	}
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
	stateType.clear();
	for (int i = 0; i < STATES; i++) {
		stateType.push_back(new Node());
	}
	states = new FluxNode(merchantType[HAIRDRESSERS], stateType);
}

Hairdressers::~Hairdressers() {
	for (int i = 0; i < stateType.size(); i++) {
		if (stateType[i]) {
			delete stateType[i];
			stateType[i] = nullptr;
		}
	}
	stateType.clear();
	if (states) {
		delete states;
		states = nullptr;
	}
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