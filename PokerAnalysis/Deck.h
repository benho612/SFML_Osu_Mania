//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_DECK_H
#define OSUMANIA_DECK_H
#include "PokerCard.h"

class Deck {
private:
    void load();
    PokerCard deck[52];// this is your final deck of cards
public:
    Deck(); // this is the constructor
    const int DECK_SIZE = 52;// this is the size of your deck
    bool empty() const; //returns true if deck has no cards
    int cardIndex; //marks the index of the next card in the deck
    void shuffle(); // puts cards in random order
    PokerCard dealCard(); // returns the next card in the deck
    PokerCard getCardAt(int index);// gets the Card at the given index
    void swap(PokerCard& a,PokerCard&b);
    friend std::ostream& operator<<(std::ostream& out, const Deck& deck); // prints all the cards to the console
};


#endif //OSUMANIA_DECK_H
