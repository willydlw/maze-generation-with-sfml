#ifndef MAZEGEN_SIMCONFIG_HPP
#define MAZEGEN_SIMCONFIG_HPP

#include <SFML/Graphics/Color.hpp>

namespace mazegen
{
    // Main Window Size
    constexpr unsigned int SIMULATION_WINDOW_WIDTH = 800U;
    constexpr unsigned int SIMULATION_WINDOW_HEIGHT = 800U;

    //


    namespace MAZE
    {
        // Grid Defaults
        constexpr int DEFAULT_ROWS = 10;
        constexpr int DEFAULT_COLS = 10;

        // Maze Drawing Defaults
        constexpr int DEFAULT_WALL_THICKNESS = 4;
        constexpr int DEFAULT_CELL_SIZE = 40;

    }

    struct MazeConfig {

        int rows;
        int cols;
        int cellSize;
        int wallThickness;

        MazeConfig( int numRows = MAZE::DEFAULT_ROWS, 
                    int numCols = MAZE::DEFAULT_COLS, 
                    int cellSize = MAZE::DEFAULT_CELL_SIZE, 
                    int wallThickness = MAZE::DEFAULT_WALL_THICKNESS) : 
                    rows(numRows), 
                    cols(numCols), 
                    cellSize(cellSize), 
                    wallThickness(wallThickness) { }

    };
        

    struct SimConfig{
        unsigned int window_width;
        unsigned int window_height;
        MazeConfig mc;

        SimConfig(int width = SIMULATION_WINDOW_WIDTH, 
                    int height = SIMULATION_WINDOW_HEIGHT) : 
                    window_width(width),
                    window_height(height) { }
    };

    
    

}   // end namespace mazegen


#endif // MAZEGEN_SIMCONFIG_HPP