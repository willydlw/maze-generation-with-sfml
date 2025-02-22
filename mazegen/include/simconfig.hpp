#ifndef MAZEGEN_CONFIG_HPP
#define MAZEGEN_CONFIG_HPP

namespace mazegen{

    struct MazeConfig {

    static constexpr int DEFAULT_ROWS = 10;
    static constexpr int DEFAULT_COLS = 10;
    static constexpr int DEFAULT_CELL_SIZE = 40;
    static constexpr int DEFAULT_WALL_THICKNESS = 4;

    int rows;
    int cols;
    int cellSize;
    int wallThickness;

    MazeConfig  (int numRows = DEFAULT_ROWS, 
                int numCols = DEFAULT_COLS, 
                int cellSize = DEFAULT_CELL_SIZE, 
                int wallThickness = DEFAULT_WALL_THICKNESS) : 
                    rows(numRows), 
                    cols(numCols), 
                    cellSize(cellSize), 
                    wallThickness(wallThickness) { }

    };


    struct SimConfig{
        static constexpr unsigned int SIMULATION_WINDOW_WIDTH = 800U;
        static constexpr unsigned int SIMULATION_WINDOW_HEIGHT = 800U;

        unsigned int window_width;
        unsigned int window_height;
        MazeConfig mc;


        SimConfig(int width = SIMULATION_WINDOW_WIDTH, 
                    int height = SIMULATION_WINDOW_HEIGHT) : 
                    window_width(width),
                    window_height(height)
        {}
    };

}   // end namespace mazegen


#endif // MAZEGEN_CONFIG_HPP