//
// Created by Ben Ho on 5/3/2023.
//

#include "BouncingBall.h"

int BouncingBall::Run(sf::RenderWindow &window) {
    sf::Sprite sprite(texture.getTexture());
    sprite.setPosition((window.getSize().x - texture.getSize().x)/2 ,(window.getSize().y - texture.getSize().y)/2);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                return (0);
            }
        }
            update();
            circle.move(xSpeed, ySpeed);
            texture.clear(sf::Color::White);
            texture.draw(circle);
            texture.display();
            window.clear();
            window.draw(sprite);
            window.draw(title);
            window.display();
        }
    }
BouncingBall::BouncingBall() {
    setUp();
}

void BouncingBall::setUp() {
    static sf::Font font;
    texture.create(500,500);
    font.loadFromFile("Fonts/varsity_regular.ttf");
    title.setFont(font);
    title.setString("BouncingBall");
    circle.setRadius(50);
    circle.setFillColor(sf::Color::Red);
    xSpeed = 2.0, ySpeed = 2.0;
}

void BouncingBall::update() {
    if (xSpeed + circle.getPosition().x > (texture.getSize().x - circle.getRadius()*2) || circle.getPosition().x <0) {
        xSpeed = -1 * xSpeed;
    }
    if (ySpeed + circle.getPosition().y > (texture.getSize().y - circle.getRadius()*2) || circle.getPosition().y <0) {
        ySpeed = -1 * ySpeed;
    }
}
