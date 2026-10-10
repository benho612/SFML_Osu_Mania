//
// Created by Ben Ho on 5/2/2023.
//

#include "GameOverScreen.h"


GameOverScreen::GameOverScreen(int i, int i1, int i2, int i3): m_perfect(i), m_good(i1), m_great(i2),m_miss(i3) {
    setup();
}


void GameOverScreen::setup() {
    font.loadFromFile("Fonts/varsity_regular.ttf");
    perfect.setString("Perfect: " + std::to_string(m_perfect));
    perfect.setPosition(960,500);
    perfect.setFont(font);

    great.setString("Great: " + std::to_string(m_great));
    great.setPosition(960,600);
    great.setFont(font);

    good.setString(("Good: " + std::to_string(m_good)));
    good.setPosition(960,700);
    good.setFont(font);

    miss.setString("Miss: " + std::to_string(m_miss));
    miss.setPosition(960,800);
    miss.setFont(font);

}

int GameOverScreen::Run(sf::RenderWindow &window) {
    while (window.isOpen())
    {
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
                return (-1);
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
        }
        window.clear();
        window.draw(perfect);
        window.draw(great);
        window.draw(good);
        window.draw(miss);
        window.display();
    }
}





