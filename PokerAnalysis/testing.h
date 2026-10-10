//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_TESTING_H
#define OSUMANIA_TESTING_H
#include "rowOfCard.h"
#include "SfmlScore.h"
#include "..\Component.h"
class testing :public Component {
public:
    testing();
    int Run(sf::RenderWindow &window) override;
    void setUp();
private:
    sf::Text title;
};


#endif //OSUMANIA_TESTING_H
