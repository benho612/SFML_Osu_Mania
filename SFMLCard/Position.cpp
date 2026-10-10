//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_POSITION_CPP
#define OSUMANIA_POSITION_CPP
#include "Position.h"

template <typename T, typename S>
void Position::center(const T& constObj, S& obj)
{
    sf::FloatRect bounds = constObj.getGlobalBounds();
    obj.setPosition({bounds.left + bounds.width/2 - obj.getGlobalBounds().width/2,
                     bounds.top + bounds.height/2 - obj.getGlobalBounds().height/2});
}
template <typename T, typename S>
void Position::topLeft(const T& constObj, S& obj)
{
    sf::FloatRect bounds = constObj.getGlobalBounds();
    obj.setPosition({bounds.left,bounds.top});
}

template <typename T, typename S>
void Position::bottomRight(const T& constObj, S& obj)
{
    sf::FloatRect bounds = constObj.getGlobalBounds();
    obj.setPosition({bounds.left+ bounds.width - obj.getGlobalBounds().width*2,
                     bounds.top + bounds.height - obj.getGlobalBounds().height*2});
}

#endif