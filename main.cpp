#include <engine.hpp>

int main()
{
    Engine engine;
    engine.run();
    return 0;
}

/*
 * Game Design
 *
 * 2D array holding the values e.g.
 *
 * [['x', '', 'o'],
 * ['', 'x', 'o'],
 * ['', 'o', 'x']]
 *
 * where '' are empty fields on the board
 *
 *
 * Tracked position of the cursor defines where the figure will be placed.
 * lmb - X, rmb O (check if the circle is always first(?))
 * Whenever the user clicks within the boundaries, an appropriate figure is drawn
 *
 * Winning scenarios include 3 figures of the same shape to cross either:
 * - horizontally
 * - vertically
 * - diagonally
 *
 * Possible extensions of the game include using OpenCV and letting the user draw a figure.
 * That figure is then processed and the algorithm decides whenever it is an X or O.
 *
 *
 */
