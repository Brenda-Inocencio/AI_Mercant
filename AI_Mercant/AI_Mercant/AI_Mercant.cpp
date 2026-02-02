#include <SFML/Graphics.hpp>
#include <optional>
#include "Shop.h"
#include "GameDay.h"
#include "HUD.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");

    // Load a sprite to display
    const sf::Texture texture("Background.png");
    sf::Sprite sprite(texture);


    // Cr�ation des rectangles
    sf::RectangleShape rect = Shop::createRectangle(175.f, 215.f, sf::Color::Yellow, { 0.f, 0.f });      
    
    sf::RectangleShape rect1 = Bakery::createRectangle(175.f, 215.f, sf::Color::Red, { 175.f, 0.f });

    sf::RectangleShape rect2 = ButcherShop::createRectangle(175.f, 215.f, sf::Color::Blue, { 450.f, 0.f });

    sf::RectangleShape rect3 = Coffee::createRectangle(175.f, 215.f, sf::Color::Cyan, { 625.f, 0.f });

    sf::RectangleShape rect4 = Pharmacy::createRectangle(175.f, 215.f, sf::Color::Green, { 0.f, 385.f });

    sf::RectangleShape rect5 = Coffee::createRectangle(175.f, 215.f, sf::Color::Cyan, { 175.f, 385.f });

    sf::RectangleShape rect6 = HairSalon::createRectangle(175.f, 215.f, sf::Color::Magenta, { 450.f, 385.f });

    sf::RectangleShape rect7 = Bakery::createRectangle(175.f, 215.f, sf::Color::Red, { 625.f, 385.f });

    HUD* hud = new HUD();

    // Start the game loop
    while (window.isOpen())
    {   
        // Process events
        while (const auto event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
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
        hud->Render(window, "jhg", 255, 255);
        

        // Update the window
        window.display();
    }
}