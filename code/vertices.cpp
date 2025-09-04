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
