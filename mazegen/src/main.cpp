#include "simulation.hpp"

int main(void)
{
    mazegen::Simulation sim("./config/defaultConfig.txt");
    sim.run();
    return 0;
}