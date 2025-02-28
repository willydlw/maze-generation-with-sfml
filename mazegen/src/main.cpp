#include "simulation.hpp"

int main(void)
{
    mazegen::Simulation sim("defaultConfig.txt");
    sim.run();
    return 0;
}