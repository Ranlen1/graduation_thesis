#include "game.h"

#include <GLFW/glfw3.h>

Game::Game()
    : _gameState(gameStateMenu), _gameWindow(800, 600, "AppleCatch")
{}

void Game::SetGameState(gameState state)
{
    _gameState = state;
}

Game::gameState Game::GetGameState() const
{
    return _gameState;
}

void Game::DrawGameMenu()
{
    if(_gameState == gameStateMenu)
       _gameMenu.Draw();
}

void Game::Run()
{
    while(!glfwWindowShouldClose(_gameWindow.GetWindow()))
    {
        shouldWindowClose();
        glClear(GL_COLOR_BUFFER_BIT);

        if(_gameMenu.PlayButtonClicked(_gameWindow.GetWindow()) && leftButtonPressed())
            SetGameState(gameStateRunning);

        DrawGameMenu();

        glfwSwapBuffers(_gameWindow.GetWindow());
        glfwPollEvents();
    }
}

void Game::shouldWindowClose()
{
    if(glfwGetKey(_gameWindow.GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(_gameWindow.GetWindow(), true);
}

bool Game::leftButtonPressed()
{
    if(glfwGetMouseButton(_gameWindow.GetWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
        return true;
    else
        return false;
}

