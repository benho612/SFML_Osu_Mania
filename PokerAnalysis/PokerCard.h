//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_POKERCARD_H
#define OSUMANIA_POKERCARD_H
#include <iostream>
#include "PokerSuits.h"
#include "PokerRanks.h"

class PokerCard {
public:
    Pokersuits suit;
    PokerRanks value;
    std::string getSuit()const;
    std::string getRank()const;
    void setSuit(Pokersuits suit);
    void setRank(PokerRanks value);
    friend std::ostream& operator<<(std::ostream& out, const PokerCard& card);
    PokerCard(Pokersuits suit, PokerRanks string);
    PokerCard();
    int getRankValue() const;
    int getSuitValue() const;
};


#endif //OSUMANIA_POKERCARD_H
