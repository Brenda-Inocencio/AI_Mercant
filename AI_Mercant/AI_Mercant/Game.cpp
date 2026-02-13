#include "Game.h"
#include "Shop.h"
#include "Pnj.h"
#include "HUD.h"
#include "MenuStart.h"
#include "MenuEnd.h"
#include "Button.h"
#include "Setting.h"
#include "BehaviorTree.h"
#include "GameDay.h"
#include <random>

Game::Game() : state(Menu), isShopCreate(false), canSpawn(true), spawnCooldown(0) {
}

void Game::Render(sf::RenderWindow& window, MenuStart* menuStart, Button* start, Button* exit, Button* settingsButton,
    std::vector<Shop*>& shops, std::vector<Customer*>& customers, HUD* hud, sf::Sprite background, MenuEnd* menuEnd, 
    Setting* setting, Button* increase, Button* decrease, GameDay* gameDay) {
    switch (state) {
    case 0:
        menuStart->Render(window);
        start->Render(window);
        exit->Render(window);
        settingsButton->Render(window);
        break;
    case 1:
        window.draw(background);
        if (gameDay->m_phase == DayPhase::Day) {
            for (int i = 0; i < customers.size(); i++) {
                customers[i]->Render(window);
            }
        }
        for (int i = 0; i < shops.size(); i++) {
            shops[i]->Render(window);
        }
        hud->Render(window, gameDay->GetDay(), gameDay->GetTime());
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

void Game::Update(float dt, float gameTime, bool isRunning, bool isEnd, bool isSettings, std::vector<Customer*>& customers, 
    GameDay* gameDay, Setting* setting, std::vector<sf::Vector2f>& places, std::vector<Shop*>& shops) {
    if (isRunning) {
        state = Running;
        if (!isShopCreate) {
            size_t maxShops = std::min(setting->numberMerchants, static_cast<int>(places.size()));

            for (size_t i = 0; i < maxShops; i++) {
                int randomShop = GetRandomNumber(0, setting->numberMerchantsType - 1);
                CreateShop(shops, randomShop, places[i]);
            }
            isShopCreate = true;
        }
        gameDay->Update(dt);
        if (gameDay->m_phase == DayPhase::Day) {
            if (gameTime - spawnCooldown >= 1.f) {
                canSpawn = true;
            }
            if (canSpawn) {
                spawnCooldown = gameTime;
            }
            for (int i = 0; i < customers.size(); i++) {
                customers[i]->behaviorTree->Tick(dt);
            }
        }
    }
    else if (isEnd) {
        state = End;
    }
    else if (isSettings) {
        state = Settings;
        isShopCreate = false;
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

void Game::CreateCustomer(std::vector<Shop*>& shops, int pos, std::vector<Customer*>& customers) {
    for (int i = 0; i < 1; i++) { //TODO: 4 a canger en aleatoire
        int pos = GetRandomNumber(0, 3);
        customers.push_back(new Customer(pos, shops));
    }

    for (int i = 0; i < customers.size(); i++) {
        customers[i]->behaviorTree->BeginExecute();
    }
}

int Game::GetRandomNumber(int min, int max) {
    std::random_device m_rd;
    std::mt19937 m_gen(m_rd());

    std::uniform_int_distribution<int> dis(min, max);
    return dis(m_gen);
}