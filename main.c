#include "game.h"

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("Crossroad Game");
    glutDisplayFunc(renderScene);
    initializeGame();
    glutTimerFunc(50, updateGameState, 0);
    glutMainLoop();
    return 0;
}