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

add_executable(main code/main.cpp)
add_executable(triangle code/triangle.cpp)
add_executable(rectangle code/rectangle.cpp)

target_link_libraries(main PRIVATE glad glfw OpenGL::GL)
target_link_libraries(triangle PRIVATE glad glfw OpenGL::GL)
target_link_libraries(rectangle PRIVATE glad glfw OpenGL::GL)



