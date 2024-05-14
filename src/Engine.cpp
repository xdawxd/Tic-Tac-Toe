#include <Engine.hpp>
#include <Board.hpp>
#include <Action.hpp>
#include <Game.hpp>
#include <State.hpp>
#include <StateFactory.hpp>

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

    auto state = MenuState(window, font, MENU); // MenuState is being created here and in handleState()
    StateFactory stateHandler{};

    while (gameState != EXIT) {
        if (window.pollEvent(event) && event.type == sf::Event::Closed) {
            state.setGameState(EXIT);
        }
        stateHandler.handleState(window, font, event, state);
    }

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
