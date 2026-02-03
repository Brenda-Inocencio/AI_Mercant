#include "Setting.h"


Setting::Setting() {

	image = new sf::Texture("Setting.png");
	sprite = new sf::Sprite(*image);
}

void Setting::Render(sf::RenderWindow& window) {
	window.draw(*sprite);
}

Setting::~Setting(){

	delete sprite;
	sprite = nullptr;
	delete image;
	image = nullptr;
}