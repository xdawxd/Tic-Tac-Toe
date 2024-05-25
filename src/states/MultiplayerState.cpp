#include "states/MultiplayerState.hpp"

MultiplayerState::MultiplayerState(sf::RenderWindow &window, sf::Font &font) : State(window, font) {}

void MultiplayerState::init() {
    WSADATA wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "WSAStartup failed.\n");
    }

    if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
        fprintf(stderr, "Version 2.2 of Winsock is not available.\n");
        WSACleanup();
        exit(2);
    }

}

void MultiplayerState::update() {}

void MultiplayerState::render() {}

GameState MultiplayerState::handleEvent() {
    return MULTIPLAYER;
}

GameState MultiplayerState::getGameState() {
    return MULTIPLAYER;
}

GameState MultiplayerState::handleStateActions() {
    return MULTIPLAYER;
}
