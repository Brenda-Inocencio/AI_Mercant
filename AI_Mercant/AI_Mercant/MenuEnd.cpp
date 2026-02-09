#include "MenuEnd.h"


MenuEnd::MenuEnd() {

	image = new sf::Texture("EndMenu.png ");
	sprite = new sf::Sprite(*image);
}

void MenuEnd::Render(sf::RenderWindow& window) {
	window.draw(*sprite);
}

MenuEnd::~MenuEnd() {

	delete sprite;
	sprite = nullptr;
	delete image;
	image = nullptr;
}
