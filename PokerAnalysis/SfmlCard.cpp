//
// Created by hoben on 3/29/2023.
//

#include "SfmlCard.h"
sf::Texture SfmlCard::texture;

void SfmlCard::draw(sf::RenderTarget &window) const {
    window.draw(card);
}

SfmlCard::SfmlCard() = default;

SfmlCard::SfmlCard(PokerRanks rank, Pokersuits suit) {
    texture.loadFromFile("Images/playingSprite.png");
    {
        card.setTexture(texture);
        intRect.width = 2925/13;
        intRect.height= 1260/4;
        updateCard(rank, suit);
    }
}

void SfmlCard::updateCard(PokerRanks rank, Pokersuits suit) {
    intRect.left = rank * intRect.width;
    intRect.top = suit  * intRect.height;
    card.setTextureRect(intRect);

}

void SfmlCard::setPosition(sf::Vector2f position) {
    card.setPosition(position);
}

void SfmlCard::setScale(sf::Vector2f position) {
    card.setScale(position);
}

int SfmlCard::getWidth() {
    return card.getGlobalBounds().width;
}

int SfmlCard::getHeight() {
    return card.getGlobalBounds().height;
}

int SfmlCard::getLeft() {
    return card.getGlobalBounds().left;
}





