#pragma once 


#include <random>

class RandomNumber{
    public:

    RandomNumber();

    private:

    // Mersenne Twister pseudo-random generator of 32 bit numbers 
    std::mt19937 m_rand_engine;

};