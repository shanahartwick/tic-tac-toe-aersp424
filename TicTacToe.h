#pragma once

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "Board.h"

class TicTacToe {
public:
    TicTacToe();
    void play();

private:
    Board board;
    int turn;

    int getMove() const;
};

#endif // TICTACTOE_H

