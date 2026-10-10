//
// Created by hoben on 4/24/2023.
//

#include "playingScreen.h"
playingScreen::playingScreen() {
    setup();
    setupNoteSprite();
    setUpHitSound();
    setupTiming();
}

int playingScreen::Run(sf::RenderWindow &window)
{
    NotePool notePool(noteSprites, 0.3f, 4, 1.0f);
    notePool.setNoteSpeed(600.0f);
    Song.play();
    float songDuration = Song.getDuration().asSeconds();
    sf::Clock clock,timer;
    while (window.isOpen())
    {
        if (timer.getElapsedTime().asSeconds() >= songDuration) {
            return (3);
        }
        sf::Event Event;
        eventHandler(notePool,Event, clock);
        while (window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                return (-1);
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                    case sf::Keyboard::Escape:
                        Song.pause();
                        return (0);
                    default:
                        break;
                }
            }
        }
        timingClock.restart();
        if (timingClock.getElapsedTime().asSeconds() > 3.f) {
            timing.setString(""); // clear the text
        }
        defaultUpdate(notePool);
        float deltaTime = clock.restart().asSeconds();
        notePool.update(deltaTime, 1920.0f, 1080.0f);
        window.clear();
        window.draw(backGround);
        for (const auto & i : receptor) {
            window.draw(i);
        }
        notePool.draw(window);
        window.draw(timing);
        window.display();
    }
    return -1;
}

void playingScreen::setupTiming() {
    font.loadFromFile("Fonts/varsity_regular.ttf");
    timing.setFont(font);
    timing.setPosition(1060,640);
}

void playingScreen::setup() {

    sf::Sprite leftReceptor;
    leftReceptor.setTexture(Images::getImage(RECEPTORLEFT));
    leftReceptor.setPosition(300,900);
    receptor.push_back(leftReceptor);

    sf::Sprite downReceptor;
    downReceptor.setTexture(Images::getImage(RECEPTORDOWN));
    downReceptor.setPosition(400,900);
    receptor.push_back(downReceptor);

    sf::Sprite rightReceptor;
    rightReceptor.setTexture(Images::getImage(RECEPTORRIGHT));
    rightReceptor.setPosition(500,900);
    receptor.push_back(rightReceptor);

    sf::Sprite UpReceptor;
    UpReceptor.setTexture(Images::getImage(RECEPTORUP));
    UpReceptor.setPosition(600,900);
    receptor.push_back(UpReceptor);

    backGround.setTexture(Images::getImage(ANIMA));
    backGround.setScale(1.9,1.8);

    sf::Color color = backGround.getColor();
    color.a = 128;
    backGround.setColor(color);

}

void playingScreen::eventHandler(NotePool& m_notePool, sf::Event& event, sf::Clock &clock) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&& !dKeyPressed) {
        HitSound.play();
        update(m_notePool, clock);
        receptor[0].setTexture(Images::getImage(RECEPTORLEFTTAP));
        dKeyPressed = true;
    } if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)&& !dKeyPressed) {
        HitSound.play();
        update(m_notePool, clock);
        receptor[1].setTexture(Images::getImage(RECEPTORDOWNTAP));
        dKeyPressed = true;
    } if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)&& !dKeyPressed) {
        HitSound.play();
        update(m_notePool, clock);
        receptor[2].setTexture(Images::getImage(RECEPTORRIGHTTAP));
        dKeyPressed = true;
    } if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)&& !dKeyPressed) {
        HitSound.play();
        update(m_notePool, clock);
        receptor[3].setTexture(Images::getImage(RECEPTORUPTAP));
        dKeyPressed = true;
    }

    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D) {
        HitSound.stop();
        receptor[0].setTexture(Images::getImage(RECEPTORLEFT));
        dKeyPressed = false;
    }
    else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::F) {
        HitSound.stop();
        receptor[1].setTexture(Images::getImage(RECEPTORDOWN));
        dKeyPressed = false;
    }
    else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::J) {
        HitSound.stop();
        receptor[2].setTexture(Images::getImage(RECEPTORRIGHT));
        dKeyPressed = false;
    }
    else if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::K) {
        HitSound.stop();
        receptor[3].setTexture(Images::getImage(RECEPTORUP));
        dKeyPressed = false;
    }
}

void playingScreen::setupNoteSprite() {
    for (int i = 3; i <= 6; i++) {
        sf::Sprite noteSprite;
        int x = i * 100;
        noteSprite.setTexture(Images::getImage(static_cast<images>(x)));
        noteSprite.setPosition(static_cast<float>(x), -10);
        noteSprites.push_back(noteSprite);
    }
}

void playingScreen::setUpHitSound() {
    Song.openFromFile(SoundEffect::getPath(ANIMAS));
    Song.setVolume(20);
    HitSound.openFromFile(SoundEffect::getPath(HITDRUM));
    HitSound.setVolume(10);
}

void playingScreen::update(NotePool& m_notePool, sf::Clock& clock) {
    sf::Time currentTime = clock.getElapsedTime();
    if (!m_notePool.getActiveNotes().empty())
    {
        auto it = m_notePool.getActiveNotes().begin();
        auto hitResult = (*it).checkHit(receptor, currentTime);
        if (hitResult == Judgment::Perfect)
        {
            timing.setString(ScoreSystem::setString(hitResult));
            Perfect++;
            std::cout << "Perfect " << Perfect << std::endl;
            m_notePool.getActiveNotes().erase(it);
            ++it;
        }
        else if (hitResult == Judgment::Great)
        {
            timing.setString(ScoreSystem::setString(hitResult));
            std::cout << "Great " << Great << std::endl;
            Great++;
            m_notePool.getActiveNotes().erase(it);
            ++it;
        }
        else if (hitResult == Judgment::Good)
        {
            timing.setString(ScoreSystem::setString(hitResult));
            std::cout << "Good " << Good << std::endl;
            Good++;
            m_notePool.getActiveNotes().erase(it);
            ++it;
        }
            /*else if (hitResult == Judgment::Miss)
            {
                timing.setString(ScoreSystem::setString(hitResult));
                std::cout << "Miss" << Miss << std::endl;
                Miss++;
            }*/
    }
}

void playingScreen::defaultUpdate(NotePool &notes) {
    for (auto it = notes.getActiveNotes().begin(); it != notes.getActiveNotes().end();) {
            if(it->isOffReceptor())
            {
                timing.setString(ScoreSystem::setString(Judgment::Miss));
                std::cout << "Miss " << Miss << std::endl;
                Miss++;
                it = notes.getActiveNotes().erase(it);
            }
            else
            {
                ++it;
            }
    }
}

int playingScreen::getPerfect() const {
    return Perfect;
}

int playingScreen::getGreat() const {
    return Great;
}

int playingScreen::getGood() const {
    return Good;
}

int playingScreen::getMiss() const {
    return Miss;
}






