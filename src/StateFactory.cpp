#include "StateFactory.hpp"

GameState StateFactory::createState(sf::RenderWindow& window, sf::Font& font, GameState& gameState) {
    if (m_currentState == nullptr || m_currentState->getGameState() != gameState) {
        delete m_currentState;
        m_currentState = nullptr;

        switch (gameState) {
            case MENU:
                m_currentState = new MenuState(window, font);
                break;
            case LOCAL:
                m_currentState = new LocalState(window, font);
                break;
            case MULTIPLAYER:
                m_currentState = new MultiplayerState(window, font);
                break;
            case EXIT:
                m_currentState = new ExitState(window, font);
                break;
        }
        if (m_currentState) {
            m_currentState->init();
        }
    }
    if (m_currentState) {
        gameState = m_currentState->handleStateActions();
    }
    return gameState;
}
