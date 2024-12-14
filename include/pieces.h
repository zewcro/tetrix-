#ifndef PIECES_H
#define PIECES_H

#include <vector>
#include "board.h"

struct Block {
    int x, y;
};

class PIECES {
public:
    PIECES();
    std::vector<Block> getBlocks() const;
    void moveLeft(Board& board);
    void moveRight(Board& board);
    bool moveDown(Board& board);
    void rotate(Board& board);
    void render() const;

private:
    std::vector<Block> blocks;
};

#endif
