//
// Created by Ben Ho on 5/3/2023.
//

#ifndef OSUMANIA_TWODARRAY_H
#define OSUMANIA_TWODARRAY_H
#include "Component.h"


class twoDArray: public Component {
private:
    sf::RenderTexture texture;
    sf::Text title;
    sf::RectangleShape ** ptr = nullptr;
    int rows, colos;
    sf::RectangleShape newRectangleShape(float x, float y);
    void createArray();
    void fillArray();
    void decreaseArray();
    void increaseArray();
public:
    twoDArray();
    twoDArray(int rows, int colos);
    twoDArray(const twoDArray& d);
    ~twoDArray() ;
    void eventHandler(sf::RenderWindow& window, sf::Event &event);
    twoDArray& operator=(const twoDArray& a);
    int Run(sf::RenderWindow &window) override;
    void setUp();

};


#endif //OSUMANIA_TWODARRAY_H
