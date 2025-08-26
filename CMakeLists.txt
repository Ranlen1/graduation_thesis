cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0072 NEW)
project(graduation_thesis VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(glad plugins/glad/src/glad.c)
target_include_directories(glad PUBLIC plugins/glad/include)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm REQUIRED)

include_directories(plugins/stb)

add_executable(main
    code/main.cpp
    code/stb_image.cpp
    code/game.cpp
    code/game_menu.cpp
    code/shader.cpp
)

target_link_libraries(main PRIVATE glad glfw glm OpenGL::GL)



