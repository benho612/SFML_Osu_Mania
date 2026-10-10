//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_FONT_H
#define OSUMANIA_FONT_H
#include <SFML/Graphics.hpp>


class Font
{
private:
    static sf::Font font;
    static void loadFont();

public:
    static sf::Font& getFont();
};


#endif //OSUMANIA_FONT_H
