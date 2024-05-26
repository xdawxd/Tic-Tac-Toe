#include "Action.hpp"

Action::Action(Board &board) : board(board) {}

void Action::handleMove(sf::Event &event) {
    if (event.mouseButton.button == sf::Mouse::Left) {
        if (currentSymbol == ' ') {
            setCurrentSymbol(event, 'x');
            return;
        }
        else {
            if (currentSymbol == 'x') {
                setCurrentSymbol(event, 'o');
                return;
            }
            else {
                setCurrentSymbol(event, 'x');
                return;
            }
        }
    }
}

void Action::setCurrentSymbol(sf::Event& event, char symbol) {
    currentSymbol = symbol;
    board.setFieldValue(symbol, event.mouseButton.x, event.mouseButton.y);
}
