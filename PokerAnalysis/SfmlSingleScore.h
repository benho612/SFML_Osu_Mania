//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_SFMLSINGLESCORE_H
#define OSUMANIA_SFMLSINGLESCORE_H

#include "SfmlCard.h"
#include "PokerScore.h"
#include <vector>

class SfmlSingleScore {
public:
    SfmlSingleScore();

    void setText();

    void setWord(const std::string &obj);

    void setPosition(sf::Vector2f position);

    void draw(sf::RenderTarget &window) const;

private:
    sf::Text text;
    static sf::Font font;
};
#endif //OSUMANIA_SFMLSINGLESCORE_H
