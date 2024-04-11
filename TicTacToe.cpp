#include "TicTacToe.h"

#include <iostream>

TicTacToe::TicTacToe() : turn(1) {
}

void TicTacToe::play() {
    board.printBoard();
    while (true) {
        if (!board.makeMove(getMove(), getMove(), turn)) {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }
        board.printBoard();
        Player winner = board.checkWinner();
        if (winner != NONE) {
            if (winner == PLAYER_X)
                std::cout << "Player X wins!" << std::endl;
            else
                std::cout << "Player O wins!" << std::endl;
            break;
        }
        else if (board.isBoardFull()) {
            std::cout << "It's a tie!" << std::endl;
            break;
        }
        turn = 3 - turn; // Toggle player turn
    }
}

int TicTacToe::getMove() const {
    int move;
    std::cout << "Player " << (turn == 1 ? "X" : "O") << ", enter your move (row and column): ";
    std::cin >> move;
    return move;
}
