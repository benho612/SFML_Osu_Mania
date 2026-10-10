//
// Created by Ben Ho on 5/3/2023.
//

#include "GreenCircleScreen.h"
#include <SFML/Graphics.hpp>

GreenCircleScreen::GreenCircleScreen() {
    setUp();
}

int GreenCircleScreen::Run(sf::RenderWindow &window) {
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                return (0);
            }
        }
        window.clear(sf::Color::Black);
        window.draw(title);
        window.draw(circle);
        window.display();
    }
    return 0;
}

void GreenCircleScreen::setUp() {
    static sf::Font font;
    font.loadFromFile("Fonts/varsity_regular.ttf");
    title.setFont(font);
    title.setString("GreenCircle");
    circle.setFillColor(sf::Color::Green);
    circle.setRadius(150.f);
    circle.setPosition(500,500);
}


