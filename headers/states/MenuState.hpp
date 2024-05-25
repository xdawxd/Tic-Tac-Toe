#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

#include "State.hpp"

class MenuState : public State {
public:
    explicit MenuState(sf::RenderWindow &window, sf::Font& font);
    ~MenuState() override = default;

public:
    void init() override;
    void update() override;
    void render() override;
    GameState handleEvent() override;
    GameState getGameState() override;
    GameState handleStateActions() override;

private:
    void initTitle();
    void initOptions();

private:
    sf::Text m_title;
    GameState m_gameState = MENU;
    std::vector<sf::Text> m_menuOptions;
};
