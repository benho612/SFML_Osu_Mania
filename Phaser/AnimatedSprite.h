//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_ANIMATEDSPRITE_H
#define OSUMANIA_ANIMATEDSPRITE_H


#include "SFML/Graphics.hpp"
#include "..\Component.h"
#include "Images.h"
#include <iostream>
#include "States.h"
#include <cmath>

enum directions {FORWARD, LEFT, RIGHT, BACK};

class AnimatedSprite: public Component/*, public sf::Sprite*/, public States{
private:
    sf::Sprite sprite;
    sf::Clock clock;
    sf::IntRect intRect;
    int time = 250;
    void setup(sf::Texture& texture, int rows, int cols);
    void setupIntRect(sf::Vector2u imgSize, int rows, int cols);
    float width, height;
    float speed;
    sf::Keyboard::Key forwardKey = sf::Keyboard::Up, leftKey = sf::Keyboard::Left,
            rightKey = sf::Keyboard::Right, DownKey = sf::Keyboard::Down, Up, down, left, right;
    sf::Text title;

public:
    void setUp(sf::Keyboard::Key up);
    void setDown(sf::Keyboard::Key down);
    void setLeft(sf::Keyboard::Key left);
    void setRight(sf::Keyboard::Key right);
    void setForwardKey(sf::Keyboard::Key forwardKey);
    void setLeftKey(sf::Keyboard::Key leftKey);
    void setRightKey(sf::Keyboard::Key rightKey);
    void setDownKey(sf::Keyboard::Key downKey);
    float getSpeed() const;
    void setSpeed(float speed);
    int getTime() const;
    void setTime(int time);

    AnimatedSprite();
    AnimatedSprite(sf::Texture& texture, int rows, int cols);
    void animate();
    void update();
    void eventHandler(sf::RenderWindow &window, sf::Event event);
    void changeDirection(directions direction);
    virtual int Run(sf::RenderWindow &window);

protected:
    //void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};



#endif //OSUMANIA_ANIMATEDSPRITE_H
