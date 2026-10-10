//
// Created by Ben Ho on 5/3/2023.
//

#include "PokerCard.h"


const std::vector<std::string> RankValue = {"Ace","Two","Three","Four","Five","Six","Seven"
        ,"Eight","Nine","Ten","Jack","Queen","King"};

PokerCard::PokerCard() {
    value = ACE;
    suit = HEARTS;
}

PokerCard::PokerCard(Pokersuits suit, PokerRanks string):suit(suit),value(string) {
}

std::string PokerCard::getSuit() const {
    switch(suit)
    {
        case DIAMONDS:
            return "Diamonds";
        case HEARTS:
            return "Hearts";
        case SPADES:
            return "Spades";
        case CLUBS:
            return "Clubs";
        default:
            exit(1);
    }
}

std::string PokerCard::getRank() const{

    return RankValue[value];
}

void PokerCard::setSuit(Pokersuits suit) {
    this->suit = suit;
}

void PokerCard::setRank(PokerRanks value) {
    this->value = value;
}

int PokerCard::getRankValue() const {
    switch(value){
        case PokerRanks::ACE:
            return 1;
        case PokerRanks::TWO:
            return 2;
        case PokerRanks::THREE:
            return 3;
        case PokerRanks::FOUR:
            return 4;
        case PokerRanks::FIVE:
            return 5;
        case PokerRanks::SIX:
            return 6;
        case PokerRanks::SEVEN:
            return 7;
        case PokerRanks::EIGHT:
            return 8;
        case PokerRanks::NINE:
            return 9;
        case PokerRanks::TEN:
            return 10;
        case PokerRanks::JACK:
            return 11;
        case PokerRanks::QUEEN:
            return 12;
        case PokerRanks::KING:
            return 13;
    }
}

int PokerCard::getSuitValue() const{
    switch(suit)
    {
        case DIAMONDS:
            return 1;
        case HEARTS:
            return 2;
        case SPADES:
            return 3;
        case CLUBS:
            return 4;
        default:
            exit(1);
    }
}

std::ostream &operator<<(std::ostream &out, const PokerCard &card) {
    std::cout <<card.getRank() << " of "<<card.getSuit();
    return out;
}





