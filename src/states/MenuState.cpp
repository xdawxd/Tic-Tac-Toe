#include <iostream> // todo: debug only

#include "states/MenuState.hpp"

MenuState::MenuState(sf::RenderWindow &window, sf::Font& font) : State(window, font) {}

void MenuState::init() {
    initTitle();
    initOptions();
}

void MenuState::update() {
    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(m_window).x, sf::Mouse::getPosition(m_window).y);
    for (auto & menuOption : m_menuOptions)
        menuOption.scaleOnHover(mousePosition);
}

void MenuState::render() {
    m_window.clear(sf::Color(sf::Color::Black));
    m_window.draw(m_title);
    for (const auto& menuOption : m_menuOptions)
    {
        m_window.draw(menuOption);
    }
    m_window.display();
}

GameState MenuState::handleEvent() {
    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(m_window).x, sf::Mouse::getPosition(m_window).y);

    sf::Event event{};
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed ||
            (event.type == sf::Event::MouseButtonReleased && m_menuOptions[2].isClicked(event, mousePosition)))
            return EXIT;
        else if (event.type == sf::Event::MouseButtonReleased && m_menuOptions[0].isClicked(event, mousePosition))
            return LOCAL;
        else if (event.type == sf::Event::MouseButtonReleased && m_menuOptions[1].isClicked(event, mousePosition))
            return MULTIPLAYER;
    }
    return m_gameState;
}

GameState MenuState::getGameState() {
    return m_gameState;
}

GameState MenuState::handleStateActions() {
    GameState gameState = handleEvent();
    State::updateAndRender();
    return gameState;
}

void MenuState::initTitle() {
    m_title.setString("Tic Tac Toe");
    m_title.setFont(m_font);

    m_title.setFillColor(sf::Color(sf::Color::Black));
    m_title.setOutlineColor(sf::Color::White);
    m_title.setOutlineThickness(4);
    m_title.setCharacterSize(96);
    m_title.setOrigin(
            m_title.getGlobalBounds().left + m_title.getGlobalBounds().width / 2.f,
            m_title.getGlobalBounds().top + m_title.getGlobalBounds().height / 2.f
    );
    m_title.setPosition(sf::Vector2f(m_window.getSize().x / 2.f, m_window.getSize().y / 12.f));
}

void MenuState::initOptions() {
    std::vector<std::string> options = {"LOCAL", "MULTIPLAYER", "EXIT"};

    for (size_t optionIndex = 0; optionIndex < options.size(); ++optionIndex)
    {
        Button option = Button(options[optionIndex]);
        option.setStyle(m_font, sf::Color::Black, sf::Color::White, 2, 68);
        option.setButtonPosition(m_window.getSize().x / 2.f, m_window.getSize().y / 2.f - 76.f + 4.f * optionIndex * 22.f);
        m_menuOptions.push_back(option);
    }
}
