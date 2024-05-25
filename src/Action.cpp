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


// lmb = 'x', rmb = 'o' code. Decide which to use.
//    char symbol = playedSymbol(event);
//    if (currentSymbol == ' ') {
//        currentSymbol = symbol;
//        board.setFieldValue(symbol, event.mouseButton.x, event.mouseButton.y);
//        return;
//    }
//    if (currentSymbol == symbol)
//        return;
//    else {
//        Field &field = board.getFieldByCoordinates(event.mouseButton.x, event.mouseButton.y);
//        if (field.symbol == ' ') {
//            currentSymbol = symbol;
//            board.setFieldValue(symbol, event.mouseButton.x, event.mouseButton.y);
//            return;
//        }
//        return;
//    }

//char Action::playedSymbol(sf::Event &event) {
//    if (event.mouseButton.button == sf::Mouse::Left)
//        return 'x';
//    else if (event.mouseButton.button == sf::Mouse::Right)
//        return 'o';
//    return ' ';
//}
