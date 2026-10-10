//
// Created by hoben on 4/19/2023.
//

#ifndef OSUMANIA_SOUNDEFFECT_H
#define OSUMANIA_SOUNDEFFECT_H
#include "SFML/Audio.hpp"
#include <map>

enum soundEnum{DADA,HITDRUM,ANIMAS,HARUMACHI};

class SoundEffect {
private:
    static std::map<soundEnum, sf::Music> soundMap;
    static void load(soundEnum sound);
public:
    static std::string getPath(soundEnum sound);
    static sf::Music& getAudio(soundEnum sound);
};


#endif //OSUMANIA_SOUNDEFFECT_H
