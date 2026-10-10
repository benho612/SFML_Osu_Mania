//
// Created by Ben Ho on 4/3/2023.
//

#include "SfmlSingleScore.h"

sf::Font SfmlSingleScore::font;

void SfmlSingleScore::setText() {
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    font.loadFromFile("Images/arial.ttf");
    text.setFont(font);
}

void SfmlSingleScore::setPosition(sf::Vector2f position) {
    text.setPosition(position);
}

void SfmlSingleScore::draw(sf::RenderTarget &window) const {
    window.draw(text);
}

void SfmlSingleScore::setWord(const std::string& obj) {
    text.setString(obj);
}

SfmlSingleScore::SfmlSingleScore(){
    setText();
}


