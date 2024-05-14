#pragma once

#include <SFML/Graphics.hpp>

enum GameState {MENU, LOCAL, MULTIPLAYER, EXIT};

class State {
public:
    explicit State(sf::RenderWindow &window, sf::Font& font, sf::Event& event, GameState state);
    ~State() = default; // todo: will this work as intended?

public:
    GameState getGameState() const;

    virtual void handle(); // todo: rename?
    virtual GameState handleEvent() = 0;
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

protected:
    sf::RenderWindow& m_window;
    sf::Font& m_font;
    sf::Event& m_event;
    GameState m_state;
};
