//
// Created by Dave R. Smith on 2/14/23.
//
#include "Background.h"

void Background::draw(sf::RenderTarget &window) const {
    window.draw(rectangle);
}

Background::Background() {
    rectangle.setFillColor(sf::Color::White);
    rectangle.setSize({500,750});
}


sf::RectangleShape& Background::getRectangle() {
    return this->rectangle;
}

sf::FloatRect Background::getPosition() {
    return this->rectangle.getGlobalBounds();
}

void Background::setPosition(float x, float y) {
    this->rectangle.setPosition(x,y);
}







