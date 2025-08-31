#include "game_menu.h"

#include <iostream>
#include <fstream>
#include <sstream>

GameMenu::GameMenu()
{
    float backgroundVertices[] = {
        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
        -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
         1.0f, -1.0f, 0.0f, 1.0f, 0.0f,

        -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
         1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
         1.0f,  1.0f, 0.0f, 1.0f, 1.0f
    };

    float playButtonXCoordinate = 50.0f/400.0f, playButtonYCoordinate = 50.0f/300.0f;

    float playButtonVertices[] = {
        -playButtonXCoordinate, -playButtonYCoordinate, 0.0f, 0.0f, 0.0f,
        playButtonXCoordinate, -playButtonYCoordinate, 0.0f, 1.0f, 0.0f,
        -playButtonXCoordinate, playButtonYCoordinate, 0.0f, 0.0f, 1.0f,
 
        playButtonXCoordinate, -playButtonYCoordinate, 0.0f, 1.0f, 0.0f,
        -playButtonXCoordinate, playButtonYCoordinate, 0.0f, 0.0f, 1.0f,
        playButtonXCoordinate, playButtonYCoordinate, 0.0f, 1.0f, 1.0f
    };
    
    shaderBinding(_backgroundVAO, _backgroundVBO, backgroundVertices, sizeof(backgroundVertices));
    shaderBinding(_playButtonVAO, _playButtonVBO, playButtonVertices, sizeof(playButtonVertices));

    std::string vertexCode = loadShaderSource("../shaders/game_menu.vs");
    std::string fragmentCode = loadShaderSource("../shaders/game_menu.fs");
    
    _shader.Compile(vertexCode.c_str(), fragmentCode.c_str());

    loadTexture("../textures/menu_background.png", _backgroundTexture);
    loadTexture("../textures/menu_play_button.png", _playButtonTexture);
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
    unsigned char *data = stbi_load(filePath, &width, &height, &nrChannels, 4);
    if(data == nullptr)
        std::cout << "texture " << filePath << " did not load" << std::endl;
    texture.Generate(width, height, data);

    stbi_image_free(data);
}
