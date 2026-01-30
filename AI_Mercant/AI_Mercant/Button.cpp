#include "Button.h"


Button::Button() {
}

void Button::SetText(std::string textStirng, float posx, float posy, float width, float height, sf::Font& font) {
    text.setFont(font);
    text.setString(textStirng);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(20);
    text.setPosition(sf::Vector2f(posx + 30, posy + 15));
}


Exit::Exit() {
    posx = 350.f;
    posy = 375.f;
    width = 100.f;
    height = 50.f;
    if (!font.openFromFile("OpenSans-VariableFont_wdth,wght.ttf"))
        std::cerr << "Can't find the font file" << std::endl;

    button.setPosition(sf::Vector2f(posx, posy));
    button.setSize(sf::Vector2f(width, height));
    button.setFillColor(sf::Color::White);
    SetText("Exit", posx, posy, width, height, font);
}

void Exit::Render(sf::RenderWindow& window) {
    window.draw(button);
    window.draw(text);
}


Start::Start() {
    posx = 350.f;
    posy = 275.f;
    width = 100;
    height = 75;
    button = sf::RectangleShape(sf::Vector2f(200.0f, 50.0f));
    button.setPosition(sf::Vector2f(posx, posy));
    button.setFillColor(sf::Color::Blue);
    if (!font.openFromFile("OpenSans-VariableFont_wdth,wght.ttf"))
        std::cerr << "Can't find the font file" << std::endl;
    SetText("Start", posx, posy, width, height, font);
}

void Start::Render(sf::RenderWindow& window) {
    window.draw(button);
    window.draw(text);
}
