#include "game_menu.h"

#include <iostream>
#include <fstream>
#include <sstream>

GameMenu::GameMenu()
{
    float vertices[] = {
        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
        -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
         1.0f, -1.0f, 0.0f, 1.0f, 0.0f,

        -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
         1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
         1.0f,  1.0f, 0.0f, 1.0f, 1.0f
    };

    glGenVertexArrays(1, &_VAO);
    glGenBuffers(1, &_VBO);

    glBindVertexArray(_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    std::string vertexCode = loadShaderSource("../shaders/game_menu.vs");
    std::string fragmentCode = loadShaderSource("../shaders/game_menu.fs");
    
    _shader.Compile(vertexCode.c_str(), fragmentCode.c_str());

    int width, height, nrChannels;
    unsigned char *data = stbi_load("../textures/menu_background.png",
            &width, &height, &nrChannels, 4);
    if(data == nullptr)
        std::cout << "texture menu_background.png did not load" << std::endl;
    _texture.Generate(width, height, data);

    stbi_image_free(data);
}

GameMenu::~GameMenu()
{
    glDeleteVertexArrays(1, &_VAO);
    glDeleteBuffers(1, &_VBO);
}

void GameMenu::Draw()
{
    _shader.Use();
    _shader.SetInteger("myTexture", 0);
    glActiveTexture(GL_TEXTURE0);
    _texture.Bind();
    glBindVertexArray(_VAO);
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
