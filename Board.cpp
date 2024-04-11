#include "Board.h"
#include <iostream>

Board::Board() {
    boardState.resize(9, 0); // Initialize board to empty
}

void Board::draw() {
    // Render the game board using OpenGL commands
}