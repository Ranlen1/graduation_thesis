#pragma once

#include "game_menu.h"
#include "window.h"

class Game
{
public:
    enum gameState
    {
        gameStateRunning = 0, gameStatePaused = 1, gameStateMenu = 2
    };

private:
    gameState _gameState;
    Window _gameWindow;
    GameMenu _gameMenu;
public:
    Game();

    void SetGameState(gameState state);

    gameState GetGameState() const;

    void DrawGameMenu();

    void Run();
private:
    void shouldWindowClose();

    bool leftButtonPressed();
};



