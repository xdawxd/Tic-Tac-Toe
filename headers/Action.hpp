#ifndef TIC_TAC_TOE_ACTION_HPP
#define TIC_TAC_TOE_ACTION_HPP

#include <engine.hpp>
#include <board.hpp>

class Action {
private:
    Board &board;
    static char playedSymbol(sf::Event &event);

public:
    // todo: read about the order of defining variables, constructors, methods etc. in a c++ class (best practices)
    explicit Action(Board &board); // todo: why use explicit

    char currentSymbol = ' ';
    void handleMove(sf::Event &event);
};

#endif //TIC_TAC_TOE_ACTION_HPP
