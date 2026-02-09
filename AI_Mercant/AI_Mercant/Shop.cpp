#include "Shop.h"

Shop::Shop(sf::Vector2f position) {
    pos = position;
    width = 175.f;
    height = 175.f;
    color = sf::Color::Yellow; 
    rect = sf::RectangleShape(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(position); 

    texture = new sf::Texture("Epicerie.png");
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2(2.f, 2.f));
}

Shop::~Shop() {
    delete texture;
    texture = nullptr;
    delete sprite;
    sprite = nullptr;
}

void Shop::Render(sf::RenderWindow& window) {
    window.draw(rect);
    window.draw(*sprite);
}

Bakery::Bakery(sf::Vector2f position) {
    pos = position;
    width = 175.f;
    height = 175.f;
    color = sf::Color::Red;
    rect = sf::RectangleShape(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(position);

    texture = new sf::Texture("Bakery.png");
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2(2.f, 2.f));
}

ButcherShop::ButcherShop(sf::Vector2f position) {
    pos = position;
    width = 175.f;
    height = 175.f;
    color = sf::Color::Blue;
    rect = sf::RectangleShape(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(position);

    texture = new sf::Texture("Butcher.png");
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2(2.f, 2.f));
}

Coffee::Coffee(sf::Vector2f position) {
    pos = position;
    width = 175.f;
    height = 175.f;
    color = sf::Color::Cyan;
    rect = sf::RectangleShape(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(position);

    texture = new sf::Texture("Cafe.png");
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2(2.f, 2.f));
}

Pharmacy::Pharmacy(sf::Vector2f position) {
    pos = position;
    width = 175.f;
    height = 175.f;
    color = sf::Color::Green;
    rect = sf::RectangleShape(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(position);

    texture = new sf::Texture("Pharmacie.png");
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2(2.f, 2.f));
}

HairSalon::HairSalon(sf::Vector2f position) {
    pos = position;
    width = 175.f;
    height = 175.f;
    color = sf::Color::Magenta;
    rect = sf::RectangleShape(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(position);

    texture = new sf::Texture("Coiffeur.png");
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2(2.f, 2.f));
}