//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_POSITION_H
#define OSUMANIA_POSITION_H

#include <SFML/Graphics.hpp>

class Position{
public:
    template <typename T, typename S>
    static void center(const T& constObj, S& obj);

    template <typename T, typename S>
    static void topLeft(const T& constObj, S& obj);

    template <typename T, typename S>
    static void bottomRight(const T& constObj, S& obj);
};
#include "Position.cpp"


#endif //OSUMANIA_POSITION_H
