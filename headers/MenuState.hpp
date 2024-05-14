#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <State.hpp>

class MenuState : public State {
public:
    explicit MenuState(sf::RenderWindow &window, sf::Font& font, sf::Event& event, GameState state);

public:
    GameState handleEvent() override;
    void handle() override;
    void init() override;
    void update() override;
    void render() override;

private:
    GameState gameState = MENU;
    sf::Text title;

private:
    std::vector<sf::Text> menuOptions;
    void initTitle();
    void initOptions();
};
