//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_BOUNCINGBALL_H
#define OSUMANIA_BOUNCINGBALL_H
#include "Component.h"


class BouncingBall:public Component {
private:
    sf::RenderTexture texture;
    sf::Text title;
    sf::CircleShape circle;
    float xSpeed, ySpeed;
public:
    BouncingBall();
    int Run(sf::RenderWindow &window) override;
    void setUp();
    void update();
};


#endif //OSUMANIA_BOUNCINGBALL_H
