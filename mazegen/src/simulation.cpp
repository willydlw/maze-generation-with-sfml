#include "simulation.hpp"

#include "imgui.h"              // necessary for ImGui::*, imgui-SFML.h doesn't include imgui.h 
#include "imgui-SFML.h"         // for ImGui::SFML::* functions and SFML-specific overloads

#include <fstream>
#include <iostream>
#include <optional>
#include <cstdlib>              // EXIT_FAILURE

namespace mazegen
{
    Simulation::Simulation(const char* configFileName)
    {
        loadConfig(configFileName);
    }

    Simulation::~Simulation()
    {
        ImGui::SFML::Shutdown();
    }

    void Simulation::init(const SimConfig& sc)
    {
        dfs = DFS(sc.mc);
        m_window.create(sf::VideoMode({sc.window_width, sc.window_height}), "Maze Generation");  
        m_window.setFramerateLimit(m_frameRate);

        if(!ImGui::SFML::Init(m_window))
        {
            std::cerr << "FATAL ERROR, " << __func__ << ", failed ImGui init\n";
            exit(EXIT_FAILURE);
        }
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

        // TODO: add input stream error checking
        ifs >> simconfig.window_width >> simconfig.window_height;
        ifs >> simconfig.framerate;

        ifs.close();

        init(simconfig);
    }


    void Simulation::run()
    {
        sf::Clock deltaClock;

        while(m_window.isOpen())
        {
            while(const auto event = m_window.pollEvent())
            {
                ImGui::SFML::ProcessEvent(m_window, *event);

                if(event->is<sf::Event::Closed>()){
                    m_window.close();
                }
            }

            ImGui::SFML::Update(m_window, deltaClock.restart());

            ImGui::Begin("Hello, world!");
            ImGui::Button("Look at this pretty button");
            ImGui::End();

            m_window.clear(sf::Color::Black);
            dfs.draw(m_window);
            ImGui::SFML::Render(m_window);
            m_window.display();
        }
    }
}