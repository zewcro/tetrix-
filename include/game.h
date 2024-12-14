#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "pieces.h"

class TetrisGame {
public:
    TetrisGame();
    void run();

private:
    void processInput();
    void update();
    void render();

    Board board;
    Pieces currentPiece;
    bool isRunning;
};

#endif // GAME_H
