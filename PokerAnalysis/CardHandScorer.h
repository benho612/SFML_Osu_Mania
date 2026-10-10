//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_CARDHANDSCORER_H
#define OSUMANIA_CARDHANDSCORER_H

#include <ostream>
#include "PokerScore.h"

class CardHandScorer {

public:
    static void sort(CardHand& hand);
    static void swap(PokerCard& card1, PokerCard& card2);
    static PokerScore scorePokerHand(CardHand hand);
};


#endif //OSUMANIA_CARDHANDSCORER_H
