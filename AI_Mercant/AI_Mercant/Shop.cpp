#include "Shop.h"
#include "Pnj.h"

Shop::Shop() : Shop(sf::Vector2f({})) {
}

Shop::Shop(sf::Vector2f position) : pos(position), width(175.f), height(175.f) {
    merchant = new Saler();
    color = sf::Color::Yellow;
    rect = sf::RectangleShape(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(position);

    texture = new sf::Texture("Shop.png");
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2(2.f, 2.f));
}

Shop::~Shop() {
    if (merchant) {
        delete merchant;
        merchant = nullptr;
    }
    if (texture) {
        delete texture;
        texture = nullptr;
    }
    if (sprite) {
        delete sprite;
        sprite = nullptr;
    }
}

void Shop::Render(sf::RenderWindow& window) {
    //window.draw(rect);
    window.draw(*sprite);
}

Bakery::Bakery(sf::Vector2f position) {
    merchant = new Baker();
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
    merchant = new Butcher();
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
    merchant = new Waiter();
    color = sf::Color::Cyan;
    rect = sf::RectangleShape(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(position);

    texture = new sf::Texture("Coffee.png");
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2(2.f, 2.f));
}

Pharmacy::Pharmacy(sf::Vector2f position) {
    merchant = new Pharmacist();
    color = sf::Color::Green;
    rect = sf::RectangleShape(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(position);

    texture = new sf::Texture("Pharmacy.png");
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2(2.f, 2.f));
}

HairSalon::HairSalon(sf::Vector2f position) {
    merchant = new Hairdressers();
    color = sf::Color::Magenta;
    rect = sf::RectangleShape(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(position);

    texture = new sf::Texture("Hairdressers.png");
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2(2.f, 2.f));
}


//sf::RectangleShape Shop::createRectangle(float width, float height, sf::Color color, sf::Vector2f position)
//{
//	return sf::RectangleShape();
//}
