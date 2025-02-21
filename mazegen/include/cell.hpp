#ifndef MAZEGEN_CELL_HPP
#define MAZEGEN_CELL_HPP

#include <SFML/Graphics/Color.hpp>

namespace mazegen{

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

} // end namespace mazegen


#endif // MAZEGEN_CELL_HPP