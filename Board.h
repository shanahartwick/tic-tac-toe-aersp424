#pragma once

ifndef BOARD_H
#define BOARD_H

#include <vector>

enum Player { NONE = 0, PLAYER_X = 1, PLAYER_O = 2 };

class Board {
public:
    Board();
    void printBoard() const;
    bool makeMove(int row, int col, int turn);
    Player checkWinner() const;
    bool isBoardFull() const;

private:
    std::vector<std::vector<Player>> board;
    static const int BOARD_SIZE = 3;

    bool isValidMove(int row, int col) const;
};

