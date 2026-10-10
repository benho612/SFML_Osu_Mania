//
// Created by Dave R. Smith on 2/14/23.
//
#include "Rank.h"

const std::vector<std::string> Ranking = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

Rank::Rank(){
}

Rank::Rank(Ranks rank)
{
    top.setString(Ranking.at(rank));
    bottom.setString(Ranking.at(rank));
    setSize(70);
    setFont();
}

void Rank::draw(sf::RenderTarget& window) const{
    window.draw(top);
    window.draw(bottom);
}

void Rank::setSize(float size) {
    top.setCharacterSize(size);
    bottom.setCharacterSize(size);
}

void Rank::setFont() {
    top.setFont(Font::getFont());
    bottom.setFont(Font::getFont());
}

sf::Text &Rank::getTop() {
    return this->top;
}
sf::Text &Rank::getBottom() {
    return this->bottom;
}

std::string Rank::getColor(Suits suit) {
    switch(suit)
    {
        case HEART: return "HEARTS";
        case DIAMOND: return "DIAMONDS";
        case SPADE: return "SPADES";
        case CLUB: return "CLUBS";
    }
}



