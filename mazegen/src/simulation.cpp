#include "simulation.hpp"

#include <fstream>
#include <iostream>
#include <optional>

namespace mazegen
{
    Simulation::Simulation(const char* configFileName)
    {
        loadConfig(configFileName);
    }

    void Simulation::init(const SimConfig& sc)
    {
        dfs = DFS(sc.mc);
        m_window.create(sf::VideoMode({sc.window_width, sc.window_height}), "Maze Generation");  
    }

    void Simulation::loadConfig(const char* configFileName)
    {
        SimConfig simconfig;
        std::ifstream ifs(configFileName);

        if(!ifs.is_open()){
            std::cerr << "ERROR, " << __func__ << ", failed to open file: "
                << configFileName << ", using default configuration\n";
            simconfig = SimConfig();
        }

        ifs >> simconfig.window_width >> simconfig.window_height;



        ifs.close();

        init(simconfig);
    }

    void Simulation::run()
    {
        while(m_window.isOpen())
        {
            while(const std::optional event = m_window.pollEvent())
            {
                if(event->is<sf::Event::Closed>()){
                    m_window.close();
                }
            }

            m_window.clear(sf::Color::Black);
            dfs.draw(m_window);
            m_window.display();
        }
    }
}