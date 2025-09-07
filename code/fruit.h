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
    double _currentTime, _lastTime, _spawnTime;
    bool _spawn;
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<float> dis;

public:
    Fruit();

    void Move();
    void Spawn();
    void Delete();
};
