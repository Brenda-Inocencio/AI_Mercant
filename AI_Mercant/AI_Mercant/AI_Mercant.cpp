#include <SFML/Graphics.hpp>
#include <optional>
#include "Shop.h"
#include "GameDay.h"
#include "HUD.h"
#include "Settings.h"
#include "button.h"
#include "MenuStart.h"
#include "MenuEnd.h"

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

    // Cr�ation des rectangles
    sf::RectangleShape rect = Shop::createRectangle(185.f, 215.f, sf::Color::Yellow, { 0.f, 0.f });      
    
    sf::RectangleShape rect1 = Bakery::createRectangle(185.f, 215.f, sf::Color::Red, { 185.f, 0.f });

    sf::RectangleShape rect2 = ButcherShop::createRectangle(185.f, 215.f, sf::Color::Blue, { 540.f, 0.f });

    sf::RectangleShape rect3 = Coffee::createRectangle(185.f, 215.f, sf::Color::Cyan, { 715.f, 0.f });

    sf::RectangleShape rect4 = Pharmacy::createRectangle(185.f, 215.f, sf::Color::Green, { 0.f, 385.f });

    sf::RectangleShape rect5 = Coffee::createRectangle(185.f, 215.f, sf::Color::Cyan, { 185.f, 385.f });

    sf::RectangleShape rect6 = HairSalon::createRectangle(185.f, 215.f, sf::Color::Magenta, { 540.f, 385.f });

    sf::RectangleShape rect7 = Bakery::createRectangle(185.f, 215.f, sf::Color::Red, { 715.f, 385.f });

    HUD* hud = new HUD();
    MenuStart* menustart = new MenuStart();
    MenuEnd* menuend = new MenuEnd();
    Button* exit = new Exit();
    Button* start = new Start();


    sf::Clock clock;
    float timer = 0.f;
    float dt = 0.0f;
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
                if (exit->GetPosX() <= static_cast<float>(mousePos.x) && exit->GetRightX() >= static_cast<float>(mousePos.x) &&
                    exit->GetPosY() <= static_cast<float>(mousePos.y) && exit->GetBottomY() >= static_cast<float>(mousePos.y)) {
                    window.close();
                }
                if (start->GetPosX() <= static_cast<float>(mousePos.x) && start->GetRightX() >= static_cast<float>(mousePos.x) &&
                    start->GetPosY() <= static_cast<float>(mousePos.y) && start->GetBottomY() >= static_cast<float>(mousePos.y)) {
                    //debut simulation
                }
            }
        }   

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        //Draw the rectangle
        window.draw(rect);
        window.draw(rect1);
        window.draw(rect2);
        window.draw(rect3);
        window.draw(rect4);
        window.draw(rect5);
        window.draw(rect6);
        window.draw(rect7);
        hud->Render(window, 0, 0.f); // 0 et 0.f a modifier representent respectivement le jour et le temps
        
        menustart->Render(window);
        //menuend->Render(window);

        //window.draw(sprite2);

        exit->Render(window);
        start->Render(window);

        // Update the window
        window.display();
    }
}