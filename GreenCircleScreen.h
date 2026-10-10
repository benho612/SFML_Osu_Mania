//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_GREENCIRCLESCREEN_H
#define OSUMANIA_GREENCIRCLESCREEN_H
#include "Component.h"

class GreenCircleScreen:public Component {
private:
    sf::Text title;
    sf::CircleShape circle;
public:
    GreenCircleScreen();
    int Run(sf::RenderWindow &window) override;
    void setUp();
};


#endif //OSUMANIA_GREENCIRCLESCREEN_H
