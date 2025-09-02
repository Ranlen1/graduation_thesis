#include <iostream>
#include "game.h"

int main()
{
    Game game;
    while(!glfwWindowShouldClose(game.gameWindow.GetWindow()))
    {
        game.Run();
    }
    return 0;
}

