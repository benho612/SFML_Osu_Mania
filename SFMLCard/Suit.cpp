//
// Created by Dave R. Smith on 2/14/23.
//
#include "Suit.h"
Suit::Suit(Suits suit)
{
    sprite.setTexture(Images::getImage(suit));
}

Suit::Suit() {
}

void Suit::draw(sf::RenderTarget &window) const {
    window.draw(sprite);
}

sf::Sprite& Suit::getSprite() {
    return this->sprite;
}






