#include <SFML/Graphics.hpp>
#include <optional>
#include <SFML/Window/Export.hpp>
#include <vector>
#include "Shop.h"
#include "Pnj.h"
#include "BehaviorTree.h"
#include "GameDay.h"
#include "HUD.h"
#include "Setting.h"
#include "button.h"
#include "MenuStart.h"
#include "MenuEnd.h"
#include "Game.h"

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({900, 600}), "SFML window");

    // Load a sprite to display
    const sf::Texture texture("Background.png");
    sf::Sprite bg(texture);

    int nbMerchants = 8;
    int nbMerchantsType = 6;
    //Settings initiallisation
    Setting* setting = new Setting(nbMerchants, nbMerchantsType);
    Game game;

    std::vector<sf::Vector2f> places = {
        { -10.f, -10.f }, { 165.f, -10.f }, { 540.f, -10.f }, { 715.f, -10.f },
        { -10.f, 410.f }, { 165.f, 410.f }, { 540.f, 410.f }, { 715.f, 410.f }
    };
    std::vector<Shop*> shops;

    std::vector<Customer*> customers;

    HUD* hud = new HUD();
    GameDay* gameDay = new GameDay();
    MenuStart* menustart = new MenuStart();
    MenuEnd* menuend = new MenuEnd();
    Button* exit = new Exit();
    Button* start = new Start();
    Button* settingsButton = new SettingsButton();
    Button* increase = new ButtonRight();
    Button* decrease = new ButtonLeft();
    
    sf::Clock clock;
    float timer = 0.f;
    float dt = 0.0f;
    bool isRunning = false;
    bool isSettings = false;
    bool endSim = false;
    // Start the game loop
    while (window.isOpen()) {
        dt = clock.restart().asSeconds();
        timer += dt;
        // Process events
        while (const auto event = window.pollEvent()) {
            // Close window: exit
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (event->is<sf::Event::MouseButtonPressed>()) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (start->GetPosX() <= static_cast<float>(mousePos.x) && start->GetRightX() >= static_cast<float>(mousePos.x) &&
                    start->GetPosY() <= static_cast<float>(mousePos.y) && start->GetBottomY() >= static_cast<float>(mousePos.y)) {
                    isRunning = true;
                }
                else if (exit->GetPosX() <= static_cast<float>(mousePos.x) && exit->GetRightX() >= static_cast<float>(mousePos.x) &&
                    exit->GetPosY() <= static_cast<float>(mousePos.y) && exit->GetBottomY() >= static_cast<float>(mousePos.y)) {
                    window.close();
                }
                else if (settingsButton->GetPosX() <= static_cast<float>(mousePos.x) && settingsButton->GetRightX() >= static_cast<float>(mousePos.x) &&
                    settingsButton->GetPosY() <= static_cast<float>(mousePos.y) && settingsButton->GetBottomY() >= static_cast<float>(mousePos.y)) {
                    isSettings = true;
                }
                if (isSettings) { 
                    if (increase->GetPosX() <= static_cast<float>(mousePos.x) && increase->GetRightX() >= static_cast<float>(mousePos.x) &&
                        increase->GetPosY() <= static_cast<float>(mousePos.y) && increase->GetBottomY() >= static_cast<float>(mousePos.y)) {   
                        setting->numberMerchants += 1;
                        std::cerr << "+1" << "\n";
                    }
                    else if (decrease->GetPosX() <= static_cast<float>(mousePos.x) && decrease->GetRightX() >= static_cast<float>(mousePos.x) &&
                        decrease->GetPosY() <= static_cast<float>(mousePos.y) && decrease->GetBottomY() >= static_cast<float>(mousePos.y)) {  
                        setting->numberMerchants  -= 1;
                        std::cerr << "-1" << "\n";
                    }
                }
            }
            else if (event->is<sf::Event::KeyPressed>()) {  
                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape) {
                    isSettings = false;
                }
            }
        }   

        // Clear screen
        window.clear();
        game.Update(dt, timer, isRunning, endSim, isSettings, customers, gameDay, setting, places, shops);
        
        // Draw the sprite
        game.Render(window, menustart, start, exit, settingsButton, shops, customers, hud, bg, menuend, setting, increase, decrease, gameDay);
        
        // Update the window
        window.display();
    }

    for (int i = 0; i < shops.size(); i++) {
        delete shops[i];
        shops[i] = nullptr;
    }
    shops.clear();

    for (int i = 0; i < customers.size(); i++) {
        delete customers[i];
        customers[i] = nullptr;
    }
    customers.clear();

    delete hud; hud = nullptr;
    delete menustart; menustart = nullptr;
    delete menuend; menuend = nullptr;
    delete setting; setting = nullptr;
    delete exit; exit = nullptr;
    delete start; start = nullptr;
    delete settingsButton; settingsButton = nullptr;
    delete increase; increase = nullptr;
    delete decrease; decrease = nullptr;
}