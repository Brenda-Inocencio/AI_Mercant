#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>
#include "GameDay.h"


class HUD{
public:
	HUD();

	
	// Update value
	void Day(int d);
	void Time(float t);


	void Render(sf::RenderWindow& window, const std::string& message, float x, float y);

	~HUD();
private:
	sf::Font* font;
	sf::Font font_;
	sf::Text text = sf::Text(font_, "Day", 48);
	sf::Text text1 = sf::Text(font_, "Time", 48);

	int day;
	float time;

	void RenderText(sf::RenderWindow& window, const std::string& message, float x, float y);
	void RenderText1(sf::RenderWindow& window, const std::string& message, float x, float y);
};

#endif 