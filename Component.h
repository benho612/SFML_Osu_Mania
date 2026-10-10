//
// Created by hoben on 4/19/2023.
//

#ifndef SFMLTU_COMPONENT_H
#define SFMLTU_COMPONENT_H

#include <SFML/Graphics.hpp>
//#include "MouseEvents.h"
class Component/*: virtual public sf::Drawable*/{
public:
    //virtual void eventHandler(sf::RenderWindow &window, sf::Event event) = 0;
    virtual int Run (sf::RenderWindow &App) = 0;
    //virtual void draw(sf::RenderTarget &target, sf::RenderStates &states) const = 0;
    //virtual void update() = 0;

};


#endif //SFMLTU_COMPONENT_H
