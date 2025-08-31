#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
private:
    GLFWwindow *_window; 
public:
    Window(int width, int height, const char* name);
    ~Window();
    
    GLFWwindow *GetWindow();
private:
    static void framebufferSizeCallback(GLFWwindow *window, int width, int height);
};

    
