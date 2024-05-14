#ifndef TIC_TAC_TOE_FIELD_HPP
#define TIC_TAC_TOE_FIELD_HPP

#include <SFML/Graphics.hpp>

class Field {
public:
    Field(int x0, int y0, int x1, int y1);
    explicit Field(char symbol); // TODO: why explicit?
    Field();

    int x0{}; // sets the default value (0 for int type)
    int y0{};
    int x1{};
    int y1{};
    sf::Color color = sf::Color::White;

    char symbol = ' ';

    bool operator==(const Field& other) const {
        return symbol == other.symbol;
    }

};

#endif //TIC_TAC_TOE_FIELD_HPP
