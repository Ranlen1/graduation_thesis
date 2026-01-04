#include "game.h"

#include <GLFW/glfw3.h>
#include "stb_image.h"

Game::Game()
    : _gameState(gameState::Menu)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    stbi_set_flip_vertically_on_load(true);
}

void Game::SetGameState(gameState state)
{
    _gameState = state;
}

void Game::DrawGameMenu()
{
    if(_gameState == gameState::Menu)
       _gameMenu.Draw();
    else if(_gameState == gameState::Running)
      _gameRunning.Draw();  
}

void Game::Run()
{
    shouldWindowClose();
    glClear(GL_COLOR_BUFFER_BIT);

    if(_gameMenu.PlayButtonClicked(Window::GetWindow()) && leftButtonPressed())
        SetGameState(gameState::Running);

    DrawGameMenu();

    glfwSwapBuffers(Window::GetWindow());
    glfwPollEvents();
}

void Game::shouldWindowClose()
{
    if(glfwGetKey(Window::GetWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(Window::GetWindow(), true);
}

bool Game::leftButtonPressed()
{
    return glfwGetMouseButton(Window::GetWindow(), GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
}

