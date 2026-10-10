//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_ROWOFCARD_H
#define OSUMANIA_ROWOFCARD_H
#include "SfmlCard.h"

class rowOfCard {
private:
    int x = 0, y = 0;
    int counter = 0;
    std::vector<SfmlCard> rowsOfCard;
    void rowRoyalFlush();
    void rowStraightFlush();
    void rowFourOfAKind();
    void rowFullHouse();
    void rowFlush();
    void rowStraight();
    void rowThreeOfAKind();
    void rowTwoPair();
    void rowOnePair();
    void rowHighCard();
public:
    void draw(sf::RenderTarget &window) const;
    rowOfCard();
    void addCard(SfmlCard& card);
};


#endif //OSUMANIA_ROWOFCARD_H
