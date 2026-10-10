//
// Created by Ben Ho on 5/2/2023.
//

#ifndef OSUMANIA_GAMEOVERSCREEN_H
#define OSUMANIA_GAMEOVERSCREEN_H

#include "Component.h"
#include "playingScreen.h"
#include <sstream>
class GameOverScreen: public Component{
private:
    sf::Font font;
    sf::Text perfect, great, good, miss;
    int m_perfect, m_great,m_good,m_miss;
public:
    GameOverScreen(int i, int i1, int i2, int i3);
    void setup();
    int Run(sf::RenderWindow &window);
};


#endif //OSUMANIA_GAMEOVERSCREEN_H
