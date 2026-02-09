#include "HUD.h"

#include <iostream>

HUD::HUD() : day("0"), time("0") {}

void HUD::Day(int d) {
	day = std::to_string(d);
	// Creation text
	dayText.setPosition(sf::Vector2f(470, 5));
	dayText.setFillColor(sf::Color::Black); // Couleur du texte
}

void HUD::Time(float t) {
	time = std::to_string(t);
	// Creation text
	timeText.setPosition(sf::Vector2f(480, 40));
	timeText.setFillColor(sf::Color::Black); // Couleur du texte
}

void HUD::Render(sf::RenderWindow& window, int d, float t) {
	RenderText(window);
	Day(t);
	window.draw(dayText);
	RenderText1(window);
	Time(t);
	window.draw(timeText);
}

void HUD::RenderText(sf::RenderWindow& window) {

	if (!font.openFromFile("arial.ttf")) {
		std::cerr << "Error can't find font";
	}

	// Creation text
	text.setPosition(sf::Vector2f(400, 5));
	text.setFillColor(sf::Color::Black); // Couleur du texte
	text.setStyle(sf::Text::Bold); // Style
	window.draw(text);
}


void HUD::RenderText1(sf::RenderWindow& window) {

	if (!font.openFromFile("arial.ttf")) {
		std::cerr << "Error can't find font";
	}

	// Creation text
	text1.setPosition(sf::Vector2f(400, 40));
	text1.setFillColor(sf::Color::Black); // Couleur du texte
	text1.setStyle(sf::Text::Bold); // Style
	window.draw(text1);
}