//
// Created by hoben on 4/19/2023.
//

#include <iostream>
#include "MainMenu.h"

MainMenu::MainMenu() {
    playing = false;
    setup();
    setPosition();
}

void MainMenu::setup() {
    mainMenu[0].setTexture(Images::getImage(START));
    mainMenu[1].setTexture(Images::getImage(OPTIONS));
    mainMenu[2].setTexture(Images::getImage(EXIT));
    background.setTexture(Images::getImage((BACKGROUND)));

}

void MainMenu::setPosition() {
    mainMenu[0].setPosition(500,300);
    mainMenu[1].setPosition(500,400);
    mainMenu[2].setPosition(500,500);
}

void MainMenu::MoveUp() {
        if(MainPressed <= 2 && MainPressed > 0)
        {
            mainMenu[MainPressed].setColor(sf::Color::White);
            MainPressed --;
            mainMenu[MainPressed].setColor(sf::Color::Blue);
        }
        else if(MainPressed == 0)
        {
            mainMenu[MainPressed].setColor(sf::Color::White);
            MainPressed = 2;
            mainMenu[MainPressed].setColor(sf::Color::Blue);
        }
    }

void MainMenu::MoveDown() {
    if(MainPressed >= 0 && MainPressed < 3) {
        mainMenu[MainPressed].setColor(sf::Color::White);
        MainPressed++;
        mainMenu[MainPressed].setColor(sf::Color::Blue);
    }
        if(MainPressed > 2)
        {
            mainMenu[MainPressed-1].setColor(sf::Color::White);
            MainPressed = 0;
            mainMenu[MainPressed].setColor(sf::Color::Blue);
        }
    }

void MainMenu::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
    {
        MoveUp();
        std::cout <<MainPressed << " \n";
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        MoveDown();
        std::cout <<MainPressed << " \n";
    }
    if(MainPressed == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        window.close();
    }
}

int MainMenu::Run(sf::RenderWindow &window) {
    sf::Event Event;

    bool Running = true;
    MainPressed = 0;
    mainMenu[0].setColor(sf::Color::Blue);
    while (Running) {
        //Verifying events
        while (window.pollEvent(Event)) {
            // Window closed
            if (Event.type == sf::Event::Closed) {
                return (-1);
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
            {
                return (4);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
            {
                return (5);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
            {
                return (6);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
            {
                return (7);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num5))
            {
                return (8);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num6))
            {
                return (9);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
                if (MainPressed == 0) {
                    playing = true;
                    return (1);
                }
                else if(MainPressed == 1)
                {
                    playing = true;
                    return (2);
                }
                else
                {
                    return (-1);
                }
            }
            eventHandler(window, Event);
        }
    window.clear();
    //Drawing
    window.draw(background);
    for (const auto &i: mainMenu) {
        window.draw(i);
    }
    if (MainPressed == maxOptions) {
        if (playing) {
            window.draw(mainMenu[2]);
        } else {
            window.draw(mainMenu[0]);
        }
        window.draw(mainMenu[1]);
    }
    window.display();
}
    return (-1);
}