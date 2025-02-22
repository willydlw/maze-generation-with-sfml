#include "maze.hpp"

#include <iostream>

namespace mazegen{

    Maze::Maze()
    {
        // what goes here?
    }

    Maze::Maze(const MazeConfig& mc) : 
                mRows(mc.rows), 
                mCols(mc.cols), 
                mWallLength(mc.cellSize),
                mWallThickness(mc.wallThickness),
                mCellSize(mc.cellSize)
    {
        init();
    }

    void Maze::init(void)
    {
        mGrid = std::vector<Cell>(mRows * mCols);

        for(int r = 0; r < mRows; r++){
            for(int c = 0; c < mCols; c++){
                mGrid[r * mCols + c] = Cell(r,c);
            }
        }
    }

    void Maze::draw(sf::RenderWindow& window)
    {
        sf::RectangleShape vertWall(sf::Vector2f{static_cast<float>(mWallThickness), static_cast<float>(mWallLength)});
        vertWall.setFillColor(CELLCOLORS::WALL);

        sf::RectangleShape horzWall(sf::Vector2f{static_cast<float>(mWallLength), static_cast<float>(mWallThickness)});
        horzWall.setFillColor(CELLCOLORS::WALL);


        static int count = 0;
        if(count == 0){
            std::cerr << __func__ << ", ready to draw lines\n";
            count++;
        }

        for(int r = 0; r < mRows; r++){
            for(int c = 0; c < mCols; c++){
                int i = r * mCols + c;
                static int printCount = 0;
                if(printCount == 0)
                {
                    std::cerr << "i: " << i << ", state: " << mGrid[i].state << "\n";
                    printCount++;
                }

                if(mGrid[i].state & Cell::DOWN_WALL){
                    float x = static_cast<float>(c * mCellSize);
                    float y = static_cast<float>(r * mCols + mCellSize);
                    horzWall.setPosition(sf::Vector2f{x, y});
                    window.draw(horzWall);
                }

                if(mGrid[i].state & Cell::RIGHT_WALL){
                    float x = static_cast<float>(c * mCellSize);
                    float y = static_cast<float>(r * mCols + mCellSize);
                    vertWall.setPosition(sf::Vector2f{x, y});
                    window.draw(vertWall);
                }
            }
        }
    }

} // end namespace mazegen