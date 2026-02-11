#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include <SFML/Graphics.hpp>

//==================
//==== 6 Trader ====
//==================

class Merchant;

class Shop {
public:

	Shop();
	Shop(sf::Vector2f position);

	~Shop();

	void Render(sf::RenderWindow& window);

	inline sf::Vector2f GetPosition() { return pos; }
	inline float GetPosX() { return pos.x; }
	inline float GetRightX() { return pos.x + width; }
	inline float GetPosY() { return pos.y; }
	inline float GetBottomY() { return pos.y + height; }
	inline Merchant* GetMerchant() { return merchant; }

protected:
	sf::Color color;
	sf::RectangleShape rect;
	float width;
	float height;
	sf::Vector2f pos;
	Merchant* merchant;
	sf::Texture* texture;
	sf::Sprite* sprite;
};


class Bakery : public Shop {
public:

	Bakery() = default;
	Bakery(sf::Vector2f position);

	~Bakery() {};

};

class ButcherShop : public Shop {
public:
	ButcherShop() = default;
	ButcherShop(sf::Vector2f position);

	~ButcherShop() {};

};

class Coffee : public Shop {
public:
	Coffee() = default;
	Coffee(sf::Vector2f position);

	~Coffee() {};

};

class Pharmacy : public Shop {
public:
	Pharmacy() = default;
	Pharmacy(sf::Vector2f position);

	~Pharmacy() {};

};

class HairSalon : public Shop {
public:
	HairSalon() = default;
	HairSalon(sf::Vector2f position);

	~HairSalon() {};

};

#endif