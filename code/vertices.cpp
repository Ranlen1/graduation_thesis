#include "vertices.h"

float backgroundVertices[] = {
        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
         1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
        -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,

         1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
        -1.0f,  1.0f, 0.0f, 0.0f, 1.0f,
         1.0f,  1.0f, 0.0f, 1.0f, 1.0f
};

size_t backgroundVerticesSize = sizeof(backgroundVertices);

float playButtonXCoordinate = 50.0f/400.0f, playButtonYCoordinate = 50.0f/300.0f;

float playButtonVertices[] = {
    -playButtonXCoordinate, -playButtonYCoordinate, 0.0f, 0.0f, 0.0f,
    playButtonXCoordinate, -playButtonYCoordinate, 0.0f, 1.0f, 0.0f,
    -playButtonXCoordinate, playButtonYCoordinate, 0.0f, 0.0f, 1.0f,
 
    playButtonXCoordinate, -playButtonYCoordinate, 0.0f, 1.0f, 0.0f,
    -playButtonXCoordinate, playButtonYCoordinate, 0.0f, 0.0f, 1.0f,
    playButtonXCoordinate, playButtonYCoordinate, 0.0f, 1.0f, 1.0f
};

size_t playButtonVerticesSize = sizeof(playButtonVertices);

float fruitXCoordinate = -1.0f + 64.0f/800.0f, fruitYCoordinate = 1.0f + 64.0f/600.0f;
float fruitVertices[] = {
    -1.0f, 1.0f, 0.0f, 0.0f, 0.0f,
    -1.0f, fruitYCoordinate, 0.0f, 0.0f, 1.0f,
    fruitXCoordinate, 1.0f, 0.0f, 1.0f, 0.0f,

    fruitXCoordinate, fruitYCoordinate, 0.0f, 1.0f, 1.0f,
    -1.0f, fruitYCoordinate, 0.0f, 0.0f, 1.0f,
    fruitXCoordinate, 1.0f, 0.0f, 1.0f, 0.0f
};
size_t fruitVerticesSize = sizeof(fruitVertices);

float counterBoxVertices[] = {
    -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
    1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
    -1.0f, -2.0f/3.0f, 0.0f, 0.0f, 1.0f,

    1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
    -1.0f, -2.0f/3.0f, 0.0f, 0.0f, 1.0f,
    1.0f, -2.0f/3.0f, 0.0f, 1.0f, 1.0f
};
size_t counterBoxVerticesSize = sizeof(counterBoxVertices);

float leftTextVertices[] = {
    -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
    -0.9f, -1.0f, 0.0f, 0.1f, 0.0f,
    -1.0f, -2.0f/3.0f, 0.0f, 0.0f, 1.0f,

    -0.9f, -1.0f, 0.0f, 0.1f, 0.0f,
    -1.0f, -2.0f/3.0f, 0.0f, 0.0f, 1.0f,
    -0.9f, -2.0f/3.0f, 0.0f, 0.1f, 1.0f
};
size_t leftTextVerticesSize = sizeof(leftTextVertices);

float rightTextVertices[] = {
    0.65f, -1.0f, 0.0f, 0.0f, 0.0f,
    0.75f, -1.0f, 0.0f, 0.1f, 0.0f,
    0.65f, -2.0f/3.0f, 0.0f, 0.0f, 1.0f,

    0.75f, -1.0f, 0.0f, 0.1f, 0.0f,
    0.65f, -2.0f/3.0f, 0.0f, 0.0f, 1.0f,
    0.75f, -2.0f/3.0f, 0.0f, 0.1f, 1.0f
};
size_t rightTextVerticesSize = sizeof(rightTextVertices);

float playerVertices[] = {
    -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
    -0.71f, -1.0f, 0.0f, 1.0f, 0.0f,
    -1.0f, -184.0f/300.0f, 0.0f, 0.0f, 1.0f,

    -0.71f, -1.0f, 0.0f, 1.0f, 0.0f,
    -1.0f, -184.0f/300.0f, 0.0f, 0.0f, 1.0f,
    -0.721f, -184.0f/300.0f, 0.0f, 1.0f, 1.0f
};
size_t playerVerticesSize = sizeof(playerVertices);
