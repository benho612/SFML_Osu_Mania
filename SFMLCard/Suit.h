//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_SUIT_H
#define OSUMANIA_SUIT_H

#include <SFML/Graphics.hpp>
#include "Suits.h"
#include "Images.h"
class Suit
{
private:
    sf::Sprite sprite;
public:
    Suit();
    Suit(Suits suit);
    virtual void draw(sf::RenderTarget& window) const;
    sf::Sprite& getSprite();
};


#endif //OSUMANIA_SUIT_H
