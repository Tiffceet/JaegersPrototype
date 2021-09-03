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
}

void kbKeyUp(unsigned char key, int x, int y)
{
}

void displayMe(void)
{
    // Register key listeners
    glutSpecialFunc(arrowKeyUp);
    glutKeyboardFunc(kbKeyUp);

    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    Prop3D props;
    props.rot = {frameNum, frameNum,frameNum};
    Vec3f size = {0.5, 0.5, 0.5};
    drawCube(props, size);

    glFlush();
}

void timer(int)
{
    glutTimerFunc(1000 / FRAME_RATE, timer, 0);
    frameNum++;
    glutPostRedisplay();
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
    glutMainLoop();
    return 0;
}
