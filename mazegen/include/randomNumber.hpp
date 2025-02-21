#ifndef MAZEGEN_RANDOMNUMBER_HPP
#define MAZEGEN_RANDOMNUMBER_HPP

#include <random>

namespace mazegen{

    class RandomNumber{
        public:

        RandomNumber();

        int get_random(int min, int max);

        private:

        // Mersenne Twister pseudo-random generator of 32 bit numbers 
        std::mt19937 m_rand_engine;

    };

} // end namespace


#endif // MAZEGEN_RANDOMNUMBER_HPP