//
// Created by Ben Ho on 5/3/2023.
//

#include "Images.h"

std::map<images, sf::Texture> Phaserimages::textures;

std::string Phaserimages::getPath(images image) {
    switch(image)
    {
        case PHASER: return "Phaser/Images/phaser.png";
            break;
    }
    return std::string();
}

void Phaserimages::load(images image) {
    textures[image].loadFromFile(getPath(image));
}

sf::Texture& Phaserimages::getImage(images image) {
    load(image);
    return textures[image];
}