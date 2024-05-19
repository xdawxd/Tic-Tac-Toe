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
    void init() override;
    void update() override;
    void render() override;
    GameState handleEvent() override;
    GameState getGameState() override;
    GameState handleStateActions() override;

public:
    bool finished = false;

public:
    void reset();
    void checkMove();
    bool checkWinner(char player);

private:
    void initScore();
    void updateScore();
    void initBackToMenuButton(); // todo

private:
    Board m_board;
    Action m_action;

    sf::Text m_score;

    short int xWins = 0;
    short int yWins = 0;
    GameState m_gameState = LOCAL;

    std::vector<sf::Text> boardGrid;  // todo: unused?
};
