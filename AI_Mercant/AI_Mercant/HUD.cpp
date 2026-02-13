#include "HUD.h"

#include <iostream>

HUD::HUD() : day("0"), time("Morning") {}

void HUD::Day(int d) {
	day = std::to_string(d);
	dayText.setString(day);
	// Creation text
	dayText.setPosition(sf::Vector2f(470, 5));
	dayText.setFillColor(sf::Color::Black); // Couleur du texte
}

void HUD::Time(std::string t) {
	time = t;
	timeText.setString(time);
	// Creation text
	timeText.setPosition(sf::Vector2f(460, 40));
	timeText.setFillColor(sf::Color::Black); // Couleur du texte
}

void HUD::Render(sf::RenderWindow& window, int d, std::string t) {
	RenderText(window);
	Day(d);
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
	text1.setPosition(sf::Vector2f(380, 40));
	text1.setFillColor(sf::Color::Black); // Couleur du texte
	text1.setStyle(sf::Text::Bold); // Style
	window.draw(text1);
}