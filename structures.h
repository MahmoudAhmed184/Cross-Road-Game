#pragma once

#include <GL/glut.h>

typedef struct
{
    GLfloat x;
    GLfloat y;
} Point;

typedef struct
{
    Point start;
    GLfloat width;
    GLfloat height;
} Road;

typedef struct
{
    GLfloat red;
    GLfloat green;
    GLfloat blue;
} Color;

typedef struct
{
    Point start;
    GLfloat width;
    GLfloat height;
    Color color;
    Road *road;
    GLint speed;
} Car;

typedef struct
{
    Point start;
    GLfloat width;
    GLfloat height;
    Color color;
    GLint speed;
} Frog;
