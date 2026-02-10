#include "Shop.h"
#include "Pnj.h"

Shop::Shop() : Shop(sf::Vector2f({})) {
}

Shop::Shop(sf::Vector2f position) : pos(position), width(185.f), height(215.f) {
    merchant = new Saler();
    color = sf::Color::Yellow;
    rect = sf::RectangleShape(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(position);
}

Shop::~Shop() {
    if (merchant) {
        delete merchant;
        merchant = nullptr;
    }
}

void Shop::Render(sf::RenderWindow& window) {
    window.draw(rect);
}

Bakery::Bakery(sf::Vector2f position) {
    merchant = new Baker();
    color = sf::Color::Red;
    rect = sf::RectangleShape(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(position);
}

ButcherShop::ButcherShop(sf::Vector2f position) {
    merchant = new Butcher();
    color = sf::Color::Blue;
    rect = sf::RectangleShape(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(position);
}

Coffee::Coffee(sf::Vector2f position) {
    merchant = new Waiter();
    color = sf::Color::Cyan;
    rect = sf::RectangleShape(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(position);
}

Pharmacy::Pharmacy(sf::Vector2f position) {
    merchant = new Pharmacist();
    color = sf::Color::Green;
    rect = sf::RectangleShape(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(position);
}

HairSalon::HairSalon(sf::Vector2f position) {
    merchant = new Hairdressers();
    color = sf::Color::Magenta;
    rect = sf::RectangleShape(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(position);
}


//sf::RectangleShape Shop::createRectangle(float width, float height, sf::Color color, sf::Vector2f position)
//{
//	return sf::RectangleShape();
//}
