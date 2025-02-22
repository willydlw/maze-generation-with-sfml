#include "maze.hpp"

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

        for(int r = 0; r < mRows; r++){
            for(int c = 0; c < mCols; c++){
                int i = r * mCols + c;

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