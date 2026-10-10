//
// Created by hoben on 4/19/2023.
//

#include "SoundEffect.h"

std::map<soundEnum, sf::Music> SoundEffect::soundMap;

std::string SoundEffect::getPath(soundEnum sound) {
    switch(sound)
    {

        case DADA: return "Songs/DaDaDaDaDaDaDaDaDaDa/DaDaDaDaDaDaDaDaDaDa.ogg";
            break;
        case HITDRUM: return "Songs/drum-hitnormal.wav";
            break;
        case ANIMAS: return "Songs/359191 xi - ANiMA/ANiMA.ogg";
            break;
        case HARUMACHI: return "Songs/Harumachi-Your-Mother.ogg";
            break;
    }
    return std::string();
}

void SoundEffect::load(soundEnum sound) {
    soundMap[sound].openFromFile(getPath(sound));
}

sf::Music &SoundEffect::getAudio(soundEnum sound) {
    load(sound);
    return soundMap[sound];
}
