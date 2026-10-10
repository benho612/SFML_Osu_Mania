//
// Created by hoben on 4/24/2023.
//

#ifndef SFMLTU_OPTIONSCREEN_H
#define SFMLTU_OPTIONSCREEN_H

#include "Component.h"
#include "Images.h"
#include "MainMenu.h"
class OptionScreen:public Component {
public:
    OptionScreen();
    void setup();
    virtual int Run(sf::RenderWindow &window);
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    void moveOption();
private:
    int maxOptions = 2;
    int Pressed = 1;
    sf::Sprite resolution;
    sf::Sprite volume;
    sf::Sprite backGround;
};


#endif //SFMLTU_OPTIONSCREEN_H
