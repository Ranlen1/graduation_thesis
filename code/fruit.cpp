#include "fruit.h"

#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

Fruit::Fruit()
    : _currentTime(glfwGetTime()), _lastTimeMoved(glfwGetTime()), _lastCoconutSpawnIntervalDecrease(glfwGetTime())
{
    _spawnIntervalRange[fruitType::apple] = {2.5, 4.5};
    _spawnIntervalRange[fruitType::coconut] = {5.0, 7.0};
    _spawnInterval[fruitType::apple] = random.GenerateDouble(_spawnIntervalRange[fruitType::apple].first, _spawnIntervalRange[fruitType::apple].second);
    _spawnInterval[fruitType::coconut] = random.GenerateDouble(_spawnIntervalRange[fruitType::coconut].first, _spawnIntervalRange[fruitType::coconut].second);
    _lastSpawnTime[fruitType::apple] = 0.0;
    _lastSpawnTime[fruitType::coconut] = 0.0;
}

void Fruit::Move()
{
    _currentTime = glfwGetTime();
    for(auto &[fruitType, trans] : fruitList)
    {
        trans = glm::translate(trans, glm::vec3(0.0f, -0.5f * float(_currentTime - _lastTimeMoved), 0.0f));
    }
    _lastTimeMoved = _currentTime;
}

void Fruit::Spawn()
{
    _currentTime = glfwGetTime();
    for(fruitType type : {fruitType::apple, fruitType::coconut})
    {

        if(_currentTime - _lastSpawnTime[type] > _spawnInterval[type])
        {
            glm::mat4 trans = glm::mat4(1.0f);
            trans = glm::translate(trans, glm::vec3(random.GenerateFloat(0.0f, 2.0f - 64.0f/800.0f), 0.0f, 0.0f));
            fruitList.push_back({type, trans});
        _lastSpawnTime[type] = _currentTime;
        _spawnInterval[type] = random.GenerateDouble(_spawnIntervalRange[type].first, _spawnIntervalRange[type].second);
        }
    }
    if(_currentTime - _lastCoconutSpawnIntervalDecrease >= 1 && _spawnIntervalRange[fruitType::coconut].first > 0.3)
    {
        _spawnIntervalRange[fruitType::coconut].first  -= 0.25;
        _spawnIntervalRange[fruitType::coconut].second -= 0.35;
        _lastCoconutSpawnIntervalDecrease = _currentTime;
    }
}

void Fruit::Delete()
{
    while(!fruitList.empty())
    {
        auto &[fruitType, trans] = fruitList.front();

        glm::vec3 movement = glm::vec3(trans[3]);
        if(movement.y < -2.5f)
            fruitList.pop_front();
        else
            break;
    }
}

