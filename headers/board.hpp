#ifndef TIC_TAC_TOE_BOARD_HPP
#define TIC_TAC_TOE_BOARD_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <field.hpp>

class Board {
private:
    const float rectangleThickness = 10.0f;
    const float rectangleBeginPosition = 0.0f;
    const float rectangleFirstPosition = 300.0f;
    const float rectangleSecondPosition = 600.0f;

    const float horizontalRectangleX = rectangleBeginPosition;
    const float horizontalRectangleOneY = rectangleFirstPosition;
    const float horizontalRectangleTwoY = rectangleSecondPosition;

    const float verticalRectangleOneX = rectangleFirstPosition;
    const float verticalRectangleTwoX = rectangleSecondPosition;
    const float verticalRectangleY = rectangleBeginPosition;

    std::vector<std::vector<Field>> fields = {
            {Field(0, 0, 300, 300),   Field(300, 0, 600, 300),   Field(600, 0, 900, 300)},
            {Field(0, 300, 300, 600), Field(300, 300, 600, 600), Field(600, 300, 900, 600)},
            {Field(0, 600, 300, 900), Field(300, 600, 600, 900), Field(600, 600, 900, 900)}
    };
public:
    Board();

    void drawBoard(sf::RenderWindow &window) const;
    void drawSymbols(sf::RenderWindow &window) const;
    void setFieldValues(char symbol, int mousePressedX, int mousePressedY);
    bool canWinDiagonally(int rowIndex, int columnIndex) const;
    void colorWinningSymbols(sf::RenderWindow &window);

    bool isFull();

    std::vector<char> getDiagonalSymbols(int rowIndex, int columnIndex) const;
    std::vector<std::vector<Field>> getFields() const;
    std::vector<char> getRowSymbols(int rowIndex) const;
    std::vector<char> getColumnSymbols(int columnIndex) const;
    Field& getFieldByCoordinates(int x, int y); // todo: adjust parameter names

    void resetFields();
};

#endif //TIC_TAC_TOE_BOARD_HPP