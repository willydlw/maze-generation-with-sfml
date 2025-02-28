#ifndef MAZEGEN_SIMCONFIG_HPP
#define MAZEGEN_SIMCONFIG_HPP

#include <SFML/Graphics/Color.hpp>

namespace mazegen
{
    namespace SIM_DEFAULT
    {
        // Maze 
        constexpr int ROWS = 10;
        constexpr int COLS = 10;
        constexpr int CELL_SIZE = 40;

        constexpr int WALL_THICKNESS = 4;
        
        constexpr int MAZE_WIDTH = COLS * CELL_SIZE;
        constexpr int MAZE_HEIGHT = ROWS * CELL_SIZE;

        // User Interface
        constexpr int UI_WIDTH = 200;

        // Main Window 
        constexpr unsigned int MAIN_WINDOW_WIDTH = MAZE_WIDTH + UI_WIDTH;
        constexpr unsigned int MAIN_WINDOW_HEIGHT = MAZE_HEIGHT;


        // Framerate default
        constexpr unsigned int FRAMERATE = 5;
    }


    struct MazeConfig {

        int rows;
        int cols;
        int cellSize;
        int wallThickness;

        MazeConfig( int numRows = SIM_DEFAULT::ROWS, 
                    int numCols = SIM_DEFAULT::COLS, 
                    int cellSize = SIM_DEFAULT::CELL_SIZE, 
                    int wallThickness = SIM_DEFAULT::WALL_THICKNESS) : 
                    rows(numRows), 
                    cols(numCols), 
                    cellSize(cellSize), 
                    wallThickness(wallThickness) { }
        
        friend std::ostream& operator << (std::ostream& os, const MazeConfig& obj)
        {
            os  << "rows: " << obj.rows 
                << ", cols: " << obj.cols 
                << ", cell size: " << obj.cellSize 
                << ", wall thickness: " << obj.wallThickness 
                << "\n";

            return os;
        }

    };
        

    struct SimConfig{
        unsigned int window_width;
        unsigned int window_height;
        unsigned int framerate;
        MazeConfig mc;

        SimConfig(  unsigned int width = SIM_DEFAULT::MAIN_WINDOW_WIDTH, 
                    unsigned int height = SIM_DEFAULT::MAIN_WINDOW_HEIGHT,
                    unsigned int framerate = SIM_DEFAULT::FRAMERATE) : 
                    window_width(width),
                    window_height(height),
                    framerate(framerate) { }

        friend std::ostream& operator << (std::ostream& os, const SimConfig& obj)
        {
            os << "window width: " << obj.window_width 
                << ", window height: " << obj.window_height 
                << ", framerate: " << obj.framerate << '\n'
                << obj.mc << '\n';
            
            return os;
        }
    };

    
    

}   // end namespace mazegen


#endif // MAZEGEN_SIMCONFIG_HPP