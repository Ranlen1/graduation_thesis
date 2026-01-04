#pragma once

#include <glm/glm.hpp>

struct textureNumber
{
    glm::mat4 transform;
    float offset;
};
class Text
{
private:
    int _score, _hp, _highestScore;
    std::vector<glm::mat4> _transfromVector;
    std::vector<float> _transfromValues;

    double currentTime, lastTime;
public:
    Text();
    void GameRestart();
    void TextUpdate();
    std::vector<textureNumber> GetLeftTextUniforms();
    std::vector<textureNumber> GetRightTextUniforms();
};
