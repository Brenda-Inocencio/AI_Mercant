#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Shop;
class HUD;

class Game {
public:
	Game() = default;
	~Game() {};
	void Render(sf::RenderWindow& window, std::vector<Shop*>& shops, HUD* hud);
	void Update();
};

