#include <GL/freeglut.h>
#include <math.h>
#include "camera.h"
#include "lighting.h"
#include "primitives.h"
#include "texture.h"

int frameNum = 0;
const int FRAME_RATE = 60;

void arrowKeyUp(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        rotateCamera({2, 0, 0});
        break;
    case GLUT_KEY_DOWN:
        rotateCamera({-2, 0, 0});
        break;
    case GLUT_KEY_LEFT:
        rotateCamera({0, -2, 0});
        break;
    case GLUT_KEY_RIGHT:
        rotateCamera({0, 2, 0});
        break;
    }
}

void kbKeyUp(unsigned char key, int x, int y)
{
    float movement_spd = 0.05;
    switch (key)
    {
    case 'w':
        moveCamera({0, movement_spd, 0});
        break;
    case 'a':
        moveCamera({movement_spd, 0, 0});
        break;
    case 's':
        moveCamera({0, -movement_spd, 0});
        break;
    case 'd':
        moveCamera({-movement_spd, 0, 0});
        break;
    case 'q':
        moveCamera({0, 0, -movement_spd});
        break;
    case 'e':
        moveCamera({0, 0, movement_spd});
        break;
    case 'o':
        setViewMode('o');
        break;
    case 'p':
        setViewMode('p');
        break;
    case '=':
        changeZoom(-0.05);
        break;
    case '-':
        changeZoom(0.05);
        break;
    }
}

void displayMe(void)
{
    // Register key listeners
    glutSpecialFunc(arrowKeyUp);
    glutKeyboardFunc(kbKeyUp);

    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    initCamera(10, 100);

    Prop3D props;
    props.pos = {0, 0, 0};
    // props.rot = {frameNum, frameNum, frameNum};
    Vec3f size = {0.5, 0.5, 0.5};
    useTexture(0);
    // drawCube(props, size);
    // drawCylinder(props, 4, 4, 10, 30, 30);
    drawPyramid(props, 5, 5, 5);

    glFlush();
}

void timer(int)
{
    glutTimerFunc(1000 / FRAME_RATE, timer, 0);
    frameNum++;
    glutPostRedisplay();
}

void init()
{
    LoadAllTexture();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Title is here");
    glutDisplayFunc(displayMe);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
    return 0;
};