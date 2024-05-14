#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <State.hpp>

class MenuState : public State {
public:
    explicit MenuState(sf::RenderWindow &window, sf::Font& font, GameState state);

private:
    std::vector<sf::Text> menuOptions;
    void initOptions();

public:
    [[nodiscard]] GameState getGameState() const override;
    GameState handleEvent() override;
    void init() override;
    void update() override;
    void render() override;
};
