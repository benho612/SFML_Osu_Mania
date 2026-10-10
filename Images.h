//
// Created by hoben on 4/19/2023.
//

#ifndef OSUMANIA_IMAGES_H
#define OSUMANIA_IMAGES_H
#include "SFML/Graphics.hpp"
#include <map>
enum images {OPTIONS,EXIT,START,BACKGROUND,RESOLUTION,SOUND,
        ARROWLEFT=300,ARROWDOWN=400,ARROWRIGHT=500,ARROWUP=600,
        RECEPTORLEFT,RECEPTORDOWN,RECEPTORUP,RECEPTORRIGHT,
        RECEPTORLEFTTAP,RECEPTORDOWNTAP,RECEPTORUPTAP,RECEPTORRIGHTTAP,
        ANIMA};
class Images {

private:
    static std::map<images, sf::Texture> textures;
    static std::string getPath(images image);
    static void load(images image);
public:
    static sf::Texture& getImage(images image);
};


#endif //OSUMANIA_IMAGES_H
