#ifndef MAZEGEN_DFS_HPP
#define MAZEGEN_DFS_HPP

#include "maze.hpp"

namespace mazegen
{
    class DFS : public Maze
    {

        public:

        DFS(const MazeConfig& mc);

    };

} // end namespace mazegen

#endif // MAZEGEN_DFS_HPP