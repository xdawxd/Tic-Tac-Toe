#include <iostream> // todo: debug only

#include "states/MenuState.hpp"

MenuState::MenuState(sf::RenderWindow &window, sf::Font& font) : State(window, font) {}

void MenuState::init() {
    initTitle();
    initOptions();
}

void MenuState::update() {
    sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(m_window).x, sf::Mouse::getPosition(m_window).y);

    for (auto & menuOption : menuOptions)
    {
        if (menuOption.getGlobalBounds().contains(mousePosition))
            menuOption.setScale(1.1f, 1.1f);
        else
            menuOption.setScale(1.f, 1.f);
    }
}

void MenuState::render() {
    m_window.clear(sf::Color(sf::Color::Black));

    //window->draw(background);
    m_window.draw(title);

    for (const auto & menuOption : menuOptions)
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
            (event.type == sf::Event::MouseButtonReleased && menuOptions[2].getGlobalBounds().contains(mousePosition)))
            return EXIT;
        else if (event.type == sf::Event::MouseButtonReleased && menuOptions[0].getGlobalBounds().contains(mousePosition))
            return LOCAL;
        else if (event.type == sf::Event::MouseButtonReleased && menuOptions[1].getGlobalBounds().contains(mousePosition))
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
    title.setString("Tic Tac Toe");
    title.setFont(m_font);

    title.setFillColor(sf::Color(sf::Color::Black));
    title.setOutlineColor(sf::Color::White);
    title.setOutlineThickness(4);
    title.setCharacterSize(96);
    title.setOrigin(
            title.getGlobalBounds().left + title.getGlobalBounds().width / 2.f,
            title.getGlobalBounds().top + title.getGlobalBounds().height / 2.f
    );
    title.setPosition(sf::Vector2f(m_window.getSize().x / 2.f, m_window.getSize().y / 12.f));
}

void MenuState::initOptions() {
    std::vector<std::string> options = {"LOCAL", "MULTIPLAYER", "EXIT"};

    for (size_t optionIndex = 0; optionIndex < options.size(); ++optionIndex)
    {
        sf::Text option;
        option.setString(options[optionIndex]);
        option.setFont(m_font);
        option.setCharacterSize(67);
        option.setOutlineColor(sf::Color::Black);
        option.setOutlineThickness(2);
        option.setOrigin(option.getGlobalBounds().width / 2.f, option.getGlobalBounds().height / 2.f);
        option.setPosition(sf::Vector2f(m_window.getSize().x / 2.f, m_window.getSize().y / 2.f - 76.f + 4.f * optionIndex * 22.f));

        option.setFillColor(sf::Color(sf::Color::Black));
        option.setOutlineColor(sf::Color::White);

        menuOptions.push_back(option);
    }
}
