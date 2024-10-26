#include "game.h"

void renderScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    for (GLint i = 0; i < NUM_ROADS; i++)
    {
        drawRoad(&roads[i]);
    }
    for (GLint i = 0; i < NUM_CARS; i++)
    {
        drawCar(&cars[i]);
    }
    drawFrog(&frog);
    handleCollisions();
    glutSwapBuffers();
}

void handleKeyboardInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        frog.start.x -= frog.speed;
        break;
    case 'd':
        frog.start.x += frog.speed;
        break;
    case 'w':
        frog.start.y += frog.speed;
        break;
    case 's':
        frog.start.y -= frog.speed;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void initializeGame()
{
    glClearColor(0.2, 0.5, 0.2, 1);
    glPointSize(5);
    glColor3i(1, 0, 0);
    glOrtho(-WINDOW_WIDTH / 2.0, WINDOW_WIDTH / 2, -WINDOW_HEIGHT / 2, WINDOW_HEIGHT / 2, -1, 1);
    glutKeyboardFunc(handleKeyboardInput);
    initializeGameState();
}

bool hasPlayerWon()
{
    return frog.start.y >= WINNING_POSITION;
}

bool isCarOffScreen(Car *car)
{
    return car->start.x >= 600;
}

void resetCarPosition(Car *car)
{
    car->start.x = -650;
}

void moveCar(Car *car)
{
    car->start.x += car->speed;
}

void updateGameState(int value)
{
    if (gameOver)
    {
        printf("Game over!");
        exit(0);
    }

    if (hasPlayerWon())
    {
        printf("You Win");
        exit(0);
    }

    for (int i = 0; i < NUM_CARS; i++)
    {
        moveCar(&cars[i]);
        if (isCarOffScreen(&cars[i]))
        {
            resetCarPosition(&cars[i]);
        }
    }
    glutPostRedisplay();
    glutTimerFunc(50, updateGameState, 0);
}
