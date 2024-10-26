#include "render.h"

void drawCarBody(const Car *car)
{
    GLfloat CAR_BODY_WIDTH = 110.0;
    glColor3f(car->color.red, car->color.green, car->color.blue);
    glBegin(GL_POLYGON);
    glVertex2d(car->start.x, car->start.y);
    glVertex2d(car->start.x, car->start.y + car->height);
    glVertex2d(car->start.x + CAR_BODY_WIDTH, car->start.y + car->height);
    glVertex2d(car->start.x + car->width, car->start.y + car->height - 10);
    glVertex2d(car->start.x + car->width, car->start.y + 10);
    glVertex2d(car->start.x + CAR_BODY_WIDTH, car->start.y);
    glEnd();
}

void drawCarWheels(const Car *car)
{
    GLfloat WHEEL_WIDTH = 20.0;
    GLfloat WHEEL_HEIGHT = 10.0;
    glColor3f(0.0f, 0.0f, 0.0f);

    // Front wheels (upper part)
    glRectd(car->start.x + 30.0, car->start.y + car->height,
            car->start.x + 30.0 + WHEEL_WIDTH, car->start.y + car->height + WHEEL_HEIGHT);
    glRectd(car->start.x + 80.0, car->start.y + car->height,
            car->start.x + 80.0 + WHEEL_WIDTH, car->start.y + car->height + WHEEL_HEIGHT);

    // Rear wheels (lower part)
    glRectd(car->start.x + 30.0, car->start.y,
            car->start.x + 30.0 + WHEEL_WIDTH, car->start.y - WHEEL_HEIGHT);
    glRectd(car->start.x + 80.0, car->start.y,
            car->start.x + 80.0 + WHEEL_WIDTH, car->start.y - WHEEL_HEIGHT);
}

void drawCarWindows(const Car *car)
{
    GLfloat CAR_WINDOW_WIDTH = 30.0;
    GLfloat CAR_WINDOW_HEIGHT = 60.0;
    glColor3f(0.0f, 0.0f, 1.0f);

    // Left window
    glRectd(car->start.x + 10.0, car->start.y + 10.0,
            car->start.x + 10.0 + CAR_WINDOW_WIDTH, car->start.y + CAR_WINDOW_HEIGHT);

    // Right window
    glRectd(car->start.x + 60.0, car->start.y + 10.0,
            car->start.x + 60.0 + CAR_WINDOW_WIDTH, car->start.y + CAR_WINDOW_HEIGHT);
}

void drawCarLights(const Car *car)
{
    GLfloat LIGHT_WIDTH = 10.0;
    GLfloat LIGHT_HEIGHT = 10.0;

    glColor3f(1.0f, 1.0f, 0.0f);

    // Front light
    glRectd(car->start.x + car->width - LIGHT_WIDTH - 10.0, car->start.y + car->height - 15,
            car->start.x + car->width - 10.0, car->start.y + car->height - 15 - LIGHT_HEIGHT);

    // Rear light
    glRectd(car->start.x + car->width - LIGHT_WIDTH - 10.0, car->start.y + 15,
            car->start.x + car->width - 10.0, car->start.y + 15 + LIGHT_HEIGHT);
}

void drawCar(const Car *car)
{
    drawCarBody(car);
    drawCarWheels(car);
    drawCarWindows(car);
    drawCarLights(car);
}

void drawRoad(const Road *road)
{
    glColor3f(0.8f, 0.8f, 0.8f);
    glRectd(road->start.x, road->start.y,
            road->start.x + road->width, road->start.y + road->height);
}

void drawFrog(const Frog *frog)
{
    glColor3f(0.5f, 0.3f, 0.8f);
    glBegin(GL_POLYGON);
    glVertex2d(frog->start.x, frog->start.y);
    glVertex2d(frog->start.x, frog->start.y + frog->height);
    glVertex2d(frog->start.x + frog->width, frog->start.y + frog->height);
    glVertex2d(frog->start.x + frog->width, frog->start.y);
    glEnd();
}