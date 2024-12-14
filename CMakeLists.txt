cmake_minimum_required(VERSION 3.10)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(tetris src/main.cpp src/game.cpp src/board.cpp src/pieces.cpp)
