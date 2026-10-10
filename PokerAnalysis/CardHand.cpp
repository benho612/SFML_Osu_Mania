//
// Created by hoben on 3/21/2023.
//

#include "CardHand.h"
CardHand::CardHand()
{
}

void CardHand::addCard(PokerCard card) {
    cardHand.push_back(card);
}

int CardHand::getSize() const {
    return cardHand.size();
}

PokerCard &CardHand::getHandCardAt(int index) {
    return cardHand[index];
}
int CardHand::getHandCardValueAt(int index) {
    return cardHand[index].getRankValue();
}

std::ostream& operator<<(std::ostream& out, const CardHand& cardHand){
    std::cout<<"Player has ";
    for (int i = 0; i < cardHand.getSize(); ++i) {
        std::cout<< cardHand.cardHand[i] << ", ";
    }
    return out;
}

