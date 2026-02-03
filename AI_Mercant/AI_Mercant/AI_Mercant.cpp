#include <SFML/Graphics.hpp>
#include <optional>
#include <SFML/Window/Export.hpp>
#include <vector>
#include <random>
#include "Shop.h"
#include "GameDay.h"
#include "HUD.h"
#include "Settings.h"
#include "button.h"
#include "MenuStart.h"
#include "MenuEnd.h"
#include "Setting.h"

int GetRandomNumber(int min, int max) {
    std::random_device m_rd;
    std::mt19937 m_gen(m_rd());

    std::uniform_int_distribution<int> dis(min, max);
    return dis(m_gen);
}

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({900, 600}), "SFML window");

    // Load a sprite to display
    const sf::Texture texture("Background.png");
    sf::Sprite sprite(texture);

    int nbMerchants = 8; 
    int nbMerchantsType = 6;
    //Settings initiallisation
    Settings settings(nbMerchants, nbMerchantsType);

    std::vector<sf::Vector2f> places = {
        { 0.f, 0.f }, { 185.f, 0.f }, { 540.f, 0.f }, { 715.f, 0.f },
        { 0.f, 385.f }, { 185.f, 385.f }, { 540.f, 385.f }, { 715.f, 385.f }
    };
    std::vector<Shop*> shops;
    size_t maxShops = std::min(settings.GetNumberMerchants(), static_cast<int>(places.size()));

    for (size_t i = 0; i < maxShops; i++) {
        int randomShop = GetRandomNumber(0, settings.GetNumberMerchantsType() - 1);

        switch (randomShop) {
        case 0: {
            shops.push_back(new Shop(places[i]));
            break;
        }
        case 1:{
            shops.push_back(new Bakery(places[i]));
            break;
        }
        case 2:{
            shops.push_back(new ButcherShop(places[i]));
            break;
        }
        case 3: {
            shops.push_back(new Coffee(places[i]));
            break;
        }
        case 4: {
            shops.push_back(new Pharmacy(places[i]));
            break;
        }
        case 5: {
            shops.push_back(new HairSalon(places[i]));
            break;
        }
        }
    }

    HUD* hud = new HUD();
    MenuStart* menustart = new MenuStart();
    MenuEnd* menuend = new MenuEnd();
    Setting* setting = new Setting();
    Button* exit = new Exit();
    Button* start = new Start();
    Button* settingsButton = new SettingsButton();

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
            if (event->is<sf::Event::Closed>())
                window.close();

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
            }
            else if (event->is<sf::Event::KeyPressed>()) {
                if (event->getIf<sf::Event::KeyPressed>()->code == sf::Keyboard::Key::Escape) {
                    isSettings = false;
                    isRunning = false;
                }
            }
        }   

        // Clear screen
        window.clear();

        // Draw the sprite
        //Draw the rectangle

        if (isSettings) {
            window.clear();
            setting->Render(window);
        }
        else if (!isRunning) {
            menustart->Render(window);
            start->Render(window);
            exit->Render(window);
            settingsButton->Render(window);
            
        }
        if (true) {
            window.draw(sprite);
            for (int i = 0; i < shops.size(); i++) {
                shops[i]->Render(window);
            }
            hud->Render(window, 0, 0.f); // 0 et 0.f a modifier representent respectivement le jour et le temps
        }
        else if (endSim) {
            menuend->Render(window);
        }


        // Update the window
        window.display();
    }

    for (int i = 0; i < shops.size(); i++) {
        delete shops[i];
        shops[i] = nullptr;
    }
    shops.clear();

    delete hud; hud = nullptr;
    delete menustart; menustart = nullptr;
    delete menuend; menuend = nullptr;
    delete exit; exit = nullptr;
    delete start; start = nullptr;
    delete settingsButton; settingsButton = nullptr;
}