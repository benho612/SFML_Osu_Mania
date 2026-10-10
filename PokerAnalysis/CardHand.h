//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_CARDHAND_H
#define OSUMANIA_CARDHAND_H
#include "Deck.h"


class CardHand {
private:
    std::vector<PokerCard> cardHand;
public:
    CardHand();
    void addCard(PokerCard card);
    friend std::ostream& operator<<(std::ostream& out, const CardHand& cardHand);
    int getSize() const ;
    PokerCard& getHandCardAt(int index);
    int getHandCardValueAt(int index);
};


#endif //OSUMANIA_CARDHAND_H
