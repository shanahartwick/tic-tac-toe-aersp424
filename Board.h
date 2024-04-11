#pragma once

#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
    Board();

    void draw();

private:
    std::vector<int> boardState; // 0 for empty, 1 for X, 2 for O
};

#endif // BOARD_H