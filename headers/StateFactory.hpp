#pragma once

#include <SFML/Graphics.hpp>
#include <State.hpp>

class StateFactory {
public:
    State* createState(sf::RenderWindow& window, sf::Font& font, sf::Event& event, GameState gameState);

private:
    State* m_currentState;

};
