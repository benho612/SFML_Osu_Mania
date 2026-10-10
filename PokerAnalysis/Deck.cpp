//
// Created by hoben on 3/21/2023.
//

#include "Deck.h"


Deck::Deck() {
    load();
    shuffle();
}

bool Deck::empty() const{
    if(cardIndex > DECK_SIZE)
        return true;
    return false;
}

void Deck::load() {
    int loadDeck = 0;
    for (auto & testSuit : testSuits) {
        for (auto & j : ranking) {
            deck[loadDeck] = PokerCard(testSuit,j);
            loadDeck++;
        }
    }
    cardIndex = 0;
}

void Deck::shuffle() {
    for (int i = 0; i < DECK_SIZE; ++i) {
        int random = rand()% DECK_SIZE;
        swap(deck[i], deck[random]);
    }
}

PokerCard Deck::dealCard() {
    int index = cardIndex;
    cardIndex++;
    return deck[index];
}

void Deck::swap(PokerCard &a, PokerCard &b) {
    PokerCard temp;
    temp = a;
    a = b;
    b = temp;
}

PokerCard Deck::getCardAt(int index) {
    return deck[index];
}

std::ostream &operator<<(std::ostream &out, const Deck &deck) {
    for (int i = 0; i < 52; ++i) {
        std::cout<<i<<": "<<deck.deck[i] <<std::endl;
    }
    return out;
}




