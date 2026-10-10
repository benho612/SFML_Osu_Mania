//
// Created by Ben Ho on 4/3/2023.
//

#include "rowOfCard.h"

void rowOfCard::addCard(SfmlCard& card) {
    card.setScale({0.5f, 0.5f});

    if(rowsOfCard.empty())
    {
        card.setPosition({0,0});
        rowsOfCard.push_back(card);
        counter ++;
    }
    else if(!(rowsOfCard.empty()))
    {
        card.setPosition({static_cast<float>(x),static_cast<float>(y)});
        x += card.getWidth();
        rowsOfCard.push_back(card);
        counter ++;
    }

    if(counter % 5 == 0 && counter < 25)
    {
        y+= card.getHeight() + 20;
        x = 0;
    }
    else if(counter == 25)
    {
        y = 0;
        x = 1000;
    }
    else if(counter % 5 == 0 && counter > 26)
    {
        y+= card.getHeight() + 20;
        x = 1000;
    }
    else if(counter == 1)
    {
        x += card.getWidth();
    }

}

rowOfCard::rowOfCard() {
    rowRoyalFlush();
    rowStraightFlush();
    rowFourOfAKind();
    rowFullHouse();
    rowFlush();

    rowStraight();
    rowThreeOfAKind();
    rowTwoPair();
    rowOnePair();
    rowHighCard();
}

void rowOfCard::draw(sf::RenderTarget &window) const {
    for (const auto & i : rowsOfCard) {
        i.draw(window);
    }
}

void rowOfCard::rowRoyalFlush() {
    for (int i = 0; i < 5; ++i) {
        auto r = static_cast<PokerRanks>(TEN + i); auto s = static_cast<Pokersuits>(DIAMONDS);
        if(r <= static_cast<PokerRanks>(KING))
        {
            SfmlCard temp(r, s);
            addCard(temp);
        }
        else
        {
            SfmlCard temp(ACE, DIAMONDS);
            addCard(temp);
        }
    }
}

void rowOfCard::rowStraightFlush() {
    for (int i = 0; i < 5; ++i) {
        auto r = static_cast<PokerRanks>(ACE + i); auto s = static_cast<Pokersuits>(HEARTS);
        {
            SfmlCard temp(r, s);
            addCard(temp);
        }
    }
}

void rowOfCard::rowFourOfAKind() {
    for (int i = 0; i < 4; ++i) {
        auto r = static_cast<PokerRanks>(ACE); auto s = static_cast<Pokersuits>(rand() % 4);
        {
            SfmlCard temp(r, s);
            addCard(temp);
        }
    }
    SfmlCard temp(static_cast<PokerRanks>(rand() % 13), static_cast<Pokersuits>(rand() % 4));
    addCard(temp);
}

void rowOfCard::rowFullHouse() {
    for (int i = 0; i < 3; ++i) {
        auto r = static_cast<PokerRanks>(ACE); auto s = static_cast<Pokersuits>(rand() % 4);
        {
            SfmlCard temp(r, s);
            addCard(temp);
        }
    }
    for (int i = 0; i < 2; ++i) {
        auto r = static_cast<PokerRanks>(JACK); auto s = static_cast<Pokersuits>(rand() % 4);
        {
            SfmlCard temp(r, s);
            addCard(temp);
        }
    }
}

void rowOfCard::rowFlush() {
    for (int i = 0; i < 5; ++i) {
        auto r = static_cast<PokerRanks>(rand() % 13); auto s = static_cast<Pokersuits>(SPADES);
        {
            SfmlCard temp(r, s);
            addCard(temp);
        }
    }
}

void rowOfCard::rowStraight() {

    for (int i = 0; i < 5; ++i) {
        auto r = static_cast<PokerRanks>(ACE + i); auto s = static_cast<Pokersuits>(rand() % 4);
        {
            SfmlCard temp(r, s);
            addCard(temp);
        }
    }
}

void rowOfCard::rowThreeOfAKind() {
    for (int i = 0; i < 3; ++i) {
        auto r = static_cast<PokerRanks>(ACE); auto s = static_cast<Pokersuits>(rand() % 4);
        {
            SfmlCard temp(r, s);
            addCard(temp);
        }
    }
    for (int i = 0; i < 2; ++i) {
        auto r = static_cast<PokerRanks>(rand() % 12 + 1); auto s = static_cast<Pokersuits>(rand() % 4);
        {
            SfmlCard temp(r, s);
            addCard(temp);
        }
    }
}

void rowOfCard::rowTwoPair() {
    for (int i = 0; i < 2; ++i) {
        auto r = static_cast<PokerRanks>(ACE); auto s = static_cast<Pokersuits>(rand() % 4);
        {
            SfmlCard temp(r, s);
            addCard(temp);
        }
    }

    for (int i = 0; i < 2; ++i) {
        auto r = static_cast<PokerRanks>(TWO); auto s = static_cast<Pokersuits>(rand() % 4);
        {
            SfmlCard temp(r, s);
            addCard(temp);
        }
    }
    SfmlCard temp(static_cast<PokerRanks>(rand() % 13), static_cast<Pokersuits>(rand() % 4));
    addCard(temp);
}

void rowOfCard::rowOnePair() {
    for (int i = 0; i < 2; ++i) {
        auto r = static_cast<PokerRanks>(ACE); auto s = static_cast<Pokersuits>(rand() % 4);
        {
            SfmlCard temp(r, s);
            addCard(temp);
        }
    }
    for (int i = 0; i < 3; ++i) {
        auto r = static_cast<PokerRanks>(rand() % 13); auto s = static_cast<Pokersuits>(rand() % 4);
        {
            SfmlCard temp(r, s);
            addCard(temp);
        }
    }
}

void rowOfCard::rowHighCard() {
    SfmlCard a(ACE, DIAMONDS);
    SfmlCard b(THREE, CLUBS);
    SfmlCard c(FIVE, SPADES);
    SfmlCard d(SEVEN, HEARTS);
    SfmlCard e(KING, DIAMONDS);
    addCard(a);
    addCard(b);
    addCard(c);
    addCard(d);
    addCard(e);


}



