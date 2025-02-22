#ifndef MAZEGEN_DFS_HPP
#define MAZEGEN_DFS_HPP

#include "maze.hpp"

#include <stack>

namespace mazegen
{
    class DFS : public Maze
    {

        public:

        DFS();

        DFS(const MazeConfig& mc);

        private:

        std::stack<Cell*> searchStack;

    };

} // end namespace mazegen

#endif // MAZEGEN_DFS_HPP