#include "HUD.h"

#include <iostream>

HUD::HUD() : day(0), time(0) {}

void HUD::Day(int d) {
	day = d;
}

void HUD::Time(float t) {
	time = t;
}

void HUD::Render(sf::RenderWindow& window, const std::string& message, float x, float y) {
	RenderText(window, message, x, y);
	RenderText1(window, message, x, y);
}

void HUD::RenderText(sf::RenderWindow& window, const std::string& message, float x, float y) {

	if (!font_.openFromFile("arial.ttf")) {
		std::cerr << "Error can't find font";
	}

	// Creation text
	text.setFont(font_);
	text.setString(message);
	text.setCharacterSize(48); // Taille en pixels
	text.setPosition(sf::Vector2f(x +255, y +255));
	text.setFillColor(sf::Color::White); // Couleur du texte
	text.setStyle(sf::Text::Bold); // Style
	window.draw(text);
}


void HUD::RenderText1(sf::RenderWindow& window, const std::string& message, float x, float y) {

	if (!font_.openFromFile("arial.ttf")) {
		std::cerr << "Error can't find font";
	}

	// Creation text
	text1.setFont(font_);
	text1.setString(message);
	text1.setCharacterSize(48); // Taille en pixels
	text1.setPosition(sf::Vector2f(x +255, y +250));
	text1.setFillColor(sf::Color::White); // Couleur du texte
	text1.setStyle(sf::Text::Bold); // Style
	window.draw(text1);
}