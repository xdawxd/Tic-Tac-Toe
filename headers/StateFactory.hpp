#pragma once

#include <SFML/Graphics.hpp>
#include "states/State.hpp"
#include "states/MenuState.hpp"
#include "states/LocalState.hpp"
#include "states/ExitState.hpp"

class StateFactory {
public:
    GameState createState(sf::RenderWindow& window, sf::Font& font, GameState& gameState);

private:
    State* m_currentState;
};
