#include "Button.h"


Button::Button() {
}

void Button::SetText(std::string textStirng, float posx, float posy, float width, float height, sf::Font& font) {
    text.setFont(font);
    text.setString(textStirng);
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(20);
    float centerX = (GetPosX() + GetRightX()) / 2.f;
    float centerY = (GetPosY() + GetBottomY()) / 2.f;

    sf::FloatRect bounds = text.getLocalBounds();
    text.setOrigin(bounds.getCenter());
    text.setPosition(sf::Vector2f(posx + width / 2.f, posy + height / 2.f));
}


Exit::Exit() {
    posx = 400.f;
    posy = 500.f;
    width = 100.f;
    height = 50.f;
    if (!font.openFromFile("OpenSans-VariableFont_wdth,wght.ttf"))
        std::cerr << "Can't find the font file" << std::endl;

    button.setPosition(sf::Vector2f(posx, posy));
    button.setSize(sf::Vector2f(width, height));
    button.setFillColor(sf::Color::Red);
    SetText("Exit", posx, posy, width, height, font);
}

void Exit::Render(sf::RenderWindow& window) {
    window.draw(button);
    window.draw(text);
}


Start::Start() {
    posx = 400;
    posy = 400;
    width = 100;
    height = 50;
    if (!font.openFromFile("OpenSans-VariableFont_wdth,wght.ttf"))
        std::cerr << "Can't find the font file" << std::endl;

    button.setPosition(sf::Vector2f(posx, posy));
    button.setSize(sf::Vector2f(width, height));
    button.setFillColor(sf::Color::Green);
    SetText("Start", posx, posy, width, height, font);
}

void Start::Render(sf::RenderWindow& window) {
    window.draw(button);
    window.draw(text);
}

SettingsButton::SettingsButton() {
    posx = 400;
    posy = 450;
    width = 100;
    height = 50;
    if (!font.openFromFile("OpenSans-VariableFont_wdth,wght.ttf"))
        std::cerr << "Can't find the font file" << std::endl;

    button.setPosition(sf::Vector2f(posx, posy));
    button.setSize(sf::Vector2f(width, height));
    button.setFillColor(sf::Color::Cyan);
    SetText("Settings", posx, posy, width, height, font);
}

void SettingsButton::Render(sf::RenderWindow& window) {
    window.draw(button);
    window.draw(text);
}

ButtonLeft::ButtonLeft() {
    posx = 250;
    posy = 225;
    width = 100;
    height = 50;
    if (!font.openFromFile("OpenSans-VariableFont_wdth,wght.ttf"))
        std::cerr << "Can't find the font file" << std::endl;

    button.setPosition(sf::Vector2f(posx, posy));
    button.setSize(sf::Vector2f(width, height));
    button.setFillColor(sf::Color::Cyan);
    SetText("Decrease", posx, posy, width, height, font);
}

void ButtonLeft::Render(sf::RenderWindow& window) {
    window.draw(button);
    window.draw(text);
}

ButtonRight::ButtonRight() {
    posx = 550;
    posy = 225;
    width = 100;
    height = 50;
    if (!font.openFromFile("OpenSans-VariableFont_wdth,wght.ttf"))
        std::cerr << "Can't find the font file" << std::endl;

    button.setPosition(sf::Vector2f(posx, posy));
    button.setSize(sf::Vector2f(width, height));
    button.setFillColor(sf::Color::Cyan);
    SetText("Increase", posx, posy, width, height, font);
}

void ButtonRight::Render(sf::RenderWindow& window) {
    window.draw(button);
    window.draw(text);
}