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

    //Tyto funkce delaji nasledujici: nahrávají data do GPU a bindují texturu pro použití v shaderu
    void Generate(int textureWidth, int textureHeight, unsigned char *data);
    void Bind() const;
};
