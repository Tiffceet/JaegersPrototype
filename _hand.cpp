#include "_hand.h"
#include <gl/freeglut.h>
#include "typedefs.h"
#include "primitives.h"
#include "texture.h"
int hand_frame = 0;
void drawRobotHand(Prop3D props)
{
    glPushMatrix();
    applyProps(props);
    useDefaultTexture();
    glColor3f(1, 1, 1);
    Prop3D upper_joint;
    upper_joint.origin.y = -2.5;
    upper_joint.rot.z = 30;
    useTexture("brick");
    drawCube(upper_joint, {2, 5, 2});

    Prop3D upper_arm;
    upper_arm.pos = {2.5, -4, 0};
    upper_arm.rot.x = 90;
    useTexture("shiny");
    drawCylinder(upper_arm, 1, 2, 4, 30, 30);

    Prop3D lower_arm;
    lower_arm.pos = {2.5, -8, 0};
    lower_arm.rot.x = 90;
    useTexture("box");
    drawCylinder(lower_arm, 2, 1, 4, 30, 30);

    // glColor3f(1, 0, 0);
    // Prop3D palm;
    // palm.pos = {2.5, -13.5, 0};
    // drawSphere(palm, 2, 30, 30);

    Prop3D palm;
    palm.rot.x = 90;
    palm.pos = {2.5, -12, 0};
    drawRobotPalm(palm);

    glPopMatrix();
}

void drawRobotPalm(Prop3D props)
{
    glPushMatrix();
    applyProps(props);
    Prop3D palm;
    palm.origin = {0, 0, 1};
    useTexture("brick");
    drawCube(palm, {3, 1, 3});

    Prop3D fing_1;
    fing_1.pos = {-1.1, 0, 2};
    drawRobotFinger(fing_1, {0, 0, 0}, {0, 0, 0});

    Prop3D fing_2;
    fing_2.pos = {-0.4, 0, 2};
    drawRobotFinger(fing_2, {0, 0, 0}, {0, 0, 0});

    Prop3D fing_3;
    fing_3.pos = {0.3, 0, 2};
    drawRobotFinger(fing_3, {0, 0, 0}, {0, 0, 0});

    Prop3D fing_4;
    fing_4.pos = {1, 0, 2};
    drawRobotFinger(fing_4, {0, 0, 0}, {0, 0, 0});

    // Thumb
    Prop3D fing_5;
    fing_5.rot.y = 30;
    fing_5.pos = {1, 0, 2};
    drawRobotFinger(fing_5, {0, 0, 0}, {0, -30, 0});

    glPopMatrix();
}

void drawRobotFinger(Prop3D props, Vec3d lower_fing_rotation, Vec3d upper_fing_rotation)
{
    glPushMatrix();
    applyProps(props);

    Prop3D lower_fing;
    Prop3D finger_joint;
    Prop3D upper_fing;

    useTexture("shiny");
    lower_fing.origin = {0, 0, 1};
    lower_fing.rot = lower_fing_rotation;
    drawCube(lower_fing, {0.5, 0.5, 2});

    useTexture("brick");
    finger_joint.pos = {0, 0, 2};
    drawSphere(finger_joint, 0.2, 30, 30);

    useTexture("box");
    upper_fing.pos = {0, 0, 2.2};
    upper_fing.rot = upper_fing_rotation;
    upper_fing.origin = {0, 0, 0.75};
    drawCube(upper_fing, {0.5, 0.5, 1.5});

    glPopMatrix();
}