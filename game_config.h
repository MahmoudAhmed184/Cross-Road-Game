#pragma once

#include "structures.h"
#include <stdbool.h>

#define NUM_CARS 5
#define NUM_ROADS 5
#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 800
#define WINNING_POSITION 335

Road roads[NUM_ROADS];
Car cars[NUM_CARS];
Frog frog;
bool gameOver;

void initializeRoads();
void initializeCars();
void initializeFrog();
void initializeGameState();
