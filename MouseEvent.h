//
// Created by hoben on 4/20/2023.
//

#ifndef SFMLTU_MOUSEEVENT_H
#define SFMLTU_MOUSEEVENT_H
#include "SFML/Graphics.hpp"

class MouseEvent {
public:
    template<typename T>
    static bool isHovered(T&obj, sf::RenderWindow&window);

    template<typename T>
    static bool isClicked(T&obj, sf::RenderWindow&window);
private:

};


#endif //SFMLTU_MOUSEEVENT_H
