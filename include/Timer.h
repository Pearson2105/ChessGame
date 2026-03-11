#pragma once
#include <SFML/Graphics.hpp>

class Timer {
private:
    float whiteTime = 600.f;
    float blackTime = 600.f;
    sf::Font font;
    sf::Text whiteText;
    sf::Text blackText;

public:
    Timer();
    void update(bool whiteTurn, float dt);
    void draw(sf::RenderWindow& window);
};