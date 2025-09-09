#include "random.h"
#include <random>

Random::Random()
    : _seed(_rd()) {}

double Random::GenerateDouble(double lower, double upper)
{
    std::uniform_real_distribution<double> dist(lower, upper);
    
    return dist(_seed);
}

float Random::GenerateFloat(float lower, float upper)
{
    std::uniform_real_distribution<float> dist(lower, upper);
    
    return dist(_seed);
}


