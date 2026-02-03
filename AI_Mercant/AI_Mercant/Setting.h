#ifndef SETTING
#define SETTING
#include <SFML/Graphics.hpp>

class Setting {
private:
    unsigned int width;
    unsigned int height;
    sf::RenderWindow window;
    sf::RectangleShape shape;

public:
    Setting();
    void setting();
    ~Setting();
};

#endif  