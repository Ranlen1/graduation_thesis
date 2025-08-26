#pragma once

class Game
{
public:
    enum gameState
    {
        gameStateRunning = 0, gameStatePaused = 1, gameStateMenu = 2
    };

private:
    gameState _gameState;

public:
    Game();

    void SetGameState(gameState state);

    gameState GetGameState() const;
};



