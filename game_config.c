#include "game_config.h"

void initializeRoads()
{
    const GLfloat spaceBetweenRoads = 20.0;
    GLfloat yStart = -300.0;
    GLfloat roadHeight = 100.0;
    for (int i = 0; i < NUM_ROADS; i++)
    {
        roads[i].start.x = -500.0;
        roads[i].start.y = yStart + (roadHeight + spaceBetweenRoads) * i;
        roads[i].width = 1000.0;
        roads[i].height = roadHeight;
    }
}

void initializeCars()
{
    Color carColors[NUM_CARS] = {
        {1.0f, 0.0f, 0.0f},
        {0.0f, 0.7f, 0.0f},
        {1.0f, 0.0f, 1.0f},
        {0.5f, 0.1f, 0.7f},
        {0.0f, 0.0f, 0.0f}};

    GLint carSpeeds[NUM_CARS] = {7, 5, 8, 6, 8};

    GLint SPACE_FOR_WHEEL = 15;
    for (int i = 0; i < NUM_CARS; i++)
    {
        cars[i].start.x = -650;
        cars[i].start.y = roads[i].start.y + SPACE_FOR_WHEEL;
        cars[i].width = 150.0;
        cars[i].height = 70.0;
        cars[i].color = carColors[i];
        cars[i].road = &roads[i];
        cars[i].speed = carSpeeds[i];
    }
}

void initializeFrog()
{
    frog.start.x = -100;
    frog.start.y = -380;
    frog.width = 100.0;
    frog.height = 50.0;
    frog.color = (Color){0.5f, 0.3f, 0.8f};
    frog.speed = 25;
}

void initializeGameState()
{
    initializeRoads();
    initializeCars();
    initializeFrog();
    gameOver = false;
}
