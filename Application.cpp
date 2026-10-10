//
// Created by hoben on 3/29/2023.
//

#include "Application.h"
#include "MouseEvent.h"
sf::RenderWindow Application::window;
std::vector<Component*> Application::Screens;

void Application::run() {
    window.create({1920,1080,60}, "osuMania");
    window.setFramerateLimit(60);
    window.setMouseCursorVisible(false);
    int screen = 0;
    /*while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            for(Component* c: components)
                c->eventHandler(window, event);
        }
        for(Component * c: components)
            c->update();

        window.clear(sf::Color::White);
        for(Component * c: components)
            window.draw(*reinterpret_cast<sf::Drawable*>(c));
        window.display();
    }*/
    while (screen >= 0)
    {
        screen = Screens[screen]->Run(window);
    }
}


void Application::addComponents(Component &component) {
    Screens.push_back(&component);
}
