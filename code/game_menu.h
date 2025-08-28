#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"
#include "texture.h"
#include "stb_image.h"

class GameMenu
{
public:
    GameMenu();
    ~GameMenu();

    void Draw();

private:
    unsigned int _VAO, _VBO;
    Shader _shader;
    Texture _texture;

    std::string loadShaderSource(const char* filePath);
};



