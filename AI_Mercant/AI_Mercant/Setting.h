#ifndef SETTING
#define SETTING

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>

class Setting {

    int numberMerchants;
    int numberMerchantsType;

public:

    Setting();

    Setting(int _numberMerchants, int _numberMerchantsType);

    void Render(sf::RenderWindow& window);

    ~Setting();

    inline int GetNumberMerchants() { return numberMerchants; }
    inline int GetNumberMerchantsType() { return numberMerchantsType; }

private:
    sf::Texture* image;
    sf::Sprite* sprite;
};



#endif  
