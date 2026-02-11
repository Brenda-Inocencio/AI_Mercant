#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class MenuStart;
class MenuEnd;
class Setting;
class Button;
class Shop;
class Customer;
class HUD;

class Game {
	enum EState {
		Menu = 0,
		Running = 1,
		End = 2,
		Settings = 3
	} state;
public:
	Game();
	~Game() {};
	void Render(sf::RenderWindow& window, MenuStart* menustart, Button* start, Button* exit, Button* settingsButton,
		std::vector<Shop*>& shops, std::vector<Customer*> customers, HUD* hud, sf::Sprite background, MenuEnd* menuEnd, Setting* setting, Button* increase, Button* decrease);
	void Update(float dt, bool isRunning, bool isEnd, bool isSettings, std::vector<Customer*> customers);
	void CreateShop(std::vector<Shop*>& shops, int shop, sf::Vector2f places);
};

