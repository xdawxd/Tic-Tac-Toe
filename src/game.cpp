#include <game.hpp>
#include <iostream>

Game::Game(Board &board) : board(board) {}


bool Game::checkWinner(char symbol) {
    auto fields = board.getFields();
    std::vector<char> playerWin(3, symbol);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            // check row winning scenario
            if (board.getRowSymbols(row) == playerWin)
                return true;

            // check column winning scenario
            if (board.getColumnSymbols(column) == playerWin)
                return true;

            // check diagonal winning scenario
            // The player can win diagonally and the middle part is also occupied by the player
            if (board.canWinDiagonally(row, column) && fields[1][1].symbol == symbol) {
                if (board.getDiagonalSymbols(row, column) == playerWin)
                    return true;
            }
        }
    }
    return false;
}


void Game::checkMove() {
    if (checkWinner('x')) {
        xWins += 1;
        finished = true;
        std::cout << "x wins" << std::endl;
    } else if (checkWinner('o')) {
        yWins += 1;
        finished = true;
        std::cout << "o wins" << std::endl;
    }

    if (board.isFull() && !finished) {
        finished = true;
        std::cout << "draw" << std::endl;
    }

    if (xWins == 10 || yWins == 10) {
        xWins = 0;
        yWins = 0;
    }
}

void Game::reset(Action &action) {
    board.resetFields();
    action.currentSymbol = ' ';
    finished = false;
}

void Game::drawScore(sf::RenderWindow &window) {
    sf::Text text;
    sf::Font font;
    font.loadFromFile("../fonts/arial.ttf"); // adjust the CWD to remove the ../

    std::string score = std::to_string(xWins) + ":" + std::to_string(yWins);
    text.setString(score);
    text.setFont(font);
    text.setCharacterSize(600);
    text.setPosition(40, 40);
    text.setFillColor(sf::Color(51, 51, 51)); // todo: move the colors to some const struct/class

    window.draw(text);
}