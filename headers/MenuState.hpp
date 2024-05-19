#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <State.hpp>

class MenuState : public State {
public:
    explicit MenuState(sf::RenderWindow &window, sf::Font& font);
    ~MenuState() override = default;

public:
    GameState getGameState() override;
    GameState handleEvent() override;
    GameState handleStateActions() override;
    void init() override;
    void update() override;
    void render() override;

private:
    sf::Text title;
    GameState gameState = MENU;

private:
    std::vector<sf::Text> menuOptions;
    void initTitle();
    void initOptions();
};
