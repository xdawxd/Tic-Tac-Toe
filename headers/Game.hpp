#pragma once

#include <Engine.hpp>
#include <Board.hpp>
#include <action.hpp>
#include <MenuState.hpp>

class Game {
public:
    explicit Game(Board &board); // todo: explicit?

public:
    bool finished = false;
    // todo: struct for wins?
    short int xWins = 0;
    short int yWins = 0;

    void drawScore(sf::RenderWindow &window);

    void checkMove();
    bool checkWinner(char player);

    void reset(Action &action);

private:
    Board &board;

};
