#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <SFML/Graphics.hpp>

//==================
//==== 6 Trader ====
//==================

class Shop {
public:

	Shop();

	static sf::RectangleShape createRectangle(float width, float height, sf::Color color, sf::Vector2f position);

	~Shop();
};


class Bakery : protected Shop {
public:

	Bakery();

	static sf::RectangleShape createRectangle(float width, float height, sf::Color color, sf::Vector2f position);

	~Bakery();
};

class ButcherShop : protected Shop {
public:
	ButcherShop();

	static sf::RectangleShape createRectangle(float width, float height, sf::Color color, sf::Vector2f position);

	~ButcherShop();
};

class Coffee : protected Shop {
public:
	Coffee();

	static sf::RectangleShape createRectangle(float width, float height, sf::Color color, sf::Vector2f position);

	~Coffee();
};

class Pharmacy : protected Shop {
public:
	Pharmacy();

	static sf::RectangleShape createRectangle(float width, float height, sf::Color color, sf::Vector2f position);

	~Pharmacy();
};

class HairSalon : protected Shop {
public:
	HairSalon();

	static sf::RectangleShape createRectangle(float width, float height, sf::Color color, sf::Vector2f position);

	~HairSalon();
};

#endif