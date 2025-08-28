#pragma once

#include <glad/glad.h>

class Texture
{
public:
    unsigned int ID;

    unsigned int width, height;

    unsigned int internalFormat, imageFormat;

    unsigned int wrapS, wrapT;
    unsigned int filterMin, filterMax;

    Texture();
    ~Texture();

    void Generate(int textureWidth, int textureHeight, unsigned char *data);

    void Bind() const;
};
