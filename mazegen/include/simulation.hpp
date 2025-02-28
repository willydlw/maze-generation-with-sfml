#ifndef MAZEGEN_SIMULATION_HPP
#define MAZEGEN_SIMULATION_HPP

/////////////////////////////////
// Headers
/////////////////////////////////
#include <SFML/Graphics.hpp>

#include "simconfig.hpp"
#include "dfs.hpp"

namespace mazegen
{
    class Simulation{

    public:
        explicit Simulation(const char* configFileName = "defaultConfigFile.txt");

        ~Simulation();

        void run();

    private:

        void init(const SimConfig& sc);
        void loadConfig(const char* configFileName);


        // SFML data
        int m_frameRate;
        sf::RenderWindow m_window;

        // maze algorithm objects
        DFS dfs;

    };

}



#endif // MAZEGEN_SIMULATION_HPP