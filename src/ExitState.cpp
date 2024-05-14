#include "ExitState.hpp"

ExitState::ExitState(sf::RenderWindow &window, sf::Font &font, sf::Event &event, GameState state) : State(window, font, event, state) {}

void ExitState::init() {
    m_window.close();
}

GameState ExitState::handleEvent() {
    return EXIT;
}

void ExitState::update() {}

void ExitState::render() {}
