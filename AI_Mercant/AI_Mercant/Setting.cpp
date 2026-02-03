#include "Setting.h"

Setting::Setting() : width(700.f), height(300.f) {
    window.create(sf::VideoMode(width, height), "Setting");
    window.setFramerateLimit(60);

    shape.setFillColor(sf::Color::Green);
    shape.setSize(sf::Vector2f(static_cast<float>(width), static_cast<float>(height)));
}

void Setting::setting() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
            
        window.clear(sf::Color::Black);
        window.draw(shape);
        window.display();
    }
}

Setting::~Setting() {}