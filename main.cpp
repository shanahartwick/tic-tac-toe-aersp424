// tic-tac-toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TicTacToe.h"
#include "Board.h"

#include <iostream>

bool playAgain() {
    char choice;
    std::cout << "Do you want to play again? (y/n): ";
    std::cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

int main() {
    do {
        TicTacToe game;
        game.play();
    } while (playAgain());

    return 0;
}