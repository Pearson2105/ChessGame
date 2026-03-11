#include <SFML/Graphics.hpp>
#include "../include/Game.h"
#include "../include/Piece.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Chess", sf::Style::Close);
    window.setFramerateLimit(60);

    Piece::loadTextures();

    Game game;

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            game.handleInput(window, event);
        }

        float dt = clock.restart().asSeconds();

        game.update(dt);

        window.clear(sf::Color(40, 40, 40));
        game.render(window);
        window.display();
    }

    return 0;
}