#pragma once

struct GridConfig {

    static constexpr int DEFAULT_ROWS = 10;
    static constexpr int DEFAULT_COLS = 10;
    static constexpr int DEFAULT_CELL_SIZE = 40;
    static constexpr int DEFAULT_WALL_THICKNESS = 4;

    int rows;
    int cols;
    int cellSize;
    int wallThickness;

    explicit GridConfig(int numRows = DEFAULT_ROWS, 
                        int numCols = DEFAULT_COLS, 
                        int cellSize = DEFAULT_CELL_SIZE, 
                        int wallThickness = DEFAULT_WALL_THICKNESS) : 
                        rows(numRows), 
                        cols(numCols), 
                        cellSize(cellSize), 
                        wallThickness(wallThickness) { }

};