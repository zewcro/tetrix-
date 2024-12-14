#include "board.h"
#include <iostream>

Board::Board() : grid(HEIGHT, std::vector<int>(WIDTH, 0)) {}

void Board::render() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << (cell ? "#" : ".");
        }
        std::cout << "\n";
    }
}

bool Board::isGameOver() const {
    for (const auto& cell : grid[0]) {
        if (cell != 0) return true;
    }
    return false;
}

void Board::lockPiece(const Tetromino& piece) {
    for (const auto& block : piece.getBlocks()) {
        grid[block.y][block.x] = 1;
    }
}

bool Board::isValidPosition(const Tetromino& piece) const {
    for (const auto& block : piece.getBlocks()) {
        if (block.x < 0 || block.x >= WIDTH || block.y >= HEIGHT || (block.y >= 0 && grid[block.y][block.x] != 0)) {
            return false;
        }
    }
    return true;
}
