#include <SFML/Graphics.hpp>
#include "../include/Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");

    Game game;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            game.handleInput(event);
        }

        game.update();

        window.clear();
        game.render(window);
        window.display();
    }

    return 0;
}