#include "game_running.h"

#include "shader.h"
#include "vertices.h"
#include "rendering_functions.h"

#include <GLFW/glfw3.h>

#include <iostream>

GameRunning::GameRunning()
{
    stbi_set_flip_vertically_on_load(true);
    rectangleShaderBinding(_backgroundVAO, _backgroundVBO, backgroundVertices, backgroundVerticesSize);
    rectangleShaderBinding(_fruitVAO, _fruitVBO, fruitVertices, fruitVerticesSize);
    rectangleShaderBinding(_counterBoxVAO, _counterBoxVBO, counterBoxVertices, backgroundVerticesSize);
    textShaderBinding(_textVAO, _textVBO, leftTextVertices, leftTextVerticesSize, rightTextVertices, rightTextVerticesSize);
    rectangleShaderBinding(_playerVAO, _playerVBO, playerVertices, playButtonVerticesSize);

    std::string vertexCode = loadShaderSource("../resources/shaders/rectangle.vs");
    std::string fragmentCode = loadShaderSource("../resources/shaders/rectangle.fs");
    _backgroundShader.Compile(vertexCode.c_str(), fragmentCode.c_str());
    
    vertexCode = loadShaderSource("../resources/shaders/fruit.vs");
    fragmentCode = loadShaderSource("../resources/shaders/fruit.fs");
    _fruitShader.Compile(vertexCode.c_str(), fragmentCode.c_str());
    
    vertexCode = loadShaderSource("../resources/shaders/text.vs");
    fragmentCode = loadShaderSource("../resources/shaders/text.fs");
    _textShader.Compile(vertexCode.c_str(), fragmentCode.c_str());
    
    loadTexture("../resources/textures/running_background.png", _backgroundTexture);
    loadTexture("../resources/textures/apple.png", _appleTexture);
    loadTexture("../resources/textures/coconut.png", _coconutTexture);
    loadTexture("../resources/textures/point_and_hp_counter_box.png", _counterBoxTexture);
    loadTexture("../resources/textures/text.png", _textTexture);
    loadTexture("../resources/textures/player.png", _playerTexture);
}

GameRunning::~GameRunning()
{
    glDeleteVertexArrays(1, &_backgroundVAO);
    glDeleteBuffers(1, &_backgroundVBO);

    glDeleteVertexArrays(1, &_fruitVAO);
    glDeleteBuffers(1, &_fruitVBO);

    glDeleteVertexArrays(1, &_textVAO);
    glDeleteBuffers(1, &_textVBO);
}

void GameRunning::Draw()
{
    _fruit.Move();
    _fruit.Spawn();
    _fruit.Delete();
    _player.Move();
    _collisionDetection.CheckCollision();

    _backgroundShader.Use();
    _backgroundShader.SetInteger("myTexture", 0);
    glActiveTexture(GL_TEXTURE0);

    _backgroundTexture.Bind();
    glBindVertexArray(_backgroundVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    _counterBoxTexture.Bind();
    glBindVertexArray(_counterBoxVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);

    _textShader.Use();
    _textShader.SetInteger("myTexture", 0);
    glActiveTexture(GL_TEXTURE0);

    _textTexture.Bind();
    glBindVertexArray(_textVAO);

    for(auto &unifrom : _text.GetLeftTextUniforms())
    {
        _textShader.SetMatrix4("transform", unifrom.transform); 
        _textShader.SetFloat("offset", unifrom.offset);
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }

    for(auto &unifrom : _text.GetRightTextUniforms())
    {
        _textShader.SetMatrix4("transform", unifrom.transform); 
        _textShader.SetFloat("offset", unifrom.offset);
        glDrawArrays(GL_TRIANGLES, 6, 6);
    }

    _fruitShader.Use();
    _fruitShader.SetInteger("myTexture", 0);
    glBindVertexArray(_fruitVAO);

    for(auto &fruit : _fruit.fruitList)
    {
        if(fruit.type == fruitType::apple)
            _appleTexture.Bind();
        else
            _coconutTexture.Bind();
        _fruitShader.SetMatrix4("transform", fruit.transform);
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }

    glBindVertexArray(_playerVAO);
    _playerTexture.Bind();
    _fruitShader.SetMatrix4("transform", _player.GetMovementMat());
    glDrawArrays(GL_TRIANGLES, 0, 6);

    glBindVertexArray(0);
}
