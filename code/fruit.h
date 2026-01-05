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

struct fruitAttributes
{
    fruitType type;
    glm::mat4 transform;
    float speed;
};

class Fruit
{
public:
    static std::deque<fruitAttributes> fruitList;
    static std::map<fruitType, std::pair<double, double>> _spawnIntervalRange;
private:
    Random random;
    double _currentTime, _lastTimeMoved, _lastCoconutSpawnIntervalDecrease;
    std::map<fruitType, double> _lastSpawnTime;
    std::map<fruitType, double> _spawnInterval;
    std::map<fruitType, std::pair<double, double>> _speedIntervalRange;

public:
    Fruit();

    void Move();
    void Spawn();
    void Delete();
    void GameRestart();
};
