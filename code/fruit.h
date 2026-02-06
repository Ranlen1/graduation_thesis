#pragma once

#include <deque>
#include <map>
#include <utility>

#include <glm/glm.hpp>

#include "random.h"

//Tento class urcuje typy ovoce ve hře
enum class FruitType
{
    apple = 0, coconut = 1
};

//Tento struct udržuje všechny potřebné attributy ovoce pohromadě
struct fruitAttributes
{
    FruitType type;
    glm::mat4 transform;
    float speed;
};

class Fruit
{
public:
    static std::deque<fruitAttributes> fruitList;
    static std::map<FruitType, std::pair<double, double>> _spawnIntervalRange;
private:
    Random random;
    double _currentTime, _lastTimeMoved, _lastCoconutSpawnIntervalDecrease;
    std::map<FruitType, double> _lastSpawnTime;
    std::map<FruitType, double> _spawnInterval;
    std::map<FruitType, std::pair<double, double>> _speedIntervalRange;

public:
    Fruit();

    //Tyto funkce dělají následovně: Pohybují ovocem, vytvářejí ovoce, mažou ovoce a resetují hru
    void Move();
    void Spawn();
    void Delete();
    void GameRestart();
};
