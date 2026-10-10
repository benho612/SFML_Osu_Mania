//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_IMAGES_H
#define OSUMANIA_IMAGES_H

#include <map>
#include "SFML/Graphics.hpp"
enum images{PHASER};

class Phaserimages {
private:
    static std::map<images, sf::Texture> textures;
    static std::string getPath(images image);
    static void load(images image);
public:
    static sf::Texture& getImage(images image);
};

#endif //OSUMANIA_IMAGES_H
