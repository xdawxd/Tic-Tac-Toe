#include "StateFactory.hpp"
#include "MenuState.hpp"
#include "ExitState.hpp"

State* StateFactory::createState(sf::RenderWindow& window, sf::Font& font, sf::Event &event, GameState gameState) {
    switch (gameState) {
        case MENU:
            m_currentState = new MenuState(window, font, event, gameState);
            break;
        case LOCAL:
            break;
        case MULTIPLAYER:
            break;
        case EXIT:
            m_currentState = new ExitState(window, font, event, gameState);
            break;
    }
    m_currentState->init();
    m_currentState->handle();
    return m_currentState;
}
