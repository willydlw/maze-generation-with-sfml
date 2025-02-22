#ifndef MAZEGEN_MAZE_HPP
#define MAZEGEN_MAZE_HPP

#include <vector>

#include "cell.hpp"
#include "simconfig.hpp"

namespace mazegen
{
    class Maze{
        public:

        Maze(const MazeConfig& mc);

        TODO: Complete draw function
        void draw(void);

        private:

        // private member functions
        void init();

        // data members 
        int m_rows;
        int m_cols;
        int m_totalCells;           // Yes, this takes extra memory but reduces the number of 
                                    // multiplications of m_rows * m_cols in the simulation          

        std::vector<Cell> m_grid;

    };

}   // end namespace mazegen

#endif // MAZEGEN_GRID_HPP