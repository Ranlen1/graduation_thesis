#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include <iostream>

#include "game.h"

void framebufferSizeCallback(GLFWwindow *window, int width, int height);
void shouldWindowClose(GLFWwindow *window);

int main()
{
    if(!glfwInit())
    {
        std::cout << "failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    const int screenWidth = 800, screenHeight = 600;

    GLFWwindow *window = glfwCreateWindow(screenWidth, screenHeight, "AppleCatch", NULL, NULL);
    if(window == NULL)
    {
        std::cout << "failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    
    Game game;
    GameMenu gameMenu;

    while(!glfwWindowShouldClose(window))
    {
        shouldWindowClose(window);

        game.DrawGameMenu(&gameMenu);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}

void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void shouldWindowClose(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
