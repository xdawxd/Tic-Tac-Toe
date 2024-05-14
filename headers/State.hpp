#pragma once

#include <SFML/Graphics.hpp>

enum GameState {MENU, LOCAL, MULTIPLAYER, EXIT};

class State {
public:
    explicit State(sf::RenderWindow &window, sf::Font& font, GameState state);
    ~State() = default; // todo: will this work as intended?

protected:
    sf::RenderWindow& m_window;
    sf::Font& m_font;
    GameState m_state;

public:
    [[nodiscard]] GameState getGameState() const;
    void setGameState(GameState state);
    virtual GameState handleEvent() = 0;
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};
