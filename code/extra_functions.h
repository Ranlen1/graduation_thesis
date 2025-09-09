#pragma once

#include <string>

#include "texture.h"

std::string loadShaderSource(const char *filePath);

void loadTexture(const char *filePath, Texture &texture);

void rectangleShaderBinding(unsigned int &VAO, unsigned int &VBO, float *vertices, size_t size);
