#include <State.hpp>

State::State(sf::RenderWindow &window, sf::Font& font) : m_window(window), m_font(font) {}

void State::updateAndRender() {
    update();
    render();
}
