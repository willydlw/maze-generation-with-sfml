#include "simulation.hpp"

int main(void)
{
    mazegen::Simulation sim("configFileName");
    sim.run();
    return 0;
}