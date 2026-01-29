#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Button {
protected:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font font;
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;
public:
	Button() = default;
	virtual ~Button() = default;
};

class Exit : protected Button {
    sf::Vector2f pos;
public:
	Exit();
};

class Start : protected Button {

};