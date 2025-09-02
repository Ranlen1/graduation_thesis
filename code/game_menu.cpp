#include "game_menu.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "vertices.h"

GameMenu::GameMenu()
    : _playButtonLeftBorder(350), _playButtonRightBorder(450), _playButtonTopBorder(250), _playButtonBotBorder(350)
{
    shaderBinding(_backgroundVAO, _backgroundVBO, backgroundVertices, backgroundVerticesSize);
    shaderBinding(_playButtonVAO, _playButtonVBO, playButtonVertices, playButtonVerticesSize);

    std::string vertexCode = loadShaderSource("../resources/shaders/game_menu.vs");
    std::string fragmentCode = loadShaderSource("../resources/shaders/game_menu.fs");
    
    _shader.Compile(vertexCode.c_str(), fragmentCode.c_str());

    loadTexture("../resources/textures/menu_background.png", _backgroundTexture);
    loadTexture("../resources/textures/menu_play_button.png", _playButtonTexture);
}

GameMenu::~GameMenu()
{
    glDeleteVertexArrays(1, &_playButtonVAO);
    glDeleteBuffers(1, &_playButtonVBO);
    
    glDeleteVertexArrays(1, &_backgroundVAO);
    glDeleteBuffers(1, &_backgroundVBO);
}

void GameMenu::Draw()
{
    _shader.Use();
    _shader.SetInteger("myTexture", 0);
    glActiveTexture(GL_TEXTURE0);


    _backgroundTexture.Bind();
    glBindVertexArray(_backgroundVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    _playButtonTexture.Bind();
    glBindVertexArray(_playButtonVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glBindVertexArray(0);
}

bool GameMenu::PlayButtonClicked(GLFWwindow *window)
{
    double cursorX, cursorY;
    glfwGetCursorPos(window, &cursorX, &cursorY);

    if((cursorX > _playButtonLeftBorder && cursorX < _playButtonRightBorder) && (cursorY > _playButtonTopBorder && cursorY < _playButtonBotBorder))
        return true;
    else
        return false;
}

std::string GameMenu::loadShaderSource(const char* filePath)
{
    std::ifstream file(filePath);
    if(!file.is_open())
        std::cout << "shader file could not be opened " << filePath << std::endl;
    std::stringstream buffer;
    buffer << file.rdbuf();
    if(buffer.str().empty())
        std::cout << "shader file is empty " << filePath << std::endl;
    return buffer.str();
}

void GameMenu::shaderBinding(unsigned int &VAO, unsigned int &VBO, float *vertices, size_t size)
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void GameMenu::loadTexture(const char *filePath, Texture &texture)
{
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(filePath, &width, &height, &nrChannels, 4);
    if(data == nullptr)
        std::cout << "texture " << filePath << " did not load" << std::endl;
    texture.Generate(width, height, data);

    stbi_image_free(data);
}
