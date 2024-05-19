#pragma once

#include <vector>
#include <string>
#include <iostream> // todo: for debug only
#include <SFML/Graphics.hpp>

#include "Action.hpp"
#include "Board.hpp"
#include "State.hpp"

class LocalState : public State {
public:
    explicit LocalState(sf::RenderWindow &window, sf::Font& font);
    ~LocalState() override = default;

public:
    GameState getGameState() override;
    GameState handleEvent() override;
    GameState handleStateActions() override;
    void init() override;
    void update() override;
    void render() override;

public:
    bool finished = false;

public:
    void checkMove();
    bool checkWinner(char player);
    void reset();

private:
    Board m_board;
    Action m_action;

    std::vector<sf::Text> boardGrid;
    sf::Text m_score;

    short int xWins = 0;
    short int yWins = 0;
    GameState gameState = LOCAL;

private:
    void initScore();
    void initBoard();

    void updateScore();
};
