#include <MenuState.hpp>

MenuState::MenuState(sf::RenderWindow &window, sf::Font& font, GameState state) : State(window, font, state) {}

GameState MenuState::getGameState() const {
    return State::getGameState();
}

GameState MenuState::handleEvent() {
    return State::handleEvent();
}

void MenuState::init() {
    initOptions();
}


void MenuState::initOptions() {
    std::vector<std::string> options = {"LOCAL", "MULTIPLAYER", "EXIT"};

    for (size_t i = 0; i < options.size(); ++i)
    {
        sf::Text diff;
        diff.setString(options[i]);
        diff.setFont(m_font);
        diff.setCharacterSize(67);
        diff.setOutlineColor(sf::Color::Black);
        diff.setOutlineThickness(2);
        diff.setOrigin(diff.getGlobalBounds().width / 2.f, diff.getGlobalBounds().height / 2.f);
        diff.setPosition(sf::Vector2f(m_window.getSize().x / 2.f, m_window.getSize().y / 2.f - 76.f + 4.f * i * 22.f));

        if (options[i] == "EASY")
            diff.setFillColor(sf::Color(0, 120, 0));
        else if (options[i] == "NORMAL")
            diff.setFillColor(sf::Color(180, 180, 0));
        else if (options[i] == "HARD")
            diff.setFillColor(sf::Color(150, 0, 0));
        else
            diff.setFillColor(sf::Color(80, 80, 80));

        menuOptions.push_back(diff);
    }
}

void MenuState::update() {

}

void MenuState::render() {

}
