// tic-tac-toe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <vector>

// Function prototypes
void printBoard(const std::vector<char>& board);
int getPlayerChoice(const std::vector<char>& board);
bool makeMove(std::vector<char>& board, int choice, char currentPlayer);
bool checkWin(const std::vector<char>& board, char currentPlayer);
bool checkDraw(const std::vector<char>& board);

int main() {
    std::vector<char> board(9, ' ');
    char currentPlayer = 'X';
    bool gameEnded = false;

    while (!gameEnded) {
        printBoard(board);
        int choice = getPlayerChoice(board);
        gameEnded = makeMove(board, choice, currentPlayer);

        if (gameEnded) {
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            break;
        }
        else if (checkDraw(board)) {
            std::cout << "The game is a draw!" << std::endl;
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    printBoard(board);
    return 0;
}

void printBoard(const std::vector<char>& board) {
    std::cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        std::cout << " " << board[i] << " | " << board[i + 1] << " | " << board[i + 2] << "\n";
        if (i < 6) {
            std::cout << "-----------\n";
        }
    }
    std::cout << "\n";
}

int getPlayerChoice(const std::vector<char>& board) {
    while (true) {
        std::cout << "Enter your move (1-9): ";
        int choice;
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > 9 || board[choice - 1] != ' ') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid move, try again.\n";
        }
        else {
            return choice;
        }
    }
}

bool makeMove(std::vector<char>& board, int choice, char currentPlayer) {
    board[choice - 1] = currentPlayer;
    return checkWin(board, currentPlayer);
}

bool checkWin(const std::vector<char>& board, char currentPlayer) {
    const int WINNING_COMBOS[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };
    for (const auto& combo : WINNING_COMBOS) {
        if (board[combo[0]] == currentPlayer &&
            board[combo[1]] == currentPlayer &&
            board[combo[2]] == currentPlayer) {
            return true;
        }
    }
    return false;
}

bool checkDraw(const std::vector<char>& board) {
    for (char cell : board) {
        if (cell == ' ') {
            return false;
        }
    }
    return true;
}
