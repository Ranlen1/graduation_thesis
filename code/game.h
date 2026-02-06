#pragma once

#include "game_menu.h"
#include "game_running.h"
#include "window.h"
#include "text.h"
#include "fruit.h"
#include "player.h"

//Tato třída uchovává možné stavy hry
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

    //Tyto funkce dělají následovné: přepínají stav hry, volají funkce na vykreslování a poslední
    //zjišťuje zda byla hra spuštěna
    void SetGameState(gameState state);
    void DrawGame();
    void Run();
private:
    void shouldWindowClose();
    bool leftButtonPressed();
};
