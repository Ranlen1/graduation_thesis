#pragma once

#include "game_menu.h"
#include "game_running.h"
#include "window.h"

enum class gameState {
    Running = 0, Menu = 1
};
class Game
{
public:
    Window gameWindow;

private:
    gameState _gameState;
    GameMenu _gameMenu;
    GameRunning _gameRunning;
public:
    Game();

    void SetGameState(gameState state);

    void DrawGameMenu();

    void Run();
private:
    void shouldWindowClose();

    bool leftButtonPressed();
};
