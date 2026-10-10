//
// Created by hoben on 4/24/2023.
//

#include <iostream>
#include "OptionScreen.h"

OptionScreen::OptionScreen() {
    setup();
}

int OptionScreen::Run(sf::RenderWindow &window)
{
    sf::Event Event;
    bool Running = true;

    while (Running)
    {
        //Verifying events
        while (window.pollEvent(Event))
        {
            // Window closed
            if (Event.type == sf::Event::Closed)
            {
                return (-1);
            }
            //Key pressed
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                    case sf::Keyboard::Escape:
                        return (0);
                    default:
                        break;
                }
            }
            eventHandler(window,Event);
        }

        window.clear();
        window.draw(backGround);
        window.draw(resolution);
        window.draw(volume);
        window.display();
    }

    //Never reaching this point normally, but just in case, exit the windowlication
    return -1;
}

void OptionScreen::setup() {
    resolution.setTexture(Images::getImage(RESOLUTION));
    volume.setTexture(Images::getImage(SOUND));
    resolution.setPosition(500,500);
    volume.setPosition(500,600);
    backGround.setTexture(Images::getImage(BACKGROUND));
}

void OptionScreen::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        moveOption();
        std::cout <<Pressed << " \n";
    }
}

void OptionScreen::moveOption() {
    if(Pressed == 1)
    {
        resolution.setColor(sf::Color::White);
        volume.setColor(sf::Color::Blue);
        Pressed ++;
    }
    else if(Pressed == 2)
    {
        resolution.setColor(sf::Color::Blue);
        volume.setColor(sf::Color::White);
        Pressed --;
    }
}

