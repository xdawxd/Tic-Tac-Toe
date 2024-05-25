#include "Engine.hpp"
#include "states/State.hpp"
#include "StateFactory.hpp"

unsigned int GameWindow::resolutionX = 900;
unsigned int GameWindow::resolutionY = 900;
std::string GameWindow::title = "Tic Tac Toe";


Engine::Engine() {
    window.create(sf::VideoMode(GameWindow::resolutionX, GameWindow::resolutionY), GameWindow::title, sf::Style::Titlebar | sf::Style::Close);
    gameState = MENU;
}

sf::Font initFont() {
    sf::Font font;
    font.loadFromFile("../fonts/arial.ttf"); // adjust the CWD to remove the ../
    return font;
}

void Engine::run() {
    sf::Font font = initFont();

    StateFactory stateFactory{};
    while (gameState != EXIT) {
        gameState = stateFactory.createState(window, font, gameState);
    }
    window.close();
}
