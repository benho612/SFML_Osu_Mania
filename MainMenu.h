//
// Created by hoben on 4/19/2023.
//

#ifndef SFMLTU_MAINMENU_H
#define SFMLTU_MAINMENU_H
#include "SFML/Graphics.hpp"
#include "Component.h"
#include "Images.h"
#include "MouseEvent.h"

class MainMenu: public Component {
private:
    int maxOptions = 2;
    int MainPressed;
    sf::Sprite background;
    sf::Sprite mainMenu[3];
    bool playing;
public:
    MainMenu();
    void setup();
    void setPosition();
    void MoveUp();
    void MoveDown();
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    virtual int Run(sf::RenderWindow &window);
protected:
    //void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFMLTU_MAINMENU_H
