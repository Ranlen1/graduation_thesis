#pragma once

#include "shader.h"
#include "rendering_functions.h"

#include <GLFW/glfw3.h>

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

    //Tyto funkce vykreslují herní menu a zjišťují, zda bylo zmáčknuto tlačítka na spuštění hry
    void Draw();
    bool PlayButtonClicked(GLFWwindow *window);
};



