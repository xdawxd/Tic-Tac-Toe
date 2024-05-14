#pragma once

#include <SFML/Graphics.hpp>
#include <State.hpp>

class StateFactory {
private:
    State* m_currentState;

public:
    void handleState(sf::RenderWindow& window, sf::Font& font, sf::Event& event, State &state);
};
