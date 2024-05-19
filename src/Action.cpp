#include "Action.hpp"

Action::Action(Board &board) : board(board) {}

void Action::handleMove(sf::Event &event) {
    char symbol = playedSymbol(event);
    if (currentSymbol == ' ') {
        currentSymbol = symbol;
        board.setFieldValues(symbol, event.mouseButton.x, event.mouseButton.y);
        return;
    }
    if (currentSymbol == symbol)
        return;
    else {
        Field &field = board.getFieldByCoordinates(event.mouseButton.x, event.mouseButton.y);
        if (field.symbol == ' ') {
            currentSymbol = symbol;
            board.setFieldValues(symbol, event.mouseButton.x, event.mouseButton.y);
            return;
        }
        return;
    }
}

char Action::playedSymbol(sf::Event &event) {
    if (event.mouseButton.button == sf::Mouse::Left)
        return 'x';
    else if (event.mouseButton.button == sf::Mouse::Right)
        return 'o';
    return ' ';
}
