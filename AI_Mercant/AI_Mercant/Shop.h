#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <SFML/Graphics.hpp>


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

class Butcher : protected Shop {
public:
	Butcher();

	static sf::RectangleShape createRectangle(float width, float height, sf::Color color, sf::Vector2f position);

	~Butcher();
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

class Hairdressers : protected Shop {
public:
	Hairdressers();

	static sf::RectangleShape createRectangle(float width, float height, sf::Color color, sf::Vector2f position);

	~Hairdressers();
};

#endif