//
// Created by hoben on 4/19/2023.
//

#ifndef OSUMANIA_APPLICATION_H
#define OSUMANIA_APPLICATION_H

#include <SFML/Graphics.hpp>
#include "Component.h"
#include <vector>

class Application:public Component {
private:
    static sf::RenderWindow window;
    static std::vector<Component*> Screens;
public:
    static void addComponents(Component& component);
    static void run();
};


#endif //OSUMANIA_APPLICATION_H
