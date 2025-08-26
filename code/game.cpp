#include "game.h"

Game::Game()
    : _gameState(gameStateMenu)
{}

void Game::SetGameState(gameState state)
{
    this->_gameState = state;
}

Game::gameState Game::GetGameState() const
{
    return _gameState;
}
