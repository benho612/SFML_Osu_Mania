//
// Created by Ben Ho on 5/3/2023.
//

#include "PokerScore.h"
//
// Created by hoben on 3/21/2023.
//

#include "PokerScore.h"


PokerScore::PokerScore() = default;

PokerScore::Scores &PokerScore::operator[](unsigned int index) {
    return scores[index];
}

int PokerScore::size() const{
    return scores.size();
}

bool PokerScore::hasRoyalFlush(CardHand sortedHand) {
    for (int i=0; i<sortedHand.getSize()-1; i++) {
        if (sortedHand.getHandCardAt(i).getSuit() != sortedHand.getHandCardAt(i + 1).getSuit()) {
            return false;
        }
    }

    if(sortedHand.getHandCardAt(0).getRankValue() != PokerRanks::ACE+1)
    {
        return false;
    }

    for(int i=1;i<sortedHand.getSize();i++) {
        if (sortedHand.getHandCardAt(i).getRankValue() != i+9)
            return false;
    }
    return true;
}

bool PokerScore::hasStraightFlush(const CardHand& sortedHand){
    return hasStraight(sortedHand) && hasFlush(sortedHand);
}

bool PokerScore::hasFourOfAKind(CardHand sortedHand) {
    int tracker = 0;
    for (int i = 0; i < 2; i++)
        if (sortedHand.getHandCardAt(i).getRankValue() != sortedHand.getHandCardAt(i + 3).getRankValue())
            tracker++;

    return (tracker == 1);
}

bool PokerScore::hasFullHouse(CardHand sortedHand) {
// has to check either to see if first 2 are pair then if rest 3 are 3 of kind.
//case 1 : Pairs then set of 3
// Checks to see if its a pair and not a 3 of a kind
    if(sortedHand.getHandCardAt(0).getRankValue()==sortedHand.getHandCardAt(1).getRankValue()&&
       sortedHand.getHandCardAt(0).getRankValue()!=sortedHand.getHandCardAt(2).getRankValue()){
// now check for 3 of a kind.
        if(hasThreeOfAKind(sortedHand))
            return true;
    }
//case 2: 3 of a kind then a pair
// checks for 3 of a kind first
    if(sortedHand.getHandCardAt(0).getRankValue()==sortedHand.getHandCardAt(1).getRankValue()&&
       sortedHand.getHandCardAt(0).getRankValue()==sortedHand.getHandCardAt(2).getRankValue()){
// now check for pair
        if(sortedHand.getHandCardAt(3).getRankValue()==sortedHand.getHandCardAt(4).getRankValue())
            return true;
    }
    return false;
}

bool PokerScore::hasFlush(CardHand sortedHand) {
    for(int i=0;i<sortedHand.getSize()-1;i++) {
        if (sortedHand.getHandCardAt(i).getSuit()!=sortedHand.getHandCardAt(i+1).getSuit())
            return false;
    }
    return true;
}

bool PokerScore::hasStraight(CardHand sortedHand) {
    for(int i=0;i<sortedHand.getSize()-1;i++) {
        if (sortedHand.getHandCardAt(i).getRankValue()!=sortedHand.getHandCardAt(i+1).getRankValue()-1)
            return false;
    }
    return true;
}

bool PokerScore::hasThreeOfAKind(CardHand sortedHand) {
// save some time
    if(!hasOnePair(sortedHand))
        return false;
// check first set
    if(sortedHand.getHandCardAt(0).getRankValue()==sortedHand.getHandCardAt(1).getRankValue()&&
       sortedHand.getHandCardAt(0).getRankValue()==sortedHand.getHandCardAt(2).getRankValue())
        return true;
// check set set
    if(sortedHand.getHandCardAt(1).getRankValue()==sortedHand.getHandCardAt(2).getRankValue()&&
       sortedHand.getHandCardAt(1).getRankValue()==sortedHand.getHandCardAt(3).getRankValue())
        return true;
// check third set
    if(sortedHand.getHandCardAt(2).getRankValue()==sortedHand.getHandCardAt(3).getRankValue()&&
       sortedHand.getHandCardAt(2).getRankValue()==sortedHand.getHandCardAt(3).getRankValue())
        return true;


    return false;
}

bool PokerScore::hasTwoPair(CardHand sortedHand) {
    int tracker=0;
    if(hasThreeOfAKind(sortedHand))
        return false;
    for(int i=0;i<sortedHand.getSize()-1;i++){
        if(sortedHand.getHandCardAt(i).getRankValue()==sortedHand.getHandCardAt(i+1).getRankValue()) {
            tracker++;
        }
    }

    return (tracker==2);
}

bool PokerScore::hasOnePair(CardHand sortedHand) {
    for(int i=0;i<sortedHand.getSize()-1;i++){
        if(sortedHand.getHandCardAt(i).getRankValue()==sortedHand.getHandCardAt(i+1).getRankValue())
            return true;
    }
    return false;
}

bool PokerScore::hasHighCard(const CardHand& sortedHand) {
    if(sortedHand.getSize()>0)
        return true;
}

void PokerScore::addScore(PokerScore::Scores score) {
    scores.push_back(score);
}

bool operator==(const PokerScore &p, PokerScore::Scores score) {
    for(int i=0;i<p.size();i++){
        if(p.getScoreAt(i)==score)
            return true;
    }
}

PokerScore::Scores PokerScore::getScoreAt(int index) const{
    return scores[index];
}

void PokerScore::operator+=(const PokerScore& score) {
    for(int i=0;i<score.size();i++){
        this->addScore(score.getScoreAt(i));
    }

}

std::ostream &operator<<(std::ostream &out,const PokerScore &score) {
    int RoyalFlush=0,StraightFlush=0,FourOfAKind=0,FullHouse=0,Flush=0,Straight=0,ThreeOfAKind=0,TwoPair=0,OnePair=0,HighCard=0;
    for(int i=0;i<score.size();i++)
        switch(score.getScoreAt(i)) {
            case PokerScore::ROYAL_FLUSH:
                RoyalFlush++;
                break;
            case PokerScore::STRAIGHT_FLUSH:
                StraightFlush++;
                break;
            case PokerScore::FOUR_OF_A_KIND:
                FourOfAKind++;
                break;
            case PokerScore::FULL_HOUSE:
                FullHouse++;
                break;
            case PokerScore::FLUSH:
                Flush++;
                break;
            case PokerScore::STRAIGHT:
                Straight++;
                break;
            case PokerScore::THREE_OF_A_KIND:
                ThreeOfAKind++;
                break;
            case PokerScore::TWO_PAIR:
                TwoPair++;
                break;
            case PokerScore::ONE_PAIR:
                OnePair++;
                break;
            case PokerScore::HIGH_CARD:
                HighCard++;
                break;
        };
    out <<"Royal Flush: " << RoyalFlush << std::endl
        << "Straight Flush: " << StraightFlush <<std::endl
        << "Four of a Kind: "<< FourOfAKind <<std::endl
        << "Full House: "<< FullHouse <<std::endl
        << "Flush: " << Flush <<std::endl
        << "Straight: "<< Straight <<std::endl
        << "Three of a Kind: "<<ThreeOfAKind <<std::endl
        << "Two Pair: "<< TwoPair <<std::endl
        << "One Pair: "<< OnePair <<std::endl
        << "High Card: "<< HighCard <<std::endl;
    return out;
}

void PokerScore::PokerAnaylsis(const PokerScore &score) {
    for(int i=0;i<score.size();i++)
        switch(score.getScoreAt(i)) {
            case PokerScore::ROYAL_FLUSH:
                RoyalFlush++;
                break;
            case PokerScore::STRAIGHT_FLUSH:
                StraightFlush++;
                break;
            case PokerScore::FOUR_OF_A_KIND:
                FourOfAKind++;
                break;
            case PokerScore::FULL_HOUSE:
                FullHouse++;
                break;
            case PokerScore::FLUSH:
                Flush++;
                break;
            case PokerScore::STRAIGHT:
                Straight++;
                break;
            case PokerScore::THREE_OF_A_KIND:
                ThreeOfAKind++;
                break;
            case PokerScore::TWO_PAIR:
                TwoPair++;
                break;
            case PokerScore::ONE_PAIR:
                OnePair++;
                break;
            case PokerScore::HIGH_CARD:
                HighCard++;
                break;
        };
}



