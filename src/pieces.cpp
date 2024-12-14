#include "PIECES.h"
#include <iostream>

PIECES::PIECES() : blocks({{5, 0}, {5, 1}, {5, 2}, {6, 2}}) {}

std::vector<Block> PIECES::getBlocks() const {
    return blocks;
}

void PIECES::moveLeft(Board& board) {
    for (auto& block : blocks) block.x--;
    if (!board.isValidPosition(*this)) {
        for (auto& block : blocks) block.x++;
    }
}

void PIECES::moveRight(Board& board) {
    for (auto& block : blocks) block.x++;
    if (!board.isValidPosition(*this)) {
        for (auto& block : blocks) block.x--;
    }
}

bool PIECES::moveDown(Board& board) {
    for (auto& block : blocks) block.y++;
    if (!board.isValidPosition(*this)) {
        for (auto& block : blocks) block.y--;
        return false;
    }
    return true;
}

void PIECES::rotate(Board& board) {
    // Simplified rotation logic
    for (auto& block : blocks) {
        int temp = block.x;
        block.x = -block.y;
        block.y = temp;
    }
    if (!board.isValidPosition(*this)) {
        for (auto& block : blocks) {
            int temp = block.x;
            block.x = block.y;
            block.y = -temp;
        }
    }
}

void PIECES::render() const {
    for (const auto& block : blocks) {
        std::cout << "(" << block.x << ", " << block.y << ")";
    }
    std::cout << "\n";
}
