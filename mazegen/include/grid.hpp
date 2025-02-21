#ifndef MAZEGEN_GRID_HPP
#define MAZEGEN_GRID_HPP

#include <vector>

#include "cell.hpp"
#include "config.hpp"

namespace mazegen
{
    class Grid{
        public:

        Grid(const GridConfig& gc);

        private:

        // private member functions
        void init();

        // data members 
        int m_rows;
        int m_cols;

        std::vector<Cell> m_grid;

    };

}   // end namespace mazegen

#endif // MAZEGEN_GRID_HPP