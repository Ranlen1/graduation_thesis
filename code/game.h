#pragma once

#include "game_menu.h"
#include "game_running.h"
#include "window.h"
#include "text.h"
#include "fruit.h"
#include "player.h"

enum class gameState {
    Running = 0, Menu = 1
};
class Game
{
public:
private:
    gameState _gameState;
    GameMenu _gameMenu;
    GameRunning _gameRunning;
    Text _text;
    Fruit _fruit;
    Player _player;
public:
    Game();

    void SetGameState(gameState state);
    void DrawGameMenu();
    void Run();
private:
    void shouldWindowClose();
    bool leftButtonPressed();
};
