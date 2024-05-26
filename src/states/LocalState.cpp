#include "states/LocalState.hpp"

LocalState::LocalState(sf::RenderWindow &window, sf::Font &font) : State(window,font), m_board(m_font), m_action(m_board) {}

void LocalState::init() {
    initScore();
    initBackToMenuButton();
}

void LocalState::update() {
    updateScore();
    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(m_window).x, sf::Mouse::getPosition(m_window).y);
    m_menuButton.scaleOnHover(mousePosition);
}

void LocalState::render() {
    m_window.clear(sf::Color(sf::Color::Black));
    m_window.draw(m_score);
    m_board.drawBoard(m_window);
    m_window.draw(m_menuButton);
    m_window.display();
}

GameState LocalState::handleEvent() {
    sf::Event event{};
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return EXIT;
        if (finished) {
            if (event.type == sf::Event::MouseButtonPressed)
                reset();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            m_action.handleMove(event);
            checkMove();
        }
    }
    return m_gameState;
}

GameState LocalState::getGameState() {
    return m_gameState;
}

GameState LocalState::handleStateActions() {
    GameState gameState = handleEvent();
    State::updateAndRender();
    return gameState;
}

void LocalState::reset() {
    m_board.resetFields();
    m_action.currentSymbol = ' ';

    finished = false;
}

void LocalState::checkMove() {
    if (checkWinner('x')) {
        xWins += 1;
        finished = true;
        std::cout << "x wins" << std::endl;
    } else if (checkWinner('o')) {
        yWins += 1;
        finished = true;
        std::cout << "o wins" << std::endl;
    }

    if (m_board.isFull() && !finished) {
        finished = true;
        std::cout << "draw" << std::endl;
//        std::string score = "Draw"; // TODO
//        m_score.setString(score);
    }

    if (xWins == 10 || yWins == 10) {
        xWins = 0;
        yWins = 0;
    }
}

bool LocalState::checkWinner(char symbol) {
    auto fields = m_board.getFields();
    auto playerField = Field(symbol);
    std::vector<Field> playerWin(3, playerField);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            // check row winning scenario
            auto rowFields = m_board.getRowSymbols(row);
            if (rowFields == playerWin) {
                m_board.colorWinningSymbols(rowFields);
                return true;
            }

            // check column winning scenario
            auto columnFields = m_board.getColumnSymbols(column);
            if (columnFields == playerWin) {
                m_board.colorWinningSymbols(columnFields);
                return true;
            }

            // check diagonal winning scenario
            // The player can win diagonally and the middle part is also occupied by the player
            if (m_board.canWinDiagonally(row, column) && fields[1][1].symbol == symbol) {
                auto diagonalFields = m_board.getDiagonalSymbols(row, column);
                if (diagonalFields == playerWin) {
                    m_board.colorWinningSymbols(diagonalFields);
                    return true;
                }
            }
        }
    }
    return false;
}

void LocalState::initScore() {
    std::string score = std::to_string(xWins) + ":" + std::to_string(yWins);
    m_score.setString(score);
    m_score.setFont(m_font);
    m_score.setCharacterSize(600);
    m_score.setPosition(40, 40);
    m_score.setFillColor(sf::Color(51, 51, 51));
}

void LocalState::updateScore() {
    std::string score = std::to_string(xWins) + ":" + std::to_string(yWins);
    m_score.setString(score);
}

void LocalState::initBackToMenuButton() {
    m_menuButton = Button("MENU");
    m_menuButton.setStyle(m_font, sf::Color::Black, sf::Color::White, 2, 24);
    m_menuButton.setButtonPosition(m_window.getSize().x / 20.f, m_window.getSize().y / 40.f);

}
