#include <board.hpp>

Board::Board() = default;

void Board::drawBoard(sf::RenderWindow &window) const { // TODO: consider moving the drawing to the Engine class
    sf::RectangleShape horizontalRectangle1(sf::Vector2f(window.getSize().x, rectangleThickness));
    horizontalRectangle1.setFillColor(sf::Color::White);
    horizontalRectangle1.setPosition(horizontalRectangleX, horizontalRectangleOneY);

    sf::RectangleShape horizontalRectangle2(sf::Vector2f(window.getSize().x, rectangleThickness));
    horizontalRectangle2.setFillColor(sf::Color::White);
    horizontalRectangle2.setPosition(horizontalRectangleX, horizontalRectangleTwoY);

    sf::RectangleShape verticalRectangle1(sf::Vector2f(rectangleThickness, window.getSize().y));
    verticalRectangle1.setFillColor(sf::Color::White);
    verticalRectangle1.setPosition(verticalRectangleOneX, verticalRectangleY);

    sf::RectangleShape verticalRectangle2(sf::Vector2f(rectangleThickness, window.getSize().y));
    verticalRectangle2.setFillColor(sf::Color::White);
    verticalRectangle2.setPosition(verticalRectangleTwoX, verticalRectangleY);

    window.draw(horizontalRectangle1);
    window.draw(horizontalRectangle2);
    window.draw(verticalRectangle1);
    window.draw(verticalRectangle2);

    drawSymbols(window);
}



void Board::setFieldValues(char symbol, int mousePressedX, int mousePressedY) {
    Field &field = getFieldByCoordinates(mousePressedX, mousePressedY);
    if (field.symbol == ' ')
        field.symbol = symbol;
}

void Board::drawSymbols(sf::RenderWindow &window) const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            Field field = fields[i][j];

            sf::Text text;
            sf::Font font;
            font.loadFromFile("../fonts/arial.ttf"); // adjust the CWD to remove the ../

            text.setString(field.symbol);
            text.setFont(font);
            text.setCharacterSize(400);
            text.setPosition(field.x0 + 50, field.y0 - 150);
            text.setFillColor(field.color);

            window.draw(text);
        }
    }
}

void Board::resetFields() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            fields[i][j].symbol = ' ';
        }
    }
}

std::vector<std::vector<Field>> Board::getFields() const {
    return fields;
}


std::vector<char> Board::getRowSymbols(int rowIndex) const {
    std::vector<char> symbols = {fields[rowIndex][0].symbol, fields[rowIndex][1].symbol, fields[rowIndex][2].symbol};
    return symbols;
}


std::vector<char> Board::getColumnSymbols(int columnIndex) const {
    std::vector<char> symbols = {fields[0][columnIndex].symbol, fields[1][columnIndex].symbol, fields[2][columnIndex].symbol};
    return symbols;
}

bool Board::canWinDiagonally(int rowIndex, int columnIndex) const {
    if (rowIndex % 2 == 0 && columnIndex % 2 == 0)
        return true;
    else if (rowIndex == 1 && columnIndex == 1)
        return true;
    return false;

}

/*
 *
 * X O O | O O X
 * O X O | O X O
 * O O X | X O O
 *
 * e.g.
 *
 * X 0 X
 * 0 X 0
 * - - X
 *
 */

// TODO: optimize the diagonal win scenario
std::vector<char> Board::getDiagonalSymbols(int rowIndex, int columnIndex) const {
    std::vector<char> symbols = {' ', ' ', ' '};

    symbols[1] = fields[1][1].symbol; // set the middle field before any checks
    if (rowIndex == 0) {
        if (columnIndex == 0) { // TODO: move to a separate function
            symbols[0] = fields[rowIndex][columnIndex].symbol;
            symbols[2] = fields[rowIndex+2][columnIndex+2].symbol;
        }

        else if (columnIndex == 2) {
            symbols[0] = fields[rowIndex][columnIndex].symbol;
            symbols[2] = fields[rowIndex+2][columnIndex-2].symbol;
        }
    }

    else if (rowIndex == 2) {
        if (columnIndex == 0) {
            symbols[0] = fields[rowIndex][columnIndex].symbol;
            symbols[2] = fields[rowIndex-2][columnIndex+2].symbol;
        }

        else if (columnIndex == 2) {
            symbols[0] = fields[rowIndex][columnIndex].symbol;
            symbols[2] = fields[rowIndex-2][columnIndex-2].symbol;
        }
    }

    else if (columnIndex == 1) {
        symbols[0] = fields[rowIndex-1][columnIndex-1].symbol;
        symbols[2] = fields[rowIndex+1][columnIndex+1].symbol;
    }
    return symbols;
}

void Board::colorWinningSymbols(sf::RenderWindow &window) {
    std::vector<char> xWin(3, 'x');
    std::vector<char> yWin(3, 'o');

    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            auto rowSymbols = getRowSymbols(row);

            if ((rowSymbols == xWin) || (rowSymbols == yWin)) {
                // e.g. change the rowSymbols[0].color = sf::Color(255, 0, 0);
                // to display a red winning row
            }


            // check column winning scenario
            if ((getColumnSymbols(column) == xWin) || (getColumnSymbols(column) == yWin))
                return;

            // check diagonal winning scenario
            // The player can win diagonally and the middle part is also occupied by the player
            if (
                    (canWinDiagonally(row, column) && fields[1][1].symbol == 'x') ||
                    (canWinDiagonally(row, column) && fields[1][1].symbol == 'y')
                ) {
                if ((getDiagonalSymbols(row, column) == xWin) || (getDiagonalSymbols(row, column) == yWin))
                    return;
            }
        }
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
}



