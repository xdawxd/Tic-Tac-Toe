#pragma once

#include <SFML/Graphics.hpp>
#include <State.hpp>


struct Resolution {
    static unsigned int x;
    static unsigned int y;
};


class Engine {
public:
    Engine();

public:
    void run();

private:
    GameState gameState;
    sf::RenderWindow window;
    sf::Event event{};
};
