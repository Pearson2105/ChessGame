#include "../include/Game.h"
#include "../include/MoveValidator.h"
#include <algorithm>

Game::Game() {
}

void Game::handleInput(sf::RenderWindow& window, sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        constexpr int TILE_SIZE = 100;
        constexpr int BOARD_SIZE = TILE_SIZE * 8;

        int offsetX = (window.getSize().x - BOARD_SIZE) / 2;
        int offsetY = (window.getSize().y - BOARD_SIZE) / 2;

        sf::Vector2i pos = sf::Mouse::getPosition(window);

        int bx = (pos.x - offsetX) / TILE_SIZE;
        int by = (pos.y - offsetY) / TILE_SIZE;

        if (bx < 0 || bx > 7 || by < 0 || by > 7) return;

        Piece* clicked = board.getPieceAt(bx, by);

        if (clicked && clicked->white == turn.isWhiteTurn()) {
            selectedPiece = clicked;
            dragging = true;
            highlight.addLegalMoves(selectedPiece, board.pieces);
        }
    }

    else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        if (selectedPiece && dragging) {
            sf::Vector2i pos = sf::Mouse::getPosition(window);
            int tx = pos.x / 100;
            int ty = pos.y / 100;

            if (tx >= 0 && tx < 8 && ty >= 0 && ty < 8) {
                if (MoveValidator::isValidMove(selectedPiece, tx, ty, board.pieces)) {

                    Piece* captured = board.getPieceAt(tx, ty);
                    if (captured) {
                        auto it = std::find(board.pieces.begin(), board.pieces.end(), captured);
                        if (it != board.pieces.end()) board.pieces.erase(it);
                    }

                    selectedPiece->setBoardPosition(tx, ty);

                    if (MoveValidator::isKingInCheck(turn.isWhiteTurn(), board.pieces)) {
                    }
                    else {
                        turn.switchTurn();
                    }
                }
            }
        }

        dragging = false;
        selectedPiece = nullptr;
        highlight.clear();
    }

    else if (event.type == sf::Event::MouseMoved && dragging && selectedPiece) {
        sf::Vector2i mpos = sf::Mouse::getPosition(window);
        selectedPiece->sprite.setPosition(
            (float)mpos.x,
            (float)mpos.y
        );
    }
}

void Game::update(float dt) {
    timer.update(turn.isWhiteTurn(), dt);
}

void Game::render(sf::RenderWindow& window) {
    board.draw(window);
    highlight.draw(window);

    for (auto p : board.pieces)
        p->draw(window);

    timer.draw(window);
}