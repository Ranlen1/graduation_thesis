cmake_minimum_required(VERSION 3.10)
project(graduation_thesis VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE glfw OpenGL::GL)
