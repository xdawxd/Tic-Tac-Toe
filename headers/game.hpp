#ifndef TIC_TAC_TOE_GAME_HPP
#define TIC_TAC_TOE_GAME_HPP

#include <engine.hpp>
#include <board.hpp>
#include <action.hpp>

class Game {
private:
    Board &board;

public:
    Game(Board &board);
    bool finished = false;
    short int xWins = 0;
    short int yWins = 0;

    void drawScore(sf::RenderWindow &window);

    void checkMove();
    bool checkWinner(char player);

    void reset(Action &action);
};

#endif //TIC_TAC_TOE_GAME_HPP