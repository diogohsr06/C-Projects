#pragma once

class Grid {
    public:
        Grid();
        void init();
        void Print();
        int grid[20][10];
    private:
        int rows;
        int cols;
        int cellSize;
};