//
// Created by hoben on 4/20/2023.
//

#ifndef SFMLTU_MOUSEEVENT_CPP
#define SFMLTU_MOUSEEVENT_CPP
#include "MouseEvent.h"

template<typename T>
bool MouseEvent::isHovered(T &obj, sf::RenderWindow &window) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return obj.getGlobalBounds().contains(mpos);
}

template<typename T>
bool MouseEvent::isClicked(T &obj, sf::RenderWindow &window) {
    return isHovered(obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

#endif