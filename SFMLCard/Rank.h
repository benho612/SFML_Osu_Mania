//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_RANK_H
#define OSUMANIA_RANK_H
#include <SFML/Graphics.hpp>
#include "Ranks.h"
#include "Background.h"
#include "Font.h"
#include "Suit.h"

class Rank
{
private:
    sf::Text top, bottom;
public:
    Rank();
    Rank(Ranks rank);
    virtual void draw(sf::RenderTarget& window) const;
    void setSize(float size);
    void setFont();
    sf::Text &getTop();
    sf::Text &getBottom();
    static std::string getColor(Suits suit);
};


#endif //OSUMANIA_RANK_H
