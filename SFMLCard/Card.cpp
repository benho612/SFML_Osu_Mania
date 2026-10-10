//
// Created by Dave R. Smith on 2/14/23.
//

#include "Card.h"

Card::Card(){
}

Card::Card(Ranks rank, Suits suit):suit(suit), rank(rank),width(100),height(100){
    setRectPosition();
    update();
    setColor(suit);
    setUp();
}

void Card::setRectPosition() {
    this->background.setPosition(width,height);
}

void Card::update() {
    Position::center(this->background.getRectangle(),this->suit.getSprite());
    Position::topLeft(this->background.getRectangle(),this->rank.getTop());
    Position::bottomRight(this->background.getRectangle(),this->rank.getBottom());

}

void Card::setColor(Suits color) {
    if (Rank::getColor(color) == "HEARTS" || Rank::getColor(color) == "DIAMONDS")
    {
        this->rank.getTop().setFillColor(sf::Color::Red);
        this->rank.getBottom().setFillColor(sf::Color::Red);
    }
    else
    {
        this->rank.getTop().setFillColor(sf::Color::Black);
        this->rank.getBottom().setFillColor(sf::Color::Black);
    }
}

void Card::setUp() {
    static sf::Font font;
    font.loadFromFile("Fonts/varsity_regular.ttf");
    title.setFont(font);
    title.setString("SFML_Card");
}

int Card::Run(sf::RenderWindow &window) {
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
        window.clear();
        background.draw(window);
        rank.draw(window);
        suit.draw(window);
        window.draw(title);
        window.display();
    }
}



