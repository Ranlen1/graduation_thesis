#include "extra_functions.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "stb_image.h"

std::string loadShaderSource(const char *filePath)
{
    std::ifstream file(filePath);
    if(!file.is_open())
        std::cout << "shader file cout not be opened " << filePath << std::endl;
    std::stringstream buffer;
    buffer << file.rdbuf();
    if(buffer.str().empty())
        std::cout << "shader file is empty " << filePath << std::endl;
    return buffer.str();
}

void loadTexture(const char *filePath, Texture &texture)
{
    int width, height, nrChannels;
    unsigned char *data = stbi_load(filePath, &width, &height, &nrChannels, 4);
    if(data == nullptr)
        std::cout << "texture " << filePath << " did not load" << std::endl;
    texture.Generate(width, height, data);
}

void rectangleShaderBinding(unsigned int &VAO, unsigned int &VBO, float *vertices, size_t size)
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
    
