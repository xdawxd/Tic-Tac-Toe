#pragma once

#include "State.hpp"

class ExitState : public State {
public:
    explicit ExitState(sf::RenderWindow &window, sf::Font& font);
    ~ExitState() override = default;

public:
    void init() override;
    void update() override;
    void render() override;
    GameState handleEvent() override;
    GameState getGameState() override;
    GameState handleStateActions() override;

private:
    GameState m_gameState = EXIT;
};