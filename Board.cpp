#include "Board.h"
#include <iostream>

Board::Board() {
    board.resize(BOARD_SIZE, std::vector<Player>(BOARD_SIZE, NONE));
}

void Board::printBoard() const {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            std::cout << (board[i][j] == PLAYER_X ? "X" : (board[i][j] == PLAYER_O ? "O" : "-"));
            if (j < BOARD_SIZE - 1)
                std::cout << "|";
        }
        std::cout << std::endl;
        if (i < BOARD_SIZE - 1)
            std::cout << "-----" << std::endl;
    }
}

bool Board::makeMove(int row, int col, int turn) {
    if (!isValidMove(row, col))
        return false;
    board[row][col] = (turn == 1 ? PLAYER_X : PLAYER_O);
    return true;
}

Player Board::checkWinner() const {
    // Check rows, columns, and diagonals
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (board[i][0] != NONE && board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return board[i][0]; // Row
        if (board[0][i] != NONE && board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return board[0][i]; // Column
    }
    if (board[0][0] != NONE && board[0][0] == board[1][1] && board[0][0] == board[2][2])
        return board[0][0]; // Diagonal
    if (board[0][2] != NONE && board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return board[0][2]; // Diagonal
    return NONE; // No winner
}

bool Board::isBoardFull() const {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == NONE)
                return false; // Board is not full
        }
    }
    return true; // Board is full
}

bool Board::isValidMove(int row, int col) const {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == NONE;
}
