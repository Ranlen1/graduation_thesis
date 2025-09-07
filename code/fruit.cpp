#include "fruit.h"

#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

Fruit::Fruit()
    : _currentTime(0.0), _lastTime(glfwGetTime()),_spawnTime(0.0), _spawn(true), gen(rd()), dis(0.0f, 2.0f - 64.0f/800.0f)
{}

void Fruit::Move()
{
    _currentTime = glfwGetTime();
    for(auto &[fruitType, trans] : fruitList)
    {
        trans = glm::translate(trans, glm::vec3(0.0f, -0.5f * float(_currentTime - _lastTime), 0.0f));
    }
    _lastTime = _currentTime;
}

void Fruit::Spawn()
{
    _spawnTime = glfwGetTime();
    double mod = fmod(_spawnTime, 4);
    if(mod > 3 && _spawn)
    {
        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(dis(gen), 0.0f, 0.0f));
        fruitList.push_back({1, trans});
        _spawn = false;
    }
    else if(mod < 3 && !_spawn)
        _spawn = true;
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

