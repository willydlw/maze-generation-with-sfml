#include "randomNumber.hpp"

namespace mazegen{

    RandomNumber::RandomNumber() : m_rand_engine(std::random_device{}())
    {

    }

    int RandomNumber::get_random(int min, int max)
    {
        std::uniform_int_distribution<int> distribution(min, max);
        return distribution(m_rand_engine);
    }

} // end namespace mazegen
