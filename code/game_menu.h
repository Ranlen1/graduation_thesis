#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"

class GameMenu
{
public:
    GameMenu();
    ~GameMenu();

    void Draw();

private:
    unsigned int _VAO, _VBO;
    Shader _shader;

    std::string loadShaderSource(const char* filePath);
};



