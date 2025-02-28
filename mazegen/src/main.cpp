#include "simulation.hpp"

int main(void)
{
    mazegen::Simulation sim("mazegen/config/wrongConfig.txt");
    sim.run();
    return 0;
}