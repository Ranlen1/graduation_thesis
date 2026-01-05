#include "player.h"
#include "window.h"
#include <GLFW/glfw3.h>

glm::mat4 Player::_playerMovement;

Player::Player()
{
    _playerMovement = glm::mat4(1.0f);
    _playerMovement[3][0] = 0.855f;
}

void Player::Move()
{
    float speed = 0.5f;
    float timeDiff = glfwGetTime() - _currentTime;
    _currentTime = glfwGetTime();
    if(glfwGetKey(Window::GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
        _playerMovement[3][0] = std::max(0.0f, _playerMovement[3][0] - timeDiff * speed);

    if(glfwGetKey(Window::GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
        _playerMovement[3][0] = std::min(1.72f, _playerMovement[3][0] + timeDiff * speed);
}

glm::mat4 Player::GetMovementMat()
{
    return _playerMovement;
}

void Player::GameRestart()
{
    _playerMovement[3][0] = 0.855f;
}
