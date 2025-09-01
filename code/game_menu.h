#pragma once
#include "shader.h"

#include <GLFW/glfw3.h>

#include "texture.h"
#include "stb_image.h"

class GameMenu
{
private:
    const int _playButtonLeftBorder, _playButtonRightBorder, _playButtonTopBorder, _playButtonBotBorder;
    unsigned int _backgroundVAO, _backgroundVBO, _playButtonVAO, _playButtonVBO;
    Shader _shader;
    Texture _backgroundTexture, _playButtonTexture;

public:
    GameMenu();
    ~GameMenu();

    void Draw();

    bool PlayButtonClicked(GLFWwindow *window);

private:
    std::string loadShaderSource(const char* filePath);

    void shaderBinding(unsigned int &VAO, unsigned int &VBO, float *vertices, size_t size);

    void loadTexture(const char *filePath, Texture &texture);
};



