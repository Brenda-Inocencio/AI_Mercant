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

	virtual ~Shop();

	void Render(sf::RenderWindow& window);

	inline sf::Vector2f GetPosition() { return pos; }
	inline float GetPosX() { return pos.x; }
	inline float GetRightX() { return pos.x + width; }
	inline float GetPosY() { return pos.y; }
	inline float GetBottomY() { return pos.y + height; }
	inline Merchant* GetMerchant() { return merchant; }
	virtual inline std::string String() { return shop; }

protected:
	std::string shop;
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

	virtual ~Bakery() override {};

};

class ButcherShop : public Shop {
public:
	ButcherShop() = default;
	ButcherShop(sf::Vector2f position);

	virtual ~ButcherShop() override {};

};

class Coffee : public Shop {
public:
	Coffee() = default;
	Coffee(sf::Vector2f position);

	virtual ~Coffee() override {};

};

class Pharmacy : public Shop {
public:
	Pharmacy() = default;
	Pharmacy(sf::Vector2f position);

	virtual ~Pharmacy() override {};

};

class HairSalon : public Shop {
public:
	HairSalon() = default;
	HairSalon(sf::Vector2f position);

	virtual ~HairSalon() override {};

};

#endif