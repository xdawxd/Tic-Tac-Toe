#include <State.hpp>

State::State(sf::RenderWindow &window, sf::Font& font, sf::Event& event, GameState state) : m_window(window), m_font(font), m_event(event), m_state(state) {}


GameState State::getGameState() const {
    return m_state;
}

void State::handle() {
    update();
    render();
}
