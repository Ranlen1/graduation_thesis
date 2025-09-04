#include "game_running.h"

#include "vertices.h"
#include "rendering_functions.h"
#include <GLFW/glfw3.h>

GameRunning::GameRunning()
{
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

    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(0.0f, -0.1f * float(glfwGetTime()), 0.0f));

    _fruitShader.Use();
    _fruitShader.SetMatrix4("transform", trans);
    _fruitShader.SetInteger("myTexture", 0);

    _appleTexture.Bind();
    glBindVertexArray(_fruitVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glBindVertexArray(0);
}
