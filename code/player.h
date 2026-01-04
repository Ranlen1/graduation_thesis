#pragma once

#include <glm/glm.hpp>

class Player
{
private:
    glm::mat4 _playerMovement;
    float _currentTime;
public:
    Player();
    void Move();
    glm::mat4 GetMovementMat();
};
