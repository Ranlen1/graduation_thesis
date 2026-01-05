#include "text.h"

#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

#include "string"

int Text::_score;
int Text::_hp;
bool Text::_gameEnded;

Text::Text()
{
    _transfromValues = {0.125f, 0.075f, 0.175f, 0.025f, 0.125f, 0.225f};
    for(float i : _transfromValues)
    {
        glm::mat4 mat = glm::mat4(1.0f);
        mat = glm::translate(mat, glm::vec3(i, 0.0f, 0.0f));
        _transfromVector.push_back(mat); 
    }

    _hp = 3;
    _score = 0;
    _gameEnded = false;
}

void Text::GameRestart()
{
    _score = 0;
    _hp = 3;
    _gameEnded = false;
}

std::vector<textureNumber> Text::GetLeftTextUniforms()
{
    std::vector<textureNumber> uniforms;
    int numberOfDigits, extraOne;
    std::string numberInString = std::to_string(_score);
    if(_score == 0)
        numberOfDigits = 1;
    else
        numberOfDigits = (int)std::log10(_score)+1;
    if(numberOfDigits == 3)
        extraOne = 1;
    else
        extraOne = 0;
    for(int i = 0; i < numberOfDigits; ++i)
        uniforms.push_back({_transfromVector[numberOfDigits+i-1+extraOne], (numberInString[i] - '0') /10.0f});
    return uniforms;
}

std::vector<textureNumber> Text::GetRightTextUniforms()
{
    std::vector<textureNumber> uniforms;
    int numberOfDigits, extraOne;
    std::string numberInString = std::to_string(_hp);
    if(_hp == 0)
        numberOfDigits = 1;
    else
        numberOfDigits = (int)std::log10(_hp)+1;
    if(numberOfDigits == 3)
        extraOne = 1;
    else
        extraOne = 0;
    for(int i = 0; i < numberOfDigits; ++i)
        uniforms.push_back({_transfromVector[numberOfDigits+i-1+extraOne], (numberInString[i] - '0') /10.0f});
    return uniforms;
}

void Text::RemoveHP()
{
    if(_hp > 1)
        _hp --;
    else
        _gameEnded = true;
}

void Text::AddPoint()
{
    _score ++;
}

bool Text::GameEnded()
{
    return _gameEnded;
}
