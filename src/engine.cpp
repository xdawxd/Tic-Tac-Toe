#include <engine.hpp>
#include <board.hpp>
#include <action.hpp>
#include <game.hpp>

Engine::Engine() {
    resolution = sf::Vector2f(900, 900);
    window.create(sf::VideoMode(resolution.x, resolution.y), "Tic Tac Toe", sf::Style::Titlebar | sf::Style::Close);
}

void Engine::run() {
    Board board;
    Action action(board);
    Game game(board);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (game.finished) {
//                board.colorWinningSymbols(window);
                if (event.type == sf::Event::MouseButtonPressed)
                    game.reset(action);
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                action.handleMove(event);
                game.checkMove();
            }
        }
        window.clear(sf::Color::Black);
        game.drawScore(window);
        board.drawBoard(window);
        window.display();
    }
}
