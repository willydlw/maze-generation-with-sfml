#ifndef MAZEGEN_SIMULATION_HPP
#define MAZEGEN_SIMULATION_HPP

/////////////////////////////////
// Headers
/////////////////////////////////
#include <SFML/Graphics.hpp>

#include "config.hpp"

namespace mazegen
{
    class Simulation{

    public:
        explicit Simulation(const char* configFileName = "defaultConfigFile.txt");

        void run();

    private:

        void init(const SimConfig& sc);
        void loadConfig(const char* configFileName);

        sf::RenderWindow m_window;



};

}



#endif // MAZEGEN_SIMULATION_HPP