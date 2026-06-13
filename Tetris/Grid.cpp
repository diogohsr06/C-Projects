#include "Grid.hpp"
#include <iostream>

Grid::Grid() {
    rows = 20;
    cols = 10;
    cellSize = 30;
    init();
}

void Grid::init() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = 0;
        }
    }
}

void Grid::Print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}