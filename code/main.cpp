#include "game.h"

int main()
{
    //Zde se vytvoří okno a běží zde hlavní herní smyčka
    GLFWwindow* win = Window::GetWindow(800, 600, "FruitCatch");
    Game game;
    while(!glfwWindowShouldClose(Window::GetWindow()))
    {
        game.Run();
    }
    return 0;
}

