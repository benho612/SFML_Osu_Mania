//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_BACKGROUND_H
#define OSUMANIA_BACKGROUND_H

#include <SFML/Graphics.hpp>
class Background
{
private:
    sf::RectangleShape rectangle;
public:
    void draw(sf::RenderTarget &window) const;
    Background();
    sf::RectangleShape& getRectangle();
    sf::FloatRect getPosition();
    void setPosition(float x, float y);
};


#endif //OSUMANIA_BACKGROUND_H
