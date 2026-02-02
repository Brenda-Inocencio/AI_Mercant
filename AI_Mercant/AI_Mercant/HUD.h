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


	void Render(sf::RenderWindow& window, int d, float t);

	~HUD() {};
private:
	sf::Font font;
	std::string day;
	std::string time;
	sf::Text text = sf::Text(font, "Day : ", 24);
	sf::Text text1 = sf::Text(font, "Time : ", 24);
	sf::Text dayText = sf::Text(font, day, 24);
	sf::Text timeText = sf::Text(font, time, 24);

	void RenderText(sf::RenderWindow& window);
	void RenderText1(sf::RenderWindow& window);
};

#endif 