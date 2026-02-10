#ifndef MENUSTART
#define MENUSTART

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>

class MenuStart {
public:

	MenuStart();

	void Render(sf::RenderWindow& window);

	~MenuStart();

private:
	sf::Texture* image;
	sf::Sprite* sprite;
};

#endif
