#pragma once
//Tato třída incializuje GLFW, GLAD a nastavuje parametry okna

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
private:
    GLFWwindow *_window; 
    static Window* instance;
    Window(int width, int height, const char* name);
public:
    ~Window();
    static GLFWwindow *GetWindow(int width = 800, int height = 600, const char *name = "FruitCatch");
private:
    static void framebufferSizeCallback(GLFWwindow *window, int width, int height);
};

    
