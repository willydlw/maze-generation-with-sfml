#include "grid.hpp"

namespace mazegen{

    Grid::Grid(const GridConfig& gc) : m_rows(gc.rows), m_cols(gc.cols)
    {
        m_rows = gc.rows;
        m_cols = gc.cols;
        m_grid = std::vector<Cell>(m_rows * m_cols);

    }

    void Grid::init(void)
    {
        for(int r = 0; r < m_rows; r++){
            for(int c = 0; c < m_cols; c++){
                m_grid[r * m_cols + c] = Cell(r,c);
            }
        }
    }

} // end namespace mazegen