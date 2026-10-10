//
// Created by Ben Ho on 4/29/2023.
//

#include "NotePool.h"

NotePool::NotePool() = default;

NotePool::NotePool(std::vector<sf::Sprite>& noteSprites, float timeBetweenNotes, int maxConsecutiveNotes, float noteProbability)
: m_noteSprites(noteSprites), m_timeBetweenNotes(timeBetweenNotes), m_maxConsecutiveNotes(maxConsecutiveNotes), m_noteProbability(noteProbability)
{
}

void NotePool::update(float deltaTime, float screenWidth, float screenHeight) {
    noteTimer += deltaTime;
    if (noteTimer >= m_timeBetweenNotes) {
        noteTimer = 0;
        int spriteIndex = std::rand() % m_noteSprites.size();
        float x = m_noteSprites[spriteIndex].getPosition().x;
        Note newNote(m_noteSprites[spriteIndex], x, 0.0f, m_noteSpeed);
        m_activeNotes.push_back(newNote);
        m_consecutiveNotes++;
        noteTimer = 0.0f;

            if (m_consecutiveNotes >= m_maxConsecutiveNotes) {
                m_noteProbability *= 0.5f; // Decrease the note probability to make it less likely that consecutive notes will continue to be dropped
                m_consecutiveNotes = 0;
            }
        }

        for (auto it = m_activeNotes.begin(); it != m_activeNotes.end();) {
            it->update(deltaTime);
            if (!it->isOnScreen(screenHeight)) {

                it = m_activeNotes.erase(it);
            }
            else{
                ++it;
            }
        }
    }

void NotePool::draw(sf::RenderWindow& window) const {

    for (const auto & note : m_activeNotes) {
        note.draw(window);
    }
}

std::vector<Note> &NotePool::getActiveNotes() {
    return m_activeNotes;
}

void NotePool::setNoteSpeed(float noteSpeed) {
    m_noteSpeed = noteSpeed;
}










