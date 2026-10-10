//
// Created by Ben Ho on 5/3/2023.
//

#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite() {
    setup(Phaserimages::getImage(PHASER),4,12);
}

AnimatedSprite::AnimatedSprite(sf::Texture &texture, int rows, int cols) {
    setup(texture, rows, cols);
}

void AnimatedSprite::animate() {
    if(clock.getElapsedTime().asMilliseconds() > time)
    {
        if(intRect.left >= width - intRect.width)
            intRect.left = 0;
        else
            intRect.left += intRect.width;
        clock.restart();
        sprite.setTextureRect(intRect);
    }
}

void AnimatedSprite::setup(sf::Texture &texture, int rows, int cols) {
    width = texture.getSize().x;
    height = texture.getSize().y;
    sprite.setTexture(texture);
    setupIntRect(texture.getSize(), rows, cols);
    static sf::Font font;
    font.loadFromFile("Fonts/varsity_regular.ttf");
    title.setFont(font);
    title.setString("Phaser");
}

void AnimatedSprite::setupIntRect(sf::Vector2u imgSize, int rows, int cols) {
    intRect.width = std::round(imgSize.x/ static_cast<float>(cols));
    intRect.height = imgSize.y / rows;
    intRect.left = 0;
    intRect.top = 0;
    sprite.setTextureRect(intRect);
}

int AnimatedSprite::getTime() const {
    return time;
}

void AnimatedSprite::setTime(int time) {
    AnimatedSprite::time = time;
}

void AnimatedSprite::update() {
    //animate only if movable
    if(check_state(MOVING))
    {
        animate();
    }
}

void AnimatedSprite::eventHandler(sf::RenderWindow &window, sf::Event event) {
    sf::Vector2f veloctiy;
    if(sf::Keyboard::isKeyPressed(forwardKey) || sf::Keyboard::isKeyPressed(Up))
    {
        changeDirection(BACK);
        veloctiy.x = 0;
        veloctiy.y = -speed;
    }
    else if(sf::Keyboard::isKeyPressed(leftKey) || sf::Keyboard::isKeyPressed(left))
    {
        changeDirection(LEFT);
        veloctiy.x = -speed;
        veloctiy.y = 0;
    }
    else if (sf::Keyboard::isKeyPressed(DownKey)|| sf::Keyboard::isKeyPressed(down))
    {
        changeDirection(FORWARD);
        veloctiy.x = 0;
        veloctiy.y = speed;
    }
    else if (sf::Keyboard::isKeyPressed(rightKey) || sf::Keyboard::isKeyPressed(right))
    {
        changeDirection(RIGHT);
        veloctiy.x = speed;
        veloctiy.y = 0;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        toggle_state(MOVING);
        while(sf::Keyboard::isKeyPressed(sf::Keyboard::Space));
    }
    sprite.move(veloctiy);
}

/*void AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const {

}*/

void AnimatedSprite::changeDirection(directions direction) {
    intRect.top = direction * intRect.height;
}

float AnimatedSprite::getSpeed() const {
    return speed;
}

void AnimatedSprite::setSpeed(float speed) {
    AnimatedSprite::speed = speed;
}

void AnimatedSprite::setForwardKey(sf::Keyboard::Key forwardKey) {
    AnimatedSprite::forwardKey = forwardKey;
}

void AnimatedSprite::setLeftKey(sf::Keyboard::Key leftKey) {
    AnimatedSprite::leftKey = leftKey;
}

void AnimatedSprite::setRightKey(sf::Keyboard::Key rightKey) {
    AnimatedSprite::rightKey = rightKey;
}

void AnimatedSprite::setDownKey(sf::Keyboard::Key downKey) {
    DownKey = downKey;
}

void AnimatedSprite::setUp(sf::Keyboard::Key up) {
    Up = up;
}

void AnimatedSprite::setDown(sf::Keyboard::Key down) {
    AnimatedSprite::down = down;
}

void AnimatedSprite::setLeft(sf::Keyboard::Key left) {
    AnimatedSprite::left = left;
}

void AnimatedSprite::setRight(sf::Keyboard::Key right) {
    AnimatedSprite::right = right;
}

int AnimatedSprite::Run(sf::RenderWindow &window) {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            eventHandler(window,event);
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad0) || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                return (0);
            }
        }
        window.clear();
        update();
        window.draw(sprite);
        window.draw(title);
        window.display();
    }
}
