#pragma once

#include <random>

class Random
{
private:
    std::random_device _rd;
    std::mt19937 _seed;

public:
    Random();

    double GenerateDouble(double lower, double upper);

    float GenerateFloat(float lower, float upper);
};
    
