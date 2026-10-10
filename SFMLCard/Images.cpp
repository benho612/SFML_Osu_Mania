//
// Created by Dave R. Smith on 2/14/23.
//

#include "Images.h"

std::vector<sf::Texture> Images::images(LAST_SUIT, sf::Texture());

std::string Images::getPath(Suits suit)
{
    switch(suit)
    {
        case HEART: return "SFMLCard/suits/heart.png";
        case DIAMOND: return "SFMLCard/suits/diamonds.png";
        case SPADE: return "SFMLCard/suits/spades.png";
        case CLUB: return "SFMLCard/suits/club.png";
        case LAST_SUIT:
            break;
    }
}

void Images::loadFile(Suits suit)
{
    images[suit].loadFromFile(getPath(suit));
}

sf::Texture& Images::getImage(Suits suit)
{
    loadFile(suit);
    return images[suit];
}
