#include "Game.h"
#include "Shop.h"
#include "HUD.h"
#include "MenuStart.h"
#include "MenuEnd.h"
#include "Button.h"
#include "Setting.h"

Game::Game() : state(Menu) {
}

void Game::Render(sf::RenderWindow& window, MenuStart* menuStart, Button* start, Button* exit, Button* settingsButton,
    std::vector<Shop*>& shops, HUD* hud, sf::Sprite background, MenuEnd* menuEnd, Setting* setting, Button* increase, Button* decrease) {
    switch (state) {
    case 0:
        menuStart->Render(window);
        start->Render(window);
        exit->Render(window);
        settingsButton->Render(window);
        break;
    case 1:
        window.draw(background);
        for (int i = 0; i < shops.size(); i++) {
            shops[i]->Render(window);
        }
        hud->Render(window, 0, 0.f); // 0 et 0.f a modifier representent respectivement le jour et le temps
        break;
    case 2:
        menuEnd->Render(window);
        break;
    case 3:
        window.clear();
        setting->Render(window);
        increase->Render(window);
        decrease->Render(window);
        break;
    }
}

void Game::Update(bool isRunning, bool isEnd, bool isSettings) {
    if (isRunning) {
        state = Running;
    }
    else if (isEnd) {
        state = End;
    }
    else if (isSettings) {
        state = Settings;
    }
    else {
        state = Menu;
    }
}

void Game::CreateShop(std::vector<Shop*>& shops, int shop, sf::Vector2f placeIndex) {
    switch (shop) {
    case 0: {
        shops.push_back(new Shop(placeIndex));
        break;
    }
    case 1: {
        shops.push_back(new Bakery(placeIndex));
        break;
    }
    case 2: {
        shops.push_back(new ButcherShop(placeIndex));
        break;
    }
    case 3: {
        shops.push_back(new Coffee(placeIndex));
        break;
    }
    case 4: {
        shops.push_back(new Pharmacy(placeIndex));
        break;
    }
    case 5: {
        shops.push_back(new HairSalon(placeIndex));
        break;
    }
    }
}
