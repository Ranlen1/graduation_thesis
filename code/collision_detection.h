#pragma once

#include "fruit.h"
#include "text.h"
#include "player.h"

//Tato třída zodpovídá za kolizi mezi hráčem a ovocem
//a volá jiné funkce poté co kolize nastane

class CollisionDetection
{
private:
    Fruit _fruit;
    Text _text;
    Player _player;

    float _playerAY, _playerAX, _playerBY, _playerBX;
    float _fruitAY, _fruitAX, _fruitBY, _fruitBX;
    glm::mat4 _mat;
    bool _collisionX, _collisionY;
public:
    CollisionDetection();
//Tato funkce projde všechno ovoce a otestuje zda došlo ke kolizi
    void CheckCollision();
};

