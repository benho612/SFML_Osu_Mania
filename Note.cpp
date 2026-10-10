//
// Created by Ben Ho on 4/27/2023.
//

#include <iostream>
#include "Note.h"
Note::Note(){
    //createNote();
}

Note::Note(float x, float y, float speed): m_x(x), m_y(y), speed_(speed),m_time(15) {
    //createNote();
}

Note::Note(sf::Sprite& sprite, float x, float y, float speed) : m_x(x), m_y(y), speed_(speed),m_time(15){
    note = sprite;
}

void Note::update(float deltaTime) {
    float ySpeed = speed_ * deltaTime;
    note.move(0.0f, ySpeed);
}

bool Note::isOnScreen(float screenHeight) const {
    return note.getPosition().y < screenHeight;
}

void Note::draw(sf::RenderWindow& window)const {
            window.draw(note);
}

Judgment Note::checkHit(const std::vector<sf::Sprite> &receptors, const sf::Time &currentTime) const {
    float timingDifference = std::abs(currentTime.asMilliseconds() - m_time);
    std::vector<sf::FloatRect> hitBox;
    for (int i = 0; i < receptors.size(); ++i) {
        hitBox.push_back(receptors[i].getGlobalBounds());
        hitBox[i].top -= hitBox[i].height / 2;
        hitBox[i].height *= 2;
    }
        if (hitBox[0].intersects(note.getGlobalBounds()) || hitBox[1].intersects(note.getGlobalBounds()) || hitBox[2].intersects(note.getGlobalBounds())
        || hitBox[3].intersects(note.getGlobalBounds()))
        {
            if (timingDifference <= PERFECT_THRESHOLD) {
                return Judgment::Perfect;
            } else if (timingDifference <= GREAT_THRESHOLD) {
                return Judgment::Great;
            } else if (timingDifference <= GOOD_THRESHOLD) {
                return Judgment::Good;
            }
        }
        else
        {
            return Judgment::Miss;
        }
}

bool Note::isOffReceptor() const {
    return note.getPosition().y > 950;
}







