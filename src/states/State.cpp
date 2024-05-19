#include "states/State.hpp"

State::State(sf::RenderWindow &window, sf::Font& font) : m_window(window), m_font(font) {} // todo: default state val?

void State::updateAndRender() {
    update();
    render();
}
