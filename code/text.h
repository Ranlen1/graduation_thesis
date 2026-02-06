#pragma once

#include <glm/glm.hpp>

//Strukt ktery slouží k předáváni unfirom do shaderu
struct textureNumber
{
    glm::mat4 transform;
    float offset;
};
class Text
{
private:
    static int _score, _hp;
    static bool _gameEnded;
    std::vector<glm::mat4> _transfromVector;
    std::vector<float> _transfromValues;
public:
    Text();
    //Tyto funkce delaji nasledujici: resetuji hry, spravuji uniformy pro skore a zivoty, odebiraji
    //zivtoy, pridavaji body a ukoncuji hru
    void GameRestart();
    std::vector<textureNumber> GetLeftTextUniforms();
    std::vector<textureNumber> GetRightTextUniforms();
    void RemoveHP();
    void AddPoint();
    bool GameEnded();
};
