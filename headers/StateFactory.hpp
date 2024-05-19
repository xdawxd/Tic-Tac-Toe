#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "MenuState.hpp"
#include "LocalState.h"
#include "ExitState.hpp"

class StateFactory {
public:
    GameState createState(sf::RenderWindow& window, sf::Font& font, GameState& gameState);

private:
    State* m_currentState;
};
