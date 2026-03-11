#include "../include/Timer.h"
#include <iomanip>
#include <sstream>

Timer::Timer() {
    if (!font.loadFromFile("resources/VarsityTeam-Bold.otf")) {
    }

    whiteText.setFont(font);
    blackText.setFont(font);
    whiteText.setCharacterSize(28);
    blackText.setCharacterSize(28);
    whiteText.setFillColor(sf::Color::White);
    blackText.setFillColor(sf::Color::Black);

    whiteText.setPosition(820, 120);
    blackText.setPosition(820, 620);
}

void Timer::update(bool whiteTurn, float dt) {
    if (whiteTurn) whiteTime -= dt;
    else           blackTime -= dt;

    if (whiteTime < 0) whiteTime = 0;
    if (blackTime < 0) blackTime = 0;

    auto formatTime = [](float t) {
        int min = static_cast<int>(t) / 60;
        int sec = static_cast<int>(t) % 60;
        std::ostringstream oss;
        oss << min << ":" << std::setfill('0') << std::setw(2) << sec;
        return oss.str();
        };

    whiteText.setString("White: " + formatTime(whiteTime));
    blackText.setString("Black: " + formatTime(blackTime));
}

void Timer::draw(sf::RenderWindow& window) {
    window.draw(whiteText);
    window.draw(blackText);
}