//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_IMAGES_H
#define OSUMANIA_IMAGES_H
#include <vector>
#include "Suits.h"
#include <SFML/Graphics.hpp>
#include <string>

class Images
{
private:
    static std::vector<sf::Texture> images;
    static std::string getPath(Suits suit);
    static void loadFile(Suits suit);
public:
    static sf::Texture& getImage(Suits suit);
};


#endif //OSUMANIA_IMAGES_H
