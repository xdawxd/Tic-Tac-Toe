#pragma once

#include <SFML/Graphics.hpp>

enum GameState {MENU, LOCAL, MULTIPLAYER, EXIT};

class State {
public:
    explicit State(sf::RenderWindow &window, sf::Font& font);
    virtual ~State() = default;

public:
    virtual void updateAndRender();

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    virtual GameState handleEvent() = 0;
    virtual GameState getGameState() = 0;
    virtual GameState handleStateActions() = 0;

protected:
    sf::RenderWindow& m_window;
    sf::Font& m_font;
    GameState m_gameState;
};
