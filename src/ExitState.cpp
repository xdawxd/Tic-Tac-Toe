#include "ExitState.hpp"

ExitState::ExitState(sf::RenderWindow &window, sf::Font &font) : State(window, font) {}

void ExitState::init() {
    m_window.close();
}

GameState ExitState::handleStateActions() {
    return gameState;
}

GameState ExitState::handleEvent() {
    return gameState;
}

void ExitState::update() {}

void ExitState::render() {}

GameState ExitState::getGameState() {
    return gameState;
}


