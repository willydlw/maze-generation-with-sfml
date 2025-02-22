#ifndef MAZEGEN_MAZE_HPP
#define MAZEGEN_MAZE_HPP

#include <SFML/Graphics.hpp>

#include <vector>

#include "cell.hpp"
#include "simconfig.hpp"

namespace mazegen
{
    class Maze{
    public:

        // constructors
        Maze();
        Maze(const MazeConfig& mc);

       
        void draw(sf::RenderWindow& window);

    private:

        // private member functions
        void init();

        // grid size data members 
        int mRows;
        int mCols;

        // drawing data members
        int mWallLength;
        int mWallThickness;
        int mCellSize;


        std::vector<Cell> mGrid;

    };

}   // end namespace mazegen

#endif // MAZEGEN_GRID_HPP