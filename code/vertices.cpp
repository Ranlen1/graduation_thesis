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
