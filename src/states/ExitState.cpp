#include "states/ExitState.hpp"

ExitState::ExitState(sf::RenderWindow &window, sf::Font &font) : State(window, font) {}

void ExitState::init() {m_window.close();}

void ExitState::update() {}

void ExitState::render() {}

GameState ExitState::handleEvent() {return m_gameState;}

GameState ExitState::getGameState() {return m_gameState;}

GameState ExitState::handleStateActions() {return m_gameState;}
