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
class GameDay;

class Game {
	enum EState {
		Menu = 0,
		Running = 1,
		End = 2,
		Settings = 3
	} state;
	bool isShopCreate;
	float spawnCooldown;
	bool canSpawn;
public:
	Game();
	~Game() {};
	void Render(sf::RenderWindow& window, MenuStart* menustart, Button* start, Button* exit, Button* settingsButton,
		std::vector<Shop*>& shops, std::vector<Customer*>& customers, HUD* hud, sf::Sprite background, MenuEnd* menuEnd, 
		Setting* setting, Button* increase, Button* decrease, GameDay* gameDay);
	void Update(float dt, float gameTime, bool isRunning, bool isEnd, bool isSettings, std::vector<Customer*>& customers,
		GameDay* gameDay, Setting* setting, std::vector<sf::Vector2f>& places, std::vector<Shop*>& shops);
	void CreateShop(std::vector<Shop*>& shops, int shop, sf::Vector2f places);
	void CreateCustomer(std::vector<Shop*>& shops, int pos, std::vector<Customer*>& customers);
	int GetRandomNumber(int min, int max);
};

