#include "MenuStart.h"


MenuStart::MenuStart() {

	image = new sf::Texture("StartMenu.png ");
	sprite = new sf::Sprite(*image);
}

void MenuStart::Render(sf::RenderWindow& window) {
	window.draw(*sprite);
}

MenuStart::~MenuStart()
{
	delete sprite;
	sprite = nullptr;
	delete image;
	image = nullptr;
}
