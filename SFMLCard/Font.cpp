//
// Created by Ben Ho on 5/3/2023.
//

#include "Font.h"
sf::Font Font::font;

void Font::loadFont()
{
    font.loadFromFile("SFMLCard/OpenSans-Bold.ttf");
}

sf::Font& Font::getFont()
{
    loadFont();
    return font;
}