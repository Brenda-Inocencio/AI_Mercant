#include "Button.h"

Exit::Exit() {
    pos = sf::Vector2<float>(300.f, 275.f);
    shape.setPosition(pos);
    shape.setSize({width, height});
    shape.setFillColor(idleColor);

}
