#include <State.hpp>

State::State(sf::RenderWindow &window, sf::Font& font, GameState state) : m_window(window), m_font(font), m_state(state) {}


GameState State::getGameState() const {
    return m_state;
}


void State::setGameState(GameState state) {
    m_state = state;
}
