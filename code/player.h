#pragma once

#include <glm/glm.hpp>

class Player
{
private:
    static glm::mat4 _playerMovement;
    float _currentTime;
public:
    Player();
    //Tato funkce spravuje pohyb hráče
    void Move();
    glm::mat4 GetMovementMat();

    //Tato funkce resetuje hru
    void GameRestart();
};
