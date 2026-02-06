#include "fruit.h"

#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

std::deque<fruitAttributes> Fruit::fruitList;
std::map<FruitType, std::pair<double, double>> Fruit::_spawnIntervalRange;

Fruit::Fruit()
    : _currentTime(glfwGetTime()), _lastTimeMoved(glfwGetTime()), _lastCoconutSpawnIntervalDecrease(glfwGetTime())
{
    //V těchto promšnných se ukládají potřebná čísla pro určování rychlosti padajícího ovoce
    //a toho, jak často se ovoce vytváří
    _spawnIntervalRange[FruitType::apple] = {2.5, 4.5};
    _spawnIntervalRange[FruitType::coconut] = {5.0, 7.0};
    _spawnInterval[FruitType::apple] = random.GenerateDouble(_spawnIntervalRange[FruitType::apple].first, _spawnIntervalRange[FruitType::apple].second);
    _spawnInterval[FruitType::coconut] = random.GenerateDouble(_spawnIntervalRange[FruitType::coconut].first, _spawnIntervalRange[FruitType::coconut].second);
    _lastSpawnTime[FruitType::apple] = 0.0;
    _lastSpawnTime[FruitType::coconut] = 0.0;
    _speedIntervalRange[FruitType::apple] = {0.35, 0.65};
    _speedIntervalRange[FruitType::coconut] = {0.40, 0.7};
}

void Fruit::Move()
{
    _currentTime = glfwGetTime();
    for(auto &fruit : fruitList)
    {
        fruit.transform = glm::translate(fruit.transform, glm::vec3(0.0f, -fruit.speed * float(_currentTime - _lastTimeMoved), 0.0f));
    }
    _lastTimeMoved = _currentTime;
}

void Fruit::Spawn()
{
    //Tato funkce vytvoří ovoce vždy, když je rozdíl nynějšího času a času kdy se typ ovoce napsled
    //vytvořil větší než časový interval pro vytvoření daného typu ovoce
    _currentTime = glfwGetTime();
    for(FruitType type : {FruitType::apple, FruitType::coconut})
    {

        if(_currentTime - _lastSpawnTime[type] > _spawnInterval[type])
        {
            glm::mat4 trans = glm::mat4(1.0f);
            trans = glm::translate(trans, glm::vec3(random.GenerateFloat(0.0f, 2.0f - 64.0f/800.0f), 0.0f, 0.0f));
            float speed = random.GenerateDouble(_speedIntervalRange[type].first, _speedIntervalRange[type].second);
            fruitList.push_back({type, trans, speed});
        _lastSpawnTime[type] = _currentTime;
        _spawnInterval[type] = random.GenerateDouble(_spawnIntervalRange[type].first, _spawnIntervalRange[type].second);
        }
    }
    if(_currentTime - _lastCoconutSpawnIntervalDecrease >= 3 && _spawnIntervalRange[FruitType::coconut].first > 0.3)
    {
        _spawnIntervalRange[FruitType::coconut].first  -= 0.25;
        _spawnIntervalRange[FruitType::coconut].second -= 0.35;
        _lastCoconutSpawnIntervalDecrease = _currentTime;
    }
}

void Fruit::Delete()
{
    //Ovoce se smaže pokud spadne pod okraj herního pole
    while(!fruitList.empty())
    {
        auto &fruit = fruitList.front();

        glm::vec3 movement = glm::vec3(fruit.transform[3]);
        if(movement.y < -2.5f)
            fruitList.pop_front();
        else
            break;
    }
}

void Fruit::GameRestart()
{
    fruitList.clear();
    _spawnIntervalRange[FruitType::coconut] = {5.0, 7.0};
}
