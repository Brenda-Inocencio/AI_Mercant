#include "Game.h"
#include "Shop.h"
#include "HUD.h"

void Game::Render(sf::RenderWindow& window, std::vector<Shop*>& shops, HUD* hud) {
    for (int i = 0; i < shops.size(); i++) {
        shops[i]->Render(window);
    }
    hud->Render(window, 0, 0.f); // 0 et 0.f a modifier representent respectivement le jour et le temps
}

void Game::Update() {

}
