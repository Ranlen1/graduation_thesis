#pragma once

#include <string>

#include "texture.h"

//Tato funkce načíta shader
std::string loadShaderSource(const char *filePath);

//Tato funkce načítá obrázky
void loadTexture(const char *filePath, Texture &texture);

//Tato funkce vytváři VBO a VAO pro obdélníky
void rectangleShaderBinding(unsigned int &VAO, unsigned int &VBO, float *vertices, size_t size);

//Tato funkce vytváři VBO a VAO pro text
void textShaderBinding(unsigned int &VAO, unsigned int &VBO, float *leftVertices, size_t leftSize,
        float *rightVertices, size_t rightSize);
