//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_POKERRANKS_H
#define OSUMANIA_POKERRANKS_H

enum PokerRanks {
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
    //
};



namespace {
    std::vector<PokerRanks> ranking{
            PokerRanks::ACE, PokerRanks::TWO, PokerRanks::THREE, PokerRanks::FOUR, PokerRanks::FIVE,
            PokerRanks::SIX, PokerRanks::SEVEN, PokerRanks::EIGHT, PokerRanks::NINE, PokerRanks::TEN,
            PokerRanks::JACK, PokerRanks::QUEEN, PokerRanks::KING
    };
}


#endif //OSUMANIA_POKERRANKS_H
