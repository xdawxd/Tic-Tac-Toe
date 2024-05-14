#pragma once

#include "State.hpp"

class ExitState : public State {
public:
    explicit ExitState(sf::RenderWindow &window, sf::Font& font, sf::Event& event, GameState state);

public:
    void init() override;

    GameState handleEvent() override; // TODO: not sure if those methods should be pure virtual
    void update() override;
    void render() override;

private:
    GameState gameState = EXIT;
};