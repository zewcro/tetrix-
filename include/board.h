#ifndef BOARD_H
#define BOARD_H

#include "pieces.h"
#include <vector>

class Board {
public:
    Board();
    void render() const;
    bool isGameOver() const;
    void lockPiece(const Tetromino& piece);
    bool isValidPosition(const Tetromino& piece) const;

private:
    std::vector<std::vector<int>> grid;
    static const int WIDTH = 10;
    static const int HEIGHT = 20;
};

#endif // BOARD_H
