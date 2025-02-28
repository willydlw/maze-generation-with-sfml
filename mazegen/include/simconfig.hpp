#ifndef MAZEGEN_SIMCONFIG_HPP
#define MAZEGEN_SIMCONFIG_HPP

#include <SFML/Graphics/Color.hpp>

namespace mazegen
{
    // Maze Drawing Defaults
    constexpr int DEFAULT_WALL_THICKNESS = 4;
    constexpr int DEFAULT_CELL_SIZE = 80;

    // Main Window Size
    constexpr unsigned int SIMULATION_WINDOW_WIDTH = 800U + 2U * DEFAULT_WALL_THICKNESS;
    constexpr unsigned int SIMULATION_WINDOW_HEIGHT = 800U + 2U * DEFAULT_WALL_THICKNESS;

    // Framerate default
    constexpr unsigned int SIMULATION_FRAMERATE = 60;

   
    // Grid Size Defaults
    constexpr int DEFAULT_ROWS = 10;
    constexpr int DEFAULT_COLS = 10;

 

    struct MazeConfig {

        int rows;
        int cols;
        int cellSize;
        int wallThickness;

        MazeConfig( int numRows = DEFAULT_ROWS, 
                    int numCols = DEFAULT_COLS, 
                    int cellSize = DEFAULT_CELL_SIZE, 
                    int wallThickness = DEFAULT_WALL_THICKNESS) : 
                    rows(numRows), 
                    cols(numCols), 
                    cellSize(cellSize), 
                    wallThickness(wallThickness) { }

    };
        

    struct SimConfig{
        unsigned int window_width;
        unsigned int window_height;
        unsigned int framerate;
        MazeConfig mc;

        SimConfig(  unsigned int width = SIMULATION_WINDOW_WIDTH, 
                    unsigned int height = SIMULATION_WINDOW_HEIGHT,
                    unsigned int framerate = SIMULATION_FRAMERATE) : 
                    window_width(width),
                    window_height(height),
                    framerate(framerate) { }
    };

    
    

}   // end namespace mazegen


#endif // MAZEGEN_SIMCONFIG_HPP