//
// Created by hoben on 4/10/2023.
//

#include "Images.h"

std::map<images, sf::Texture> Images::textures;

std::string Images::getPath(images image) {
    switch(image)
    {
        case START: return "Images/GUI/Start.png";
            break;
        case EXIT: return "Images/GUI/Exit.png";
            break;
        case OPTIONS: return "Images/GUI/Options.png";
            break;
        case BACKGROUND: return "Images/GUI/background.jpg";
            break;
        case ARROWUP: return "Images/Arrows/Up.png";
            break;
        case ARROWDOWN: return "Images/Arrows/Down.png";
            break;
        case ARROWRIGHT: return "Images/Arrows/Right.png";
            break;
        case ARROWLEFT: return "Images/Arrows/Left.png";
            break;
        case RESOLUTION: return "Images/GUI/Resolution.png";
            break;
        case SOUND: return "Images/GUI/Sound.png";
            break;
        case RECEPTORLEFT: return "Images/receptors/Receptor0.png";
            break;
        case RECEPTORLEFTTAP: return "Images/receptors/Receptor0tap.png";
            break;
        case RECEPTORDOWN: return "Images/receptors/Receptor1.png";
            break;
        case RECEPTORDOWNTAP: return "Images/receptors/Receptor1tap.png";
            break;
        case RECEPTORUP: return "Images/receptors/Receptor2.png";
            break;
        case RECEPTORUPTAP: return "Images/receptors/Receptor2tap.png";
            break;
        case RECEPTORRIGHT: return "Images/receptors/Receptor3.png";
            break;
        case RECEPTORRIGHTTAP: return "Images/receptors/Receptor3tap.png";
            break;
        case ANIMA: return "Songs/359191 xi - ANiMA/bg.png";
            break;
    }
    return std::string();
}

void Images::load(images image) {
    textures[image].loadFromFile(getPath(image));
}

sf::Texture& Images::getImage(images image) {
    load(image);
    return textures[image];
}
