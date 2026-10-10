//
// Created by Ben Ho on 4/29/2023.
//

#ifndef OSUMANIA_NOTEPOOL_H
#define OSUMANIA_NOTEPOOL_H
#include "Note.h"
#include <SFML/System.hpp>
#include <iostream>
class NotePool {
    friend class playingScreen;
public:
    NotePool();
    NotePool(std::vector<sf::Sprite>& noteSprites, float timeBetweenNotes, int maxConsecutiveNotes, float noteProbability);
    void update(float deltaTime, float screenWidth, float screenHeight);
    void draw(sf::RenderWindow& window) const;
    std::vector <Note>& getActiveNotes();
    void setNoteSpeed(float noteSpeed);

private:
    std::vector<sf::Sprite> m_noteSprites;
    std::vector<Note> m_activeNotes;
    float noteTimer = 0.0f;
    float m_timeBetweenNotes;
    int m_consecutiveNotes = 0;
    int m_maxConsecutiveNotes;
    float m_noteProbability;
    float m_noteSpeed = 0.0f;

};


#endif //OSUMANIA_NOTEPOOL_H
