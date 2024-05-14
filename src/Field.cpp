#include <Field.hpp>

Field::Field(int x0, int y0, int x1, int y1) : x0(x0), y0(y0), x1(x1), y1(y1) {}

Field::Field(char symbol) : symbol(symbol) {}

Field::Field() = default;
