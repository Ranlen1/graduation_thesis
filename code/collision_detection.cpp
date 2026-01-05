#include "collision_detection.h"

CollisionDetection::CollisionDetection()
    : _playerAY(-282.0f/300.0f), _playerBY(-320.0f/300.0f)
{}
void CollisionDetection::CheckCollision()
{
    _mat = _player.GetMovementMat();
    _playerAX = -392.0f/400.0f + _mat[3][0];
    _playerBX = -272.0f/400.0f + _mat[3][0];

    for(auto fruit = _fruit.fruitList.begin(); fruit != _fruit.fruitList.end(); )
    {
        _mat = fruit->transform;
        if(fruit->type == fruitType::apple)
        {
            _fruitAX = -389.0f/400.0f + _mat[3][0];
            _fruitBX = -347.0f/400.0f + _mat[3][0];
            _fruitAY = 284.0f/300.0f + _mat[3][1];
            _fruitBY = 246.0f/300.0f + _mat[3][1];

            _collisionX = (_playerBX >= _fruitAX) && (_playerAX <= _fruitBX);
            _collisionY = (_playerBY <= _fruitAY) && (_playerAY >= _fruitBY);

            if(_collisionX && _collisionY)
            {
                _text.AddPoint();
                fruit = _fruit.fruitList.erase(fruit);
            }
            else
                fruit ++;
        }
        else
        {
            _fruitAX = -388.0f/400.0f + _mat[3][0];
            _fruitBX = -348.0f/400.0f + _mat[3][0];
            _fruitAY = 290.0f/300.0f + _mat[3][1];
            _fruitBY = 246.0f/300.0f + _mat[3][1];

            _collisionX = (_playerBX >= _fruitAX) && (_playerAX <= _fruitBX);
            _collisionY = (_playerBY <= _fruitAY) && (_playerAY >= _fruitBY);

            if(_collisionX && _collisionY)
            {
                _text.RemoveHP();
                fruit = _fruit.fruitList.erase(fruit);
            }
            else
                fruit ++;
        }
    }
}
