#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "states/State.hpp"

struct GameWindow {
    static unsigned int resolutionX;
    static unsigned int resolutionY;
    static std::string title;
};


class Engine {
public:
    Engine();

public:
    void run();

private:
    GameState gameState;
    sf::RenderWindow window;
};
