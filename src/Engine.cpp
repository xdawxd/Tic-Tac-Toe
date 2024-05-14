#include <Engine.hpp>
#include <Board.hpp>
#include <Action.hpp>
#include <Game.hpp>
#include <State.hpp>
#include <StateFactory.hpp>

unsigned int Resolution::x = 900; // TODO: consider removing this or doing it the other way
unsigned int Resolution::y = 900;

Engine::Engine() {
    window.create(sf::VideoMode(Resolution::x, Resolution::y), "Tic Tac Toe", sf::Style::Titlebar | sf::Style::Close);
    gameState = MENU;
}

sf::Font initFont() {
    sf::Font font;
    font.loadFromFile("../fonts/arial.ttf"); // adjust the CWD to remove the ../
    return font;
}

void Engine::run() {
    Board board;
    Action action(board);
    Game game(board);
    sf::Font font = initFont();

    StateFactory stateFactory{};
    while (gameState != EXIT) {
        if (window.pollEvent(event) && event.type == sf::Event::Closed) {
            gameState = EXIT;
        }
        State* state = stateFactory.createState(window, font, event, gameState);

    }
    window.close();

//    while (window.isOpen()) {
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed)
//                window.close();
//            if (game.finished) {
//                if (event.type == sf::Event::MouseButtonPressed)
//                    game.reset(action);
//            }
//            if (event.type == sf::Event::MouseButtonPressed) {
//                action.handleMove(event);
//                game.checkMove();
//            }
//        }
//        window.clear(sf::Color::Black);
//        game.drawScore(window);
//        board.drawBoard(window);
//        window.display();
//    }
}
