#include "render.h"

#define BASE_CAR_WIDTH 150.0
#define BASE_CAR_HEIGHT 70.0
#define CAR_BODY_WIDTH_RATIO 110.0f / BASE_CAR_WIDTH
#define CAR_WHEEL_WIDTH_RATIO 20.0f / BASE_CAR_WIDTH
#define CAR_WHEEL_HEIGHT_RATIO 10.0f / BASE_CAR_HEIGHT
#define CAR_WINDOW_WIDTH_RATIO 30.0f / BASE_CAR_WIDTH
#define CAR_WINDOW_HEIGHT_RATIO 60.0f / BASE_CAR_HEIGHT
#define CAR_LIGHT_WIDTH_RATIO 10.0f / BASE_CAR_WIDTH
#define CAR_LIGHT_HEIGHT_RATIO 10.0f / BASE_CAR_HEIGHT

void drawCarBody(const Car *car)
{
        GLfloat bodyWidth = car->width * CAR_BODY_WIDTH_RATIO;
        GLfloat vertOffset = (car->height * 0.15f);

        glColor3f(car->color.red, car->color.green, car->color.blue);

        glBegin(GL_POLYGON);
        glVertex2d(car->start.x, car->start.y);
        glVertex2d(car->start.x, car->start.y + car->height);
        glVertex2d(car->start.x + bodyWidth, car->start.y + car->height);
        glVertex2d(car->start.x + car->width, car->start.y + car->height - vertOffset);
        glVertex2d(car->start.x + car->width, car->start.y + vertOffset);
        glVertex2d(car->start.x + bodyWidth, car->start.y);
        glEnd();
}

void drawCarWheels(const Car *car)
{
        GLfloat wheelWidth = car->width * CAR_WHEEL_WIDTH_RATIO;
        GLfloat wheelHeight = car->height * CAR_WHEEL_HEIGHT_RATIO;
        GLfloat leftSideOffset = car->width * (30.0f / BASE_CAR_WIDTH);
        GLfloat rightSideOffset = car->width * (80.0f / BASE_CAR_WIDTH);

        glColor3f(0.0f, 0.0f, 0.0f);

        // Front wheels (upper part)
        glRectd(car->start.x + leftSideOffset,
                car->start.y + car->height,
                car->start.x + leftSideOffset + wheelWidth,
                car->start.y + car->height + wheelHeight);
        glRectd(car->start.x + rightSideOffset,
                car->start.y + car->height,
                car->start.x + rightSideOffset + wheelWidth,
                car->start.y + car->height + wheelHeight);

        // Rear wheels (lower part)
        glRectd(car->start.x + leftSideOffset,
                car->start.y,
                car->start.x + leftSideOffset + wheelWidth,
                car->start.y - wheelHeight);
        glRectd(car->start.x + rightSideOffset,
                car->start.y,
                car->start.x + rightSideOffset + wheelWidth,
                car->start.y - wheelHeight);
}

void drawCarWindows(const Car *car)
{
        GLfloat windowWidth = car->width * CAR_WINDOW_WIDTH_RATIO;
        GLfloat windowHeight = car->height * CAR_WINDOW_HEIGHT_RATIO;
        GLfloat leftSideOffset = car->width * (10.0f / 150.0f);
        GLfloat rightSideOffset = car->width * (60.0f / 150.0f);
        GLfloat vertOffset = (car->height * 0.15f);

        glColor3f(0.0f, 0.0f, 1.0f);

        // Left window
        glRectd(car->start.x + leftSideOffset,
                car->start.y + vertOffset,
                car->start.x + leftSideOffset + windowWidth,
                car->start.y + windowHeight);

        // Right window
        glRectd(car->start.x + rightSideOffset,
                car->start.y + vertOffset,
                car->start.x + rightSideOffset + windowWidth,
                car->start.y + windowHeight);
}

void drawCarLights(const Car *car)
{
        GLfloat lightWidth = car->width * CAR_LIGHT_WIDTH_RATIO;
        GLfloat lightHeight = car->height * CAR_LIGHT_HEIGHT_RATIO;
        GLfloat sideOffset = 10.0f * (car->width / BASE_CAR_WIDTH);
        GLfloat vertOffset = 15.0f * (car->height / BASE_CAR_HEIGHT);

        glColor3f(1.0f, 1.0f, 0.0f);

        // Front light
        glRectd(car->start.x + car->width - lightWidth - sideOffset,
                car->start.y + car->height - vertOffset,
                car->start.x + car->width - sideOffset,
                car->start.y + car->height - vertOffset - lightHeight);

        // Rear light
        glRectd(car->start.x + car->width - lightWidth - sideOffset,
                car->start.y + vertOffset,
                car->start.x + car->width - sideOffset,
                car->start.y + vertOffset + lightHeight);
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
