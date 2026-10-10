//
// Created by hoben on 4/24/2023.
//

#ifndef OSUMANIA_PLAYINGSCREEN_H
#define OSUMANIA_PLAYINGSCREEN_H
#include "Component.h"
#include "Images.h"
#include "SoundEffect.h"
#include "ScoreSystem.h"
#include "GameOverScreen.h"

class playingScreen: public Component {
private:
    sf::Text timing;
    sf::Music HitSound,Song;
    std::vector<sf::Sprite> noteSprites;
    std::vector<sf::Sprite> receptor;
    sf::Sprite backGround;
    sf::Font font;
    sf::Clock timingClock;
    bool dKeyPressed = false;
    int Perfect = 0;
    int Great = 0;
    int Good = 0;
    int Miss = 0;
public:
    void eventHandler(NotePool& m_notePool, sf::Event& event, sf::Clock &clock);
    void setupNoteSprite();
    void setup();
    void setUpHitSound();
    void setupTiming();
    playingScreen();
    virtual int Run(sf::RenderWindow &window);
    void defaultUpdate(NotePool& notes);
    void update(NotePool& notes, sf::Clock &clock);
    int getPerfect() const;
    int getGreat() const;
    int getGood() const;
    int getMiss() const;
    friend class GameOverScreen;
};



#endif //OSUMANIA_PLAYINGSCREEN_H
