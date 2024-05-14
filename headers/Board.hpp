#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <Field.hpp>

struct RectangleProperties {
    const float thickness = 10.0f;
    const float beginPosition = 0.0f;
    const float firstPosition = 300.0f;
    const float secondPosition = 600.0f;
};

struct HorizontalRectangleProperties : RectangleProperties {
    const float x = beginPosition;
    const float oneY = firstPosition;
    const float twoY = secondPosition;
};


struct VerticalRectangleProperties: RectangleProperties {
    const float oneX = firstPosition;
    const float twoX = secondPosition;
    const float y = beginPosition;
};


class Board {
private:
    std::vector<std::vector<Field>> fields = {
            {Field(0, 0, 300, 300),   Field(300, 0, 600, 300),   Field(600, 0, 900, 300)},
            {Field(0, 300, 300, 600), Field(300, 300, 600, 600), Field(600, 300, 900, 600)},
            {Field(0, 600, 300, 900), Field(300, 600, 600, 900), Field(600, 600, 900, 900)}
    };

    void drawSymbols(sf::RenderWindow &window) const;

public:
    Board();

    void drawBoard(sf::RenderWindow &window) const;
    void setFieldValues(char symbol, int mousePressedX, int mousePressedY);

    [[nodiscard]] bool canWinDiagonally(int rowIndex, int columnIndex) const;
    void colorWinningSymbols(const std::vector<Field>& winningFields);

    bool isFull();
    void resetFields();

    [[nodiscard]] std::vector<Field> getRowSymbols(int rowIndex) const; // todo:  [[nodiscard]] meaning?
    [[nodiscard]] std::vector<Field> getColumnSymbols(int columnIndex) const;
    [[nodiscard]] std::vector<Field> getDiagonalSymbols(int rowIndex, int columnIndex) const;
    [[nodiscard]] std::vector<std::vector<Field>> getFields() const;
    Field& getFieldByCoordinates(int x, int y);
};
