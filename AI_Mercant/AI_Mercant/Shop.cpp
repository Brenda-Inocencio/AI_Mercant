#include "Shop.h"
#include "Pnj.h"

Shop::Shop() : Shop(sf::Vector2f({}), nullptr) {
}

Shop::Shop(sf::Vector2f position, GameDay* day) : pos(position), width(175.f), height(175.f) {
    merchant = new Saler(day);

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
    window.draw(*sprite);
}

Bakery::Bakery(sf::Vector2f position, GameDay* day) {
    merchant = new Baker(day);

    texture = new sf::Texture("Bakery.png");
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2(2.f, 2.f));
}

ButcherShop::ButcherShop(sf::Vector2f position, GameDay* day) {
    merchant = new Butcher(day);

    texture = new sf::Texture("Butcher.png");
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2(2.f, 2.f));
}

Coffee::Coffee(sf::Vector2f position, GameDay* day) {
    merchant = new Waiter(day);

    texture = new sf::Texture("Coffee.png");
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2(2.f, 2.f));
}

Pharmacy::Pharmacy(sf::Vector2f position, GameDay* day) {
    merchant = new Pharmacist(day);

    texture = new sf::Texture("Pharmacy.png");
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2(2.f, 2.f));
}

HairSalon::HairSalon(sf::Vector2f position, GameDay* day) {
    merchant = new Hairdressers(day);

    texture = new sf::Texture("Hairdressers.png");
    sprite = new sf::Sprite(*texture);
    sprite->setPosition(position);
    sprite->setScale(sf::Vector2(2.f, 2.f));
}

