#include "window.h"

#include <iostream>

Window::Window(int width, int height, const char* name)
{
    if(!glfwInit())
        std::cout << "failed to initialize GLFW" << std::endl;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _window = glfwCreateWindow(width, height, name, NULL, NULL);

    if(_window == NULL)
        std::cout << "failed to create GLFW window" << std::endl;

    glfwMakeContextCurrent(_window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        std::cout << "failed to initialize GLAD" << std::endl;

    glfwSetFramebufferSizeCallback(_window, framebufferSizeCallback);
}

Window::~Window()
{
    glfwDestroyWindow(_window);
    glfwTerminate();
}

GLFWwindow *Window::GetWindow()
{
    return _window;
}

void Window::framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}


    
