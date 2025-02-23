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
        sf::RectangleShape leftBorder(sf::Vector2f{static_cast<float>(mWallThickness), 
                static_cast<float>(mWallLength * mRows)});

        leftBorder.setFillColor(sf::Color{255, 255, 0});

        leftBorder.setPosition(sf::Vector2f{0.0f, 0.0f});
        window.draw(leftBorder);

        sf::RectangleShape bottomBorder({static_cast<float>(mWallLength * mCols), 
                static_cast<float>(mWallThickness)});

        bottomBorder.setFillColor(sf::Color{0,0,255} );
        bottomBorder.setPosition(sf::Vector2f{0.0f, 
                static_cast<float>(window.getSize().y - mWallThickness)});
        window.draw(bottomBorder);

        sf::RectangleShape vertWall(sf::Vector2f{static_cast<float>(mWallThickness), static_cast<float>(mCellSize)});
        vertWall.setFillColor(CELLCOLORS::WALL);


        sf::RectangleShape horzWall(sf::Vector2f{static_cast<float>(mCellSize), static_cast<float>(mWallThickness)});
        horzWall.setFillColor(CELLCOLORS::WALL);

        static int printCount = 0;

        for(int r = 0; r < mRows; r++){
            for(int c = 0; c < mCols; c++){
                int i = r * mCols + c;
                
                if(mGrid[i].state & Cell::DOWN_WALL){
                    //float x = static_cast<float>(c * mCellSize);
                    //float y = static_cast<float>(r * mCols + mCellSize);

                    //if(printCount == 0)
                    //std::cerr << "horzWall, r: " << r << ", c: " << c
                    //    << ", x: " << x << ", y: " << y << "\n";

                    //horzWall.setPosition(sf::Vector2f{x, y});
                    //window.draw(horzWall);
                }

                if(mGrid[i].state & Cell::RIGHT_WALL){
                    float x = static_cast<float>( (c + 1) * mCellSize);
                    float y = static_cast<float>(r * mCellSize + mWallThickness);
                    vertWall.setPosition(sf::Vector2f{x, y});
                    window.draw(vertWall);
                }
            }
        }

        printCount++;
    }

} // end namespace mazegen