#include <SFML/Graphics.hpp>
#include <optional>

#include "Shop.h"
#include "button.h"

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");

    // Load a sprite to display
    const sf::Texture texture("Background.png");
    sf::Sprite sprite(texture);

   /* // Taille originale de l'image
    sf::Vector2u originalSize = texture.getSize();
    std::cout << "Taille originale : " << originalSize.x << "x" << originalSize.y << "\n";*/


    // Cr�ation des rectangles
    sf::RectangleShape rect = Shop::createRectangle(175.f, 215.f, sf::Color::Yellow, { 0.f, 0.f });      // Shop -> Shop of clothes
    
    sf::RectangleShape rect1 = Bakery::createRectangle(175.f, 215.f, sf::Color::Red, { 175.f, 0.f });

    sf::RectangleShape rect2 = ButcherShop::createRectangle(175.f, 215.f, sf::Color::Blue, { 450.f, 0.f });

    sf::RectangleShape rect3 = Coffee::createRectangle(175.f, 215.f, sf::Color::Cyan, { 625.f, 0.f });

    sf::RectangleShape rect4 = Pharmacy::createRectangle(175.f, 215.f, sf::Color::Green, { 0.f, 385.f });

    sf::RectangleShape rect5 = Coffee::createRectangle(175.f, 215.f, sf::Color::Cyan, { 175.f, 385.f });

    sf::RectangleShape rect6 = HairSalon::createRectangle(175.f, 215.f, sf::Color::Magenta, { 450.f, 385.f });

    sf::RectangleShape rect7 = Bakery::createRectangle(175.f, 215.f, sf::Color::Red, { 625.f, 385.f });

    Button* exit = new Exit;
    Button* start = new Start;

    // Start the game loop
    while (window.isOpen()) {   
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
        exit->Render(window);
        start->Render(window);

        // Update the window
        window.display();
    }
}