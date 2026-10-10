//
// Created by Ben Ho on 4/27/2023.
//

#ifndef OSUMANIA_NOTE_H
#define OSUMANIA_NOTE_H
#include <SFML/Graphics.hpp>
#include "Images.h"
#include <vector>
#include "Judgment.h"
//const float TEMPO = 480.0f; // beats per minute
const float PERFECT_THRESHOLD = 0 ;
const float GOOD_THRESHOLD = 1.5f ;
const float GREAT_THRESHOLD = 2.0f ;


class Note {
public:
    Note();
    Note(float x, float y, float speed);
    Note(sf::Sprite& sprite, float x, float y, float speed);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window) const;
    bool isOnScreen(float screenHeight) const;
    bool isOffReceptor() const;
    Judgment checkHit(const std::vector<sf::Sprite>& receptors, const sf::Time& currentTime) const;
private:
    sf::Sprite note;
    float speed_ , m_x, m_y;
    int m_time;
};



#endif //OSUMANIA_NOTE_H
