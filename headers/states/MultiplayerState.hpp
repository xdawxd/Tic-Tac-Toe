#pragma once

#include "State.hpp"

class MultiplayerState : public State {
public:
    explicit MultiplayerState(sf::RenderWindow &window, sf::Font& font);
    virtual ~MultiplayerState() = default;

public:
    virtual void updateAndRender();

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual GameState handleEvent() = 0;
    virtual GameState getGameState() = 0;
    virtual GameState handleStateActions() = 0;

};
