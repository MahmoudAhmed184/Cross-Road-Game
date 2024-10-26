#include "collision.h"

bool isFrogOutOfWindowBounds()
{
    return frog.start.x < -WINDOW_WIDTH / 2 || frog.start.x + frog.width >= WINDOW_WIDTH / 2 ||
           frog.start.y < -WINDOW_HEIGHT / 2 || frog.start.y + frog.height >= WINDOW_HEIGHT / 2;
}

bool hasFrogCollidedWithCar(Car *car)
{
    GLdouble carRightX = car->start.x + car->width;
    GLdouble carTopY = car->start.y + car->height;

    if (frog.start.x + frog.width >= car->start.x && frog.start.x <= carRightX &&
        frog.start.y + frog.height >= car->start.y && frog.start.y <= carTopY)
    {
        return true;
    }
    return false;
}

void handleCollisions()
{
    if (isFrogOutOfWindowBounds())
    {
        gameOver = true;
        return;
    }

    for (GLint i = 0; i < NUM_CARS; i++)
    {
        if (hasFrogCollidedWithCar(&cars[i]))
        {
            gameOver = true;
            return;
        }
    }
}