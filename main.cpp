#include <GL/freeglut.h>
#include <math.h>
#include "camera.h"
#include "lighting.h"
#include "primitives.h"
#include "texture.h"
#include "material.h"
#include "body.h"
#include "_hand.h"
#include "_leg.h"
#define WIN_WIDTH 800
#define WIN_HEIGHT 800

int frameNum = 0;
const int FRAME_RATE = 60;

void arrowKeyUp(int key, int x, int y)
{
    // switch (key)
    // {
    // case GLUT_KEY_UP:
    //     rotateCamera({2.0f, 0.0f, 0.0f});
    //     break;
    // case GLUT_KEY_DOWN:
    //     rotateCamera({-2.0f, 0.0f, 0.0f});
    //     break;
    // case GLUT_KEY_LEFT:
    //     rotateCamera({0.0f, -2.0f, 0.0f});
    //     break;
    // case GLUT_KEY_RIGHT:
    //     rotateCamera({0.0f, 2.0f, 0.0f});
    //     break;
    // }
}

void kbKeyUp(unsigned char key, int x, int y)
{
    float movement_spd = 0.1;
    switch (key)
    {
    case 'w':
        moveCamera({0, movement_spd, 0});
        break;
    case 'a':
        moveCamera({-movement_spd, 0, 0});
        break;
    case 's':
        moveCamera({0, -movement_spd, 0});
        break;
    case 'd':
        moveCamera({movement_spd, 0, 0});
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
    case 'i':
        moveLightPosition({0, movement_spd, 0});
        break;
    case 'j':
        moveLightPosition({-movement_spd, 0, 0});
        break;
    case 'k':
        moveLightPosition({0, -movement_spd, 0});
        break;
    case 'l':
        moveLightPosition({movement_spd, 0, 0});
        break;
    case ';':
        moveLightPosition({0, 0, movement_spd});
        break;
    case '\'':
        moveLightPosition({0, 0, -movement_spd});
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

    useTexture("sky");
    Prop3D background;
    background.pos = {0, 0, -200};
    drawCube(background, {200, 200, 200});

    initCamera(10, 100);
    // ApplyLight();

    Prop3D props;
    // props.pos = {0, 0, 0};
    useDefaultTexture();
    drawRobotLeg(props);
    // drawRobotHand(props);
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
    SetDistantLighting(
        {1.0, 0.0, 0.0, -2},  // Pos
        {0.1, 0.1, 0.1, 1.0}, // Amb
        {1.0, 1.0, 1.0, 1.0}, // Diff
        {1.0, 1.0, 1.0, 1.0}  // Spec
    );
    // toggleLight();
}

bool isDragging = false;
Vec2d dragStart = {0, 0};

void mouse(int button, int state, int x, int y)
{
    // std::cout << "x: " << x << "; y: " << y << std::endl;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        // std::cout << "LEFT DOWN" << std::endl;
        isDragging = true;
        dragStart = {x, y};
        return;
    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    {
        // std::cout << "LEFT UP" << std::endl;
        isDragging = false;
        return;
    }

    // Wheel reports as button 3(scroll up) and button 4(scroll down)
    if (button == 3)
    {
        changeZoom(-0.05);
        return;
    }
    if (button == 4)
    {
        changeZoom(0.05);
        return;
    }
}

void drag(int x, int y)
{
    // std::cout << "Drag Start X: " << dragStart.x - x << std::endl;
    // std::cout << "Rot X: " << (float)(dragStart.x - x) / WIN_WIDTH * 360 << std::endl;
    // std::cout << "Rot Y: " << (float)(dragStart.y - y) / WIN_HEIGHT * 360 << std::endl;
    if (isDragging)
    {
        rotateCamera(
            {(float)(-dragStart.y + y) / WIN_HEIGHT * 180.0f,
             (float)(-dragStart.x + x) / WIN_WIDTH * 180.0f,
             0});
        dragStart = {x, y};
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Title is here");
    glutDisplayFunc(displayMe);
    glutTimerFunc(0, timer, 0);

    glutMouseFunc(mouse);
    glutMotionFunc(drag);
    init();
    glutMainLoop();
    return 0;
};