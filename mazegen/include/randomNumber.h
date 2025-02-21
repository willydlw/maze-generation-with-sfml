#pragma once 


#include <random>

class RandomNumber{
    public:

    RandomNumber();

    int get_random(const int& i_value_max = INT_MAX, const int& i_value_min = INT_MIN);

    private:

    // Mersenne Twister pseudo-random generator of 32 bit numbers 
    std::mt19937 m_rand_engine;

};