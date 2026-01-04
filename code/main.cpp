#include "game.h"

int main()
{
    GLFWwindow* win = Window::GetWindow(800, 600, "FruitCatch");
    Game game;
    while(!glfwWindowShouldClose(Window::GetWindow()))
    {
        game.Run();
    }
    return 0;
}

