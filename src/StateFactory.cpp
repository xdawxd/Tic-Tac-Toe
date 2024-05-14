#include <StateFactory.hpp>
#include <MenuState.hpp>

void StateFactory::handleState(sf::RenderWindow& window, sf::Font& font, sf::Event &event, State &state) {
    auto gameState = state.getGameState();
    switch (state.getGameState()) {
        case MENU:
            m_currentState = new MenuState(window, font, gameState);
            break;
        case LOCAL:
            break;
        case MULTIPLAYER:
            break;
        case EXIT:
            window.close();
            return;
    }
    m_currentState->init();
}
