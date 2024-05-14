#pragma once

#include <Engine.hpp>
#include <Board.hpp>

class Action {
public:
    char currentSymbol = ' ';
private:
    Board &board;
    static char playedSymbol(sf::Event &event);

public:
    explicit Action(Board &board);
    void handleMove(sf::Event &event);
};
