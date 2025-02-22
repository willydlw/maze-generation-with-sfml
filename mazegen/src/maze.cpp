#include "maze.hpp"

namespace mazegen{

    Maze::Maze(const MazeConfig& mc) : m_rows(mc.rows), m_cols(mc.cols)
    {
        init();
    }

    void Maze::init(void)
    {
        m_grid = std::vector<Cell>(m_rows * m_cols);

        for(int r = 0; r < m_rows; r++){
            for(int c = 0; c < m_cols; c++){
                m_grid[r * m_cols + c] = Cell(r,c);
            }
        }
    }

    void Maze::draw(void)
    {
        
    }

} // end namespace mazegen