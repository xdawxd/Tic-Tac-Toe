#pragma once

#include <SFML/Graphics.hpp>
#include <State.hpp>


struct Resolution {
    static unsigned int x;
    static unsigned int y;
};


unsigned int Resolution::x = 900;
unsigned int Resolution::y = 900;


class Engine {
private:
    GameState gameState;
    sf::RenderWindow window;
    sf::Event event{};

public:
    Engine();
    void run();
};
