#include "Button.h"


Button::Button() {
}

void Button::SetText(std::string textStirng, float posx, float posy, sf::Font& font) {
    text.setFont(font);
    text.setString(textStirng);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(20);
    text.setPosition(sf::Vector2f(posx + 30, posy + 15));
}


Exit::Exit() {
    posx = 400.f;
    posy = 475.f;
    width = 100.f;
    height = 50.f;
    if (!font.openFromFile("OpenSans-VariableFont_wdth,wght.ttf"))
        std::cerr << "Can't find the font file" << std::endl;

    button.setPosition(sf::Vector2f(posx, posy));
    button.setSize(sf::Vector2f(width, height));
    button.setFillColor(sf::Color::Red);
    SetText("Exit", posx, posy, font);
}

void Exit::Render(sf::RenderWindow& window) {
    window.draw(button);
    window.draw(text);
}


Start::Start() {
    posx = 400.f;
    posy = 400;
    width = 100;
    height = 50;
    if (!font.openFromFile("OpenSans-VariableFont_wdth,wght.ttf"))
        std::cerr << "Can't find the font file" << std::endl;

    button.setPosition(sf::Vector2f(posx, posy));
    button.setSize(sf::Vector2f(width, height));
    button.setFillColor(sf::Color::Green);
    SetText("Start", posx, posy, font);
}

void Start::Render(sf::RenderWindow& window) {
    window.draw(button);
    window.draw(text);
}
