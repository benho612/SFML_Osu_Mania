//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_SFMLCARD_H
#define OSUMANIA_SFMLCARD_H
#include "..\Component.h"
#include "PokerSuits.h"
#include "PokerRanks.h"
#include <vector>

class SfmlCard {
public:
private:
    sf::Sprite card;
    sf::IntRect intRect;
    static sf::Texture texture;
    void updateCard(PokerRanks rank, Pokersuits suit);
public:
    void setPosition(sf::Vector2f position);
    void setScale(sf::Vector2f position);
    SfmlCard();
    SfmlCard(PokerRanks rank, Pokersuits suit);
    void draw(sf::RenderTarget &window) const;
    int getWidth();
    int getHeight();
    int getLeft();
};


#endif //OSUMANIA_SFMLCARD_H
