//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_CARD_H
#define OSUMANIA_CARD_H
#include "..\Component.h"
#include "Background.h"
#include "Rank.h"
#include "Position.h"
#include "Suit.h"
#include <SFML/Graphics.hpp>
class Card: public Component
{
private:
    sf::Text title;
    Background background;
    Rank rank;
    Suit suit;
    float width, height;
public:
    Card();
    Card(Ranks rank, Suits suit);
    void setRectPosition();
    void update();
    void setColor(Suits color);
    void setUp();
    int Run(sf::RenderWindow &window) override;


};


#endif //OSUMANIA_CARD_H
