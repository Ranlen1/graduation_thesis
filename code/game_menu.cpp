#include "game_menu.h"

#include "vertices.h"

GameMenu::GameMenu()
    : _playButtonLeftBorder(350), _playButtonRightBorder(450), _playButtonTopBorder(250), _playButtonBotBorder(350)
{
    rectangleShaderBinding(_backgroundVAO, _backgroundVBO, backgroundVertices, backgroundVerticesSize);
    rectangleShaderBinding(_playButtonVAO, _playButtonVBO, playButtonVertices, playButtonVerticesSize);

    std::string vertexCode = loadShaderSource("../resources/shaders/rectangle.vs");
    std::string fragmentCode = loadShaderSource("../resources/shaders/rectangle.fs");
    
    _shader.Compile(vertexCode.c_str(), fragmentCode.c_str());

    loadTexture("../resources/textures/menu_background.png", _backgroundTexture);
    loadTexture("../resources/textures/menu_play_button.png", _playButtonTexture);
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

bool GameMenu::PlayButtonClicked(GLFWwindow *window)
{
    double cursorX, cursorY;
    glfwGetCursorPos(window, &cursorX, &cursorY);

    if((cursorX > _playButtonLeftBorder && cursorX < _playButtonRightBorder) && (cursorY > _playButtonTopBorder && cursorY < _playButtonBotBorder))
        return true;
    else
        return false;
}
