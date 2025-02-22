#ifndef MAZEGEN_CELL_HPP
#define MAZEGEN_CELL_HPP

#include <SFML/Graphics/Color.hpp>

namespace mazegen{

    namespace CELLCOLORS
    {
            const sf::Color WALL(0,0,0);
            const sf::Color START(100, 255, 0);
            const sf::Color CURRENT(120, 120, 45);
    }

    struct Cell{

        static constexpr unsigned int RIGHT_WALL = 0x1;
        static constexpr unsigned int DOWN_WALL = 0x2;
        static constexpr unsigned int VISITED = 0x4;
        static constexpr unsigned int INIT_STATE = RIGHT_WALL | DOWN_WALL; 


        int row;
        int col;

        unsigned int state;

        sf::Color color;

        Cell() : row(0), col(0), state(INIT_STATE) {}
        Cell(int r, int c) : row(r), col(c), state(INIT_STATE) {}
    };

} // end namespace mazegen


#endif // MAZEGEN_CELL_HPP