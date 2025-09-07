#pragma once

#include "shader.h"
#include "texture.h"
#include "fruit.h"
#include "stb_image.h"

class GameRunning
{
private:
    unsigned int _backgroundVAO, _backgroundVBO, _fruitVAO, _fruitVBO;
    Shader _backgroundShader, _fruitShader;
    Texture _backgroundTexture, _appleTexture;
    Fruit _fruit;

    float _lastTime, _currentTime;
    
public:
    GameRunning();
    ~GameRunning();

    void Draw();
};
