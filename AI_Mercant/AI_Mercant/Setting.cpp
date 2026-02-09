#include "Setting.h"

Setting::Setting(int _numberMerchants, int _numberMerchantsType) {
	numberMerchants = _numberMerchants;
	numberMerchantsType = _numberMerchantsType;

	image = new sf::Texture("Setting.png");
	sprite = new sf::Sprite(*image);
}

void Setting::Render(sf::RenderWindow& window) {
	window.draw(*sprite);
}

Setting::~Setting() {

	delete sprite;
	sprite = nullptr;
	delete image;
	image = nullptr;
}