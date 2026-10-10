//
// Created by Ben Ho on 5/3/2023.
//

#include "testing.h"
#include "CardHandScorer.h"

int testing::Run(sf::RenderWindow &window) {
    srand(time(nullptr));
    PokerScore total;
    int timeOfRunningProgram = 700000;

    for (int i = 0; i < timeOfRunningProgram; ++i) {
        Deck deck;
        CardHand ch;
        for (int j = 0; j < 5; j++)
        {
            ch.addCard(deck.dealCard());
        }
        total+= CardHandScorer::scorePokerHand(ch);
    }
    total.PokerAnaylsis(total);
    std::cout<<total;


    rowOfCard test;
    SfmlScore scoreboard(total, timeOfRunningProgram);
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
        window.clear(sf::Color::White);
        test.draw(window);
        scoreboard.draw(window);
        window.draw(title);
        window.display();
    }
}

testing::testing() {
    setUp();
}

void testing::setUp() {
    static sf::Font font;
    font.loadFromFile("Fonts/varsity_regular.ttf");
    title.setFont(font);
    title.setString("Poke Analysis");
}
