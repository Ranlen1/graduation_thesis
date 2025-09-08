#pragma once

#include <deque>
#include <utility>
#include <random>

#include <glm/glm.hpp>

class Fruit
{
public:
    std::deque<std::pair<int, glm::mat4>> fruitList;
private:
    double _currentTime, _lastTimeMoved, _spawnTime;
    std::random_device _rd;
    std::mt19937 _seed;
    std::uniform_real_distribution<float> _fruitXCoordinate;
    std::uniform_real_distribution<double> _appleSpawnGenerator;
    double _appleSpawnTime, _timeFromLastApple;

public:
    Fruit();

    void Move();
    void Spawn();
    void Delete();
};
