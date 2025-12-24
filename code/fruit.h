#pragma once

#include <deque>
#include <map>
#include <utility>

#include <glm/glm.hpp>

#include "random.h"

enum class fruitType
{
    apple = 0, coconut = 1
};

class Fruit
{
public:
    std::deque<std::pair<fruitType, glm::mat4>> fruitList;
    Random random;
private:
    double _currentTime, _lastTimeMoved, _lastCoconutSpawnIntervalDecrease;
    std::map<fruitType, double> _lastSpawnTime;
    std::map<fruitType, double> _spawnInterval;
    std::map<fruitType, std::pair<double, double>> _spawnIntervalRange;

public:
    Fruit();

    void Move();
    void Spawn();
    void Delete();
};
