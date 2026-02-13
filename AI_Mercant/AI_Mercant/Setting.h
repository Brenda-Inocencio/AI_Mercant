#ifndef SETTING
#define SETTING

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>

class Setting {


public:

    Setting();

    Setting(int _numberMerchants, int _numberMerchantsType);

    void Render(sf::RenderWindow& window);

    ~Setting();

    int numberMerchants;
    int numberMerchantsType;

private:
    sf::Texture* image;
    sf::Sprite* sprite;
};



#endif  
