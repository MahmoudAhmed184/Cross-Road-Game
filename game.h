#pragma once

#include <stdio.h>
#include "game_config.h"
#include "render.h"
#include "collision.h"

void renderScene();
void handleKeyboardInput(unsigned char key, int x, int y);
void initializeGame();
bool hasPlayerWon();
bool isCarOffScreen(Car *car);
void resetCarPosition(Car *car);
void moveCar(Car *car);
void updateGameState(int value);