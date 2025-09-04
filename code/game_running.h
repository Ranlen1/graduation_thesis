#pragma once

#include "shader.h"
#include "texture.h"

class GameRunning
{
private:
    unsigned int _backgroundVAO, _backgroundVBO, _fruitVAO, _fruitVBO;
    Shader _backgroundShader, _fruitShader;
    Texture _backgroundTexture, _appleTexture;
public:
    GameRunning();
    ~GameRunning();

    void Draw();
};
