#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>

#include "State.hpp"

class MultiplayerState : public State {
public:
    explicit MultiplayerState(sf::RenderWindow &window, sf::Font& font);
    ~MultiplayerState() override = default;

public:
    void init() override;
    void update() override;
    void render() override;
    GameState handleEvent() override;
    GameState getGameState() override;
    GameState handleStateActions() override;
};
