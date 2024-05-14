#ifndef TIC_TAC_TOE_ENGINE_HPP
#define TIC_TAC_TOE_ENGINE_HPP

#include <SFML/Graphics.hpp>
#include <vector>


class Engine {
private:
    sf::Vector2f resolution;
    sf::RenderWindow window;

public:
    Engine();
    void run();
};


#endif //TIC_TAC_TOE_ENGINE_HPP