//
// Created by hoben on 3/21/2023.
//

#include "CardHandScorer.h"

void CardHandScorer::sort(CardHand &cardHand) {
    bool swapped;
    for(int i=0;i<cardHand.getSize();i++){
        swapped=false;
        for(int j=0;j<cardHand.getSize()-1;j++){
            if (cardHand.getHandCardValueAt(j) > cardHand.getHandCardValueAt(j + 1)) {
                swap(cardHand.getHandCardAt(j), cardHand.getHandCardAt(j + 1));
                swapped=true;
            }
        }
        if(!swapped)
            break;
    }
}

void CardHandScorer::swap(PokerCard &card1, PokerCard &card2) {
    PokerCard temp;
    temp=card1;
    card1=card2;
    card2 =temp;
}

PokerScore CardHandScorer::scorePokerHand(CardHand hand) {
    PokerScore score;
    CardHandScorer::sort(hand);
    if(PokerScore::hasRoyalFlush(hand))
        score.addScore(PokerScore::ROYAL_FLUSH);
    if(PokerScore::hasStraightFlush(hand))
        score.addScore(PokerScore::STRAIGHT_FLUSH);
    if(PokerScore::hasFourOfAKind(hand))
        score.addScore(PokerScore::FOUR_OF_A_KIND);
    if(PokerScore::hasFullHouse(hand))
        score.addScore(PokerScore::FULL_HOUSE);
    if(PokerScore::hasFlush(hand))
        score.addScore(PokerScore::FLUSH);
    if(PokerScore::hasStraight(hand))
        score.addScore(PokerScore::STRAIGHT);
    if(PokerScore::hasThreeOfAKind(hand))
        score.addScore(PokerScore::THREE_OF_A_KIND);
    if(PokerScore::hasTwoPair(hand))
        score.addScore(PokerScore::TWO_PAIR);
    if(PokerScore::hasOnePair(hand))
        score.addScore(PokerScore::ONE_PAIR);
    if(PokerScore::hasHighCard(hand))
        score.addScore(PokerScore::HIGH_CARD);
    return score;
}





