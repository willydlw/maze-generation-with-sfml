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
        // left and right border shapes
        sf::RectangleShape verticalBorder(sf::Vector2f{static_cast<float>(mWallThickness), 
                static_cast<float>(mWallLength * mRows + 2 * mWallThickness)});

        verticalBorder.setFillColor(sf::Color{255, 255, 0});

        // left border
        verticalBorder.setPosition(sf::Vector2f{0.0f, 0.0f});
        window.draw(verticalBorder);

        // right border
        verticalBorder.setPosition(sf::Vector2f{static_cast<float>(window.getSize().x - mWallThickness), 0.0f});
        window.draw(verticalBorder);

        // top and bottom border shape
        sf::RectangleShape horizontalBorder({static_cast<float>(mWallLength * mCols + 2 * mWallThickness), 
                static_cast<float>(mWallThickness)});

        horizontalBorder.setFillColor(sf::Color{0,0,255} );

        // top border
        horizontalBorder.setPosition(sf::Vector2f{0.0f, 0.0f});
        window.draw(horizontalBorder);

        // bottom border
        horizontalBorder.setPosition(sf::Vector2f{0.0f, 
                static_cast<float>(window.getSize().y - mWallThickness)});
        window.draw(horizontalBorder);

        sf::RectangleShape rightWall(sf::Vector2f{static_cast<float>(mWallThickness), static_cast<float>(mCellSize)});
        rightWall.setFillColor(CELLCOLORS::WALL);


        sf::RectangleShape downWall(sf::Vector2f{static_cast<float>(mCellSize), static_cast<float>(mWallThickness)});
        downWall.setFillColor(CELLCOLORS::WALL);


        for(int r = 0; r < mRows; r++){
            for(int c = 0; c < mCols; c++){
                int i = r * mCols + c;
                
                if(mGrid[i].state & Cell::DOWN_WALL){
                    float x = static_cast<float>(c * mCellSize + mWallThickness);
                    float y = static_cast<float>((r+1) * mCellSize);

                    downWall.setPosition(sf::Vector2f{x, y});
                    window.draw(downWall);
                }

                if(mGrid[i].state & Cell::RIGHT_WALL){
                    float x = static_cast<float>( (c + 1) * mCellSize);
                    float y = static_cast<float>(r * mCellSize + mWallThickness);
                    rightWall.setPosition(sf::Vector2f{x, y});
                    window.draw(rightWall);
                }
            }
        }
    }

} // end namespace mazegen