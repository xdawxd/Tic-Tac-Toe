#include <iostream>

#include "Board.hpp"

Board::Board(sf::Font& font) : m_font(font) {};

void Board::drawBoard(sf::RenderWindow &window) const {
    RectangleProperties rect;
    HorizontalRectangleProperties horizontalRect;
    VerticalRectangleProperties verticalRect;

    sf::RectangleShape horizontalRectangle1(sf::Vector2f(window.getSize().x, rect.thickness));
    horizontalRectangle1.setFillColor(sf::Color::White);
    horizontalRectangle1.setPosition(horizontalRect.x, horizontalRect.oneY);

    sf::RectangleShape horizontalRectangle2(sf::Vector2f(window.getSize().x, rect.thickness));
    horizontalRectangle2.setFillColor(sf::Color::White);
    horizontalRectangle2.setPosition(horizontalRect.x, horizontalRect.twoY);

    sf::RectangleShape verticalRectangle1(sf::Vector2f(rect.thickness, window.getSize().y));
    verticalRectangle1.setFillColor(sf::Color::White);
    verticalRectangle1.setPosition(verticalRect.oneX, verticalRect.y);

    sf::RectangleShape verticalRectangle2(sf::Vector2f(rect.thickness, window.getSize().y));
    verticalRectangle2.setFillColor(sf::Color::White);
    verticalRectangle2.setPosition(verticalRect.twoX, verticalRect.y);

    window.draw(horizontalRectangle1);
    window.draw(horizontalRectangle2);
    window.draw(verticalRectangle1);
    window.draw(verticalRectangle2);

    drawSymbols(window);
}

void Board::setFieldValue(char symbol, int mousePressedX, int mousePressedY) {
    Field &field = getFieldByCoordinates(mousePressedX, mousePressedY);
    if (field.symbol == ' ')
        field.symbol = symbol;
}

void Board::drawSymbols(sf::RenderWindow &window) const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            Field field = fields[i][j];

            sf::Text text;
            text.setString(field.symbol);
            text.setFont(m_font);
            text.setCharacterSize(400);
            text.setPosition(field.x0 + 50, field.y0 - 150);
            text.setFillColor(field.color);

            // std::cout << std::hex << field.color.toInteger() << std::endl; // todo: remove color debug

            window.draw(text);
        }
    }
}

void Board::resetFields() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            fields[i][j].symbol = ' ';
            fields[i][j].color = sf::Color::White;
        }
    }
}

std::vector<std::vector<Field>> Board::getFields() const {
    return fields;
}

std::vector<Field> Board::getRowSymbols(int rowIndex) const {
    std::vector<Field> rowFields = {fields[rowIndex][0], fields[rowIndex][1], fields[rowIndex][2]};
    return rowFields;
}

std::vector<Field> Board::getColumnSymbols(int columnIndex) const {
    std::vector<Field> symbols = {fields[0][columnIndex], fields[1][columnIndex], fields[2][columnIndex]};
    return symbols;
}

bool Board::canWinDiagonally(int rowIndex, int columnIndex) const {
    if (rowIndex % 2 == 0 && columnIndex % 2 == 0)
        return true;
    else if (rowIndex == 1 && columnIndex == 1)
        return true;
    return false;

}

// TODO: optimize the diagonal win scenario
std::vector<Field> Board::getDiagonalSymbols(int rowIndex, int columnIndex) const {
    std::vector<Field> symbols(3, Field());

    symbols[1] = fields[1][1]; // set the middle field before any checks
    if (rowIndex == 0) {
        if (columnIndex == 0) { // TODO: move to a separate function
            symbols[0] = fields[rowIndex][columnIndex];
            symbols[2] = fields[rowIndex+2][columnIndex+2];
        }

        else if (columnIndex == 2) {
            symbols[0] = fields[rowIndex][columnIndex];
            symbols[2] = fields[rowIndex+2][columnIndex-2];
        }
    }

    else if (rowIndex == 2) {
        if (columnIndex == 0) {
            symbols[0] = fields[rowIndex][columnIndex];
            symbols[2] = fields[rowIndex-2][columnIndex+2];
        }

        else if (columnIndex == 2) {
            symbols[0] = fields[rowIndex][columnIndex];
            symbols[2] = fields[rowIndex-2][columnIndex-2];
        }
    }

    else if (columnIndex == 1) {
        symbols[0] = fields[rowIndex-1][columnIndex-1];
        symbols[2] = fields[rowIndex+1][columnIndex+1];
    }
    return symbols;
}

void Board::colorWinningSymbols(const std::vector<Field>& winningFields) {
    for (auto winningField: winningFields) {
        Field& bField = getFieldByCoordinates(winningField.x0 + 20, winningField.y0 + 20); // todo: adjust the name, and ref the winning position...
        bField.color = sf::Color(60, 0, 0);
    }
}

bool Board::isFull() {
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            if (fields[row][column].symbol == ' ')
                return false;
        }
    }
    return true;
}

Field& Board::getFieldByCoordinates(int x, int y) {
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            Field &field = fields[row][column];
            if ((x >= field.x0 && y >= field.y0) && (x <= field.x1 && y <= field.y1))
                return field;
        }
    }
    throw std::out_of_range("No field found for the given coordinates.");
}
