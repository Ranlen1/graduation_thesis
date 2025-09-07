#include "game_running.h"

#include "vertices.h"
#include "rendering_functions.h"

#include <GLFW/glfw3.h>

GameRunning::GameRunning()
{
    stbi_set_flip_vertically_on_load(true);
    rectangleShaderBinding(_backgroundVAO, _backgroundVBO, backgroundVertices, backgroundVerticesSize);
    rectangleShaderBinding(_fruitVAO, _fruitVBO, fruitVertices, fruitVerticesSize);

    std::string vertexCode = loadShaderSource("../resources/shaders/rectangle.vs");
    std::string fragmentCode = loadShaderSource("../resources/shaders/rectangle.fs");
    _backgroundShader.Compile(vertexCode.c_str(), fragmentCode.c_str());
    
    vertexCode = loadShaderSource("../resources/shaders/fruit.vs");
    fragmentCode = loadShaderSource("../resources/shaders/fruit.fs");
    _fruitShader.Compile(vertexCode.c_str(), fragmentCode.c_str());
    
    loadTexture("../resources/textures/running_background.png", _backgroundTexture);
    loadTexture("../resources/textures/apple.png", _appleTexture);
}

GameRunning::~GameRunning()
{
    glDeleteVertexArrays(1, &_backgroundVAO);
    glDeleteBuffers(1, &_backgroundVBO);

    glDeleteVertexArrays(1, &_fruitVAO);
    glDeleteBuffers(1, &_fruitVBO);
}

void GameRunning::Draw()
{
    _backgroundShader.Use();
    _backgroundShader.SetInteger("myTexture", 0);
    glActiveTexture(GL_TEXTURE0);

    _backgroundTexture.Bind();
    glBindVertexArray(_backgroundVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    _fruit.Move();
    _fruit.Spawn();
    _fruit.Delete();

    _fruitShader.Use();
    _fruitShader.SetInteger("myTexture", 0);
    _appleTexture.Bind();
    glBindVertexArray(_fruitVAO);

    for(auto &[fruitType, trans] : _fruit.fruitList)
    {
        _fruitShader.SetMatrix4("transform", trans);
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }
    glBindVertexArray(0);
}
