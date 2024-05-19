#pragma once

#include "State.hpp"

class ExitState : public State {
public:
    explicit ExitState(sf::RenderWindow &window, sf::Font& font);

public:
    void init() override;

    GameState getGameState() override;
    GameState handleStateActions() override;
    GameState handleEvent() override;
    void update() override;
    void render() override;

private:
    GameState gameState = EXIT;
};