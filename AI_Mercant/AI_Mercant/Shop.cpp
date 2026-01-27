#include "Shop.h"

Shop::Shop() {
}

sf::RectangleShape Shop::createRectangle(float width, float height, sf::Color color, sf::Vector2f position) {

	sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setFillColor(color);
    rectangle.setPosition(position);
    return rectangle;
}


Bakery::Bakery() {
}

sf::RectangleShape Bakery::createRectangle(float width, float height, sf::Color color, sf::Vector2f position) {

    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setFillColor(color);
    rectangle.setPosition(position);
    return rectangle;
}


Butcher::Butcher() {
}

sf::RectangleShape Butcher::createRectangle(float width, float height, sf::Color color, sf::Vector2f position) {

    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setFillColor(color);
    rectangle.setPosition(position);
    return rectangle;
}


Coffee::Coffee() {
}

sf::RectangleShape Coffee::createRectangle(float width, float height, sf::Color color, sf::Vector2f position) {

    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setFillColor(color);
    rectangle.setPosition(position);
    return rectangle;
}


Pharmacy::Pharmacy() {
}

sf::RectangleShape Pharmacy::createRectangle(float width, float height, sf::Color color, sf::Vector2f position) {

    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setFillColor(color);
    rectangle.setPosition(position);
    return rectangle;
}


HairSalon::HairSalon() {
}

sf::RectangleShape HairSalon::createRectangle(float width, float height, sf::Color color, sf::Vector2f position) {

    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setFillColor(color);
    rectangle.setPosition(position);
    return rectangle;
}


//sf::RectangleShape Shop::createRectangle(float width, float height, sf::Color color, sf::Vector2f position)
//{
//	return sf::RectangleShape();
//}
