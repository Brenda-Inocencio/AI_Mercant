#ifndef SETTING
#define SETTING

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>

class Setting {
public:

    Setting();

    void Render(sf::RenderWindow& window);

    ~Setting();

private:
    sf::Texture* image;
    sf::Sprite* sprite;
};

#endif  