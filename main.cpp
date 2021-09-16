#include <GL/freeglut.h>
#include <math.h>
#include "animation.h"
#include "camera.h"
#include "lighting.h"
#include "primitives.h"
#include "texture.h"
#include "material.h"
#include "body.h"
#include "head.h"
#include "_hand.h"
#include "_leg.h"
#include "spawnable_object.h"
#define WIN_WIDTH 800
#define WIN_HEIGHT 800

int frameNum = 0, animation_fly_angle = 0, animation_fly_confirmation = 0, animation_head_angle = 0, animation_head_confirmation = 0, animation_wing_confirmation = 0;
const int FRAME_RATE = 60;

void arrowKeyUp(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        rleg_upper_foot.rot.z -= 2;
        rleg_lower_leg.rot.z += 1;
        lleg_upper_foot.rot.z -= 2;
        lleg_lower_leg.rot.z += 1;
        break;
    case GLUT_KEY_DOWN:
        rleg_upper_foot.rot.z += 2;
        rleg_lower_leg.rot.z -= 1;
        lleg_upper_foot.rot.z += 2;
        lleg_lower_leg.rot.z -= 1;
        break;
    case GLUT_KEY_LEFT:
        lhand_arm.rot.x += 3;
        lhand_upper_arm.rot.x += 2;
        lhand_lower_arm.rot.x += 1;
        rhand_arm.rot.x += 3;
        rhand_upper_arm.rot.x += 2;
        rhand_lower_arm.rot.x += 1;
        break;
    case GLUT_KEY_RIGHT:
        lhand_arm.rot.x -= 3;
        lhand_upper_arm.rot.x -= 2;
        lhand_lower_arm.rot.x -= 1;
        rhand_arm.rot.x -= 3;
        rhand_upper_arm.rot.x -= 2;
        rhand_lower_arm.rot.x -= 1;
        break;
    }
}

void kbKeyUp(unsigned char key, int x, int y)
{
    float movement_spd = 1;
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
    case 'r':
        PlaySequence("LeftArmGrab_1");
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
    case 'f':
        if (animation_wing_confirmation != 1) break;
        if (animation_fly_confirmation == 0)
        {
            animation_fly_confirmation = 1;
        }
        else
        {
            animation_fly_confirmation = 0;
        }
        break;
    case 'h':
        if (animation_head_confirmation != 1)
        {
            animation_head_confirmation = 1;
        }
        else
        {
            animation_head_confirmation = 0;
        }
        break;
    case 'g':
        if (animation_head_confirmation != 2)
        {
            animation_head_confirmation = 2;
        }
        else
        {
            animation_head_confirmation = 0;
        }
        break;
    case 'y':
        if (animation_fly_angle != 0) break;
        if (animation_wing_confirmation != 1)
        {
            animation_wing_confirmation = 1;
        }
        else
        {
            animation_wing_confirmation = 0;
        }
        break;
    case ' ':
        PlaySequence("RobotWalk_1");
        break;
    case 'v':
        PlaySequence("RobotTurn90_1");
        break;
    case '/':
        toggleLight();
        break;
    case 'u':
        PlaySequence("ShootLazer_1");
        break;
    }
}

void drawMainRobot(Prop3D props)
{
    glPushMatrix();
    applyProps(props);
    DrawSpawnables();

    glPushMatrix();

    Prop3D propsA;
    propsA.pos.y = 9 * 0.5;
    propsA.pos.z = -2.5 * 0.5;
    applyProps(propsA);

    glPushMatrix();

    Prop3D props_head_rotated;
    if (animation_head_confirmation == 1)
    {
        if (animation_head_angle < 45)
        {
            props_head_rotated.rot.y = animation_head_angle++;
            applyProps(props_head_rotated);
            drawRobotHead(0.5, props);
        }
        else
        {
            props_head_rotated.rot.y = 45;
            applyProps(props_head_rotated);
            drawRobotHead(0.5, props);
        }
    }
    else if (animation_head_confirmation == 2)
    {
        if (animation_head_angle > -45)
        {
            props_head_rotated.rot.y = animation_head_angle--;
            applyProps(props_head_rotated);
            drawRobotHead(0.5, props);
        }
        else
        {
            props_head_rotated.rot.y = -45;
            applyProps(props_head_rotated);
            drawRobotHead(0.5, props);
        }
    }
    else
    {
        if (animation_head_angle > 0)
        {
            props_head_rotated.rot.y = animation_head_angle--;
            applyProps(props_head_rotated);
            drawRobotHead(0.5, props);
        }
        else if (animation_head_angle < 0)
        {
            props_head_rotated.rot.y = animation_head_angle++;
            applyProps(props_head_rotated);
            drawRobotHead(0.5, props);
        }
        else
        {
            animation_head_angle = 0;
            drawRobotHead(0.5, props);
        }
    }

    glPopMatrix();
    glPopMatrix();

    Prop3D propsB;
    drawRobotBody(0.5, propsB, animation_wing_confirmation);

    Prop3D props_leg_left;
    props_leg_left.rot.y = 90;
    props_leg_left.scale = {0.5, 0.5, 0.5};
    props_leg_left.pos = {1.5, -6, -1.5};
    drawRobotLeftLeg(props_leg_left);

    Prop3D props_leg_right;
    props_leg_right.rot.y = 90;
    props_leg_right.scale = {0.5, 0.5, 0.5};
    props_leg_right.pos = {-1.5, -6, -1.5};
    drawRobotRightLeg(props_leg_right);

    ////drawPantShield(props);
    Prop3D props_hand_left;
    props_hand_left.scale = {0.3, 0.3, 0.3};
    props_hand_left.pos = {5, 10, -3};
    drawRobotLeftHand(props_hand_left);

    Prop3D props_hand_right;
    // props_hand_right.rot.y = 180;
    props_hand_right.scale = {0.3, 0.3, 0.3};
    props_hand_right.pos = {-5, 10, -3};
    drawRobotRightHand(props_hand_right);

    glPopMatrix();
}

void displayMe(void)
{
    // Register key listeners
    glutSpecialFunc(arrowKeyUp);
    glutKeyboardFunc(kbKeyUp);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    useTexture("sky");
    Prop3D background;
    background.pos = {0, 0, -200};
    drawCube(background, {200, 200, 200});

    initCamera(10, 100);
    ProcessAnimation();
    ApplyLight();
    useDefaultTexture();

    if (animation_fly_confirmation == 1)
    {
        if (animation_fly_angle < 45)
        {
            if (RobotFacing.z > 0)
            {
                MainRobotProps.rot.x = animation_fly_angle * RobotFacing.z;
            }
            else
            {
                MainRobotProps.rot.x = animation_fly_angle * -RobotFacing.z;
            }
            MainRobotProps.rot.z = animation_fly_angle * -RobotFacing.x;
            animation_fly_angle++;
            drawMainRobot(MainRobotProps);
        }
        else
        {
            if (RobotFacing.z > 0)
            {
                MainRobotProps.rot.x = animation_fly_angle * RobotFacing.z;
            }
            else
            {
                MainRobotProps.rot.x = animation_fly_angle * -RobotFacing.z;
            }
            MainRobotProps.rot.z = animation_fly_angle * -RobotFacing.x;
            drawMainRobot(MainRobotProps);
        }
    }
    else
    {
        if (animation_fly_angle > 0)
        {
            animation_fly_angle--;
            if (RobotFacing.z > 0)
            {
                MainRobotProps.rot.x = animation_fly_angle * RobotFacing.z;
            }
            else
            {
                MainRobotProps.rot.x = animation_fly_angle * -RobotFacing.z;
            }
            MainRobotProps.rot.z = animation_fly_angle * -RobotFacing.x;
            drawMainRobot(MainRobotProps);
        }
        else
        {
            drawMainRobot(MainRobotProps);
        }
    }
    setMaterial(MAT_WHITE);
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
    InitObjectsPosition();
    InitAnimationSequencesState();
    InitSpawnables();
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
    glutReshapeFunc(reshapeWindow);
    glutTimerFunc(0, timer, 0);

    glutMouseFunc(mouse);
    glutMotionFunc(drag);
    init();
    glutMainLoop();
    return 0;
};