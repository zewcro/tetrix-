#include "game.h"
#include <iostream>
#include <thread>
#include <chrono>

TetrisGame::TetrisGame() : isRunning(true), currentPiece() {}

void TetrisGame::run() {
    while (isRunning) {
        processInput();
        update();
        render();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void TetrisGame::processInput() {
    char input;
    if (std::cin.peek() != EOF) {
        std::cin >> input;
        if (input == 'q') isRunning = false;
        if (input == 'a') currentPiece.moveLeft(board);
        if (input == 'd') currentPiece.moveRight(board);
        if (input == 's') currentPiece.rotate(board);
    }
}

void TetrisGame::update() {
    if (!currentPiece.moveDown(board)) {
        board.lockPiece(currentPiece);
        currentPiece = PIECES();
        if (board.isGameOver()) isRunning = false;
    }
}

void TetrisGame::render() {
    system("clear"); 
    board.render();
    currentPiece.render();
}
