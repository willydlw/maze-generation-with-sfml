#ifndef CELL_H_INCLUDED
#define CELL_H_INCLUDED

#include <SFML/Graphics/Color.hpp>

struct Cell{
    int row;
    int col;

    bool visited;
    bool rightWall;
    bool downWall;
    
    sf::Color color;

    Cell( ) : row(0), col(0), visited(false), rightWall(true), downWall(true) {}
    Cell(int r, int c) : row(r), col(c), visited(false), 
            rightWall(true), downWall(true) {}
};


#endif 