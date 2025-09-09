#pragma once

#include <deque>
#include <utility>

#include <glm/glm.hpp>

#include "random.h"

class Fruit
{
public:
    std::deque<std::pair<int, glm::mat4>> fruitList;
    Random random;
private:
    double _currentTime, _lastTimeMoved, _spawnTime,
    _timeFromLastApple, _appleSpawnTime;

public:
    Fruit();

    void Move();
    void Spawn();
    void Delete();
};
