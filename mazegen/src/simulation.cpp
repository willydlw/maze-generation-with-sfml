#include "simulation.hpp"

#include <fstream>
#include <iostream>

namespace mazegen
{
    Simulation::Simulation(const char* configFileName)
    {
        loadConfig(configFileName);
        init();
    }

    void Simulation::init()
    {
       
    }

    void Simulation::loadConfig(const char* configFileName)
    {
        std::ifstream ifs(configFileName);

        if(!ifs.is_open()){
            std::cerr << "ERROR, " << __func__ << ", failed to open file: "
                << configFileName << ", using default configuration\n";
        }



        ifs.close();
    }

    void Simulation::run()
    {

    }
}