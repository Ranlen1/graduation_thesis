#pragma once

#include "shader.h"
#include "texture.h"
#include "fruit.h"
#include "stb_image.h"
#include "text.h"
#include "player.h"
#include "collision_detection.h"

class GameRunning
{
private:
    unsigned int _backgroundVAO, _backgroundVBO, _fruitVAO, _fruitVBO, _counterBoxVAO, _counterBoxVBO,_textVAO, _textVBO, _playerVAO, _playerVBO;
    Shader _backgroundShader, _fruitShader, _textShader;
    Texture _backgroundTexture, _appleTexture, _coconutTexture, _counterBoxTexture, _textTexture, _playerTexture;
    Fruit _fruit;
    Text _text;
    Player _player;
    CollisionDetection _collisionDetection;

    float _lastTime, _currentTime;
    
public:
    GameRunning();
    ~GameRunning();

    void Draw();
};
