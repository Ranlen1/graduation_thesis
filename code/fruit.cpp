#include "fruit.h"

#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

Fruit::Fruit()
    : _currentTime(0.0), _lastTimeMoved(glfwGetTime()),_spawnTime(0.0), _seed(_rd()),
    _fruitXCoordinate(0.0f, 2.0f - 64.0f/800.0f), _appleSpawnGenerator(3.0, 5.0),
    _appleSpawnTime(_appleSpawnGenerator(_seed)), _timeFromLastApple(0.0)
{}

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
    if(_currentTime - _timeFromLastApple > _appleSpawnTime)
    {
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(_fruitXCoordinate(_seed), 0.0f, 0.0f));
        fruitList.push_back({1, trans});
        _timeFromLastApple = _currentTime;
        _appleSpawnTime = _appleSpawnGenerator(_seed);
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

