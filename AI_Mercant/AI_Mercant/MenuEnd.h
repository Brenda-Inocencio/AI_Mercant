#ifndef MENUEND
#define MENUSEND

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>

class MenuEnd {
public:

	MenuEnd();

	void Render(sf::RenderWindow& window);

	~MenuEnd();

private:
	sf::Texture* image;
	sf::Sprite* sprite;
};

#endif
