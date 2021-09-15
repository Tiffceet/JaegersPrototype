#include "_hand.h"
#include <gl/freeglut.h>
#include "typedefs.h"
#include "primitives.h"
#include "texture.h"
int hand_frame = 0;
void drawRobotLeftHand(Prop3D props)
{
    glPushMatrix();
    applyProps(props);
    useDefaultTexture();
    glColor3f(1, 1, 1);
    Prop3D lhand_upper_joint;
    lhand_upper_joint.origin.y = -2.5;
    lhand_upper_joint.rot.z = 30;
    useTexture("brick");
    drawCube(lhand_upper_joint, {2, 5, 2});

    Prop3D lhand_arm;
    drawLeftArm(lhand_arm);

    glPopMatrix();
}

void drawLeftArm(Prop3D props)
{
    glPushMatrix();
    applyProps(props);
    Prop3D lhand_upper_arm;
    lhand_upper_arm.pos = {2.5, -4, 0};
    lhand_upper_arm.rot.x = 90;
    useTexture("shiny");
    drawCylinder(lhand_upper_arm, 1, 2, 4, 30, 30);

    Prop3D lhand_lower_arm;
    lhand_lower_arm.pos = {2.5, -8, 0};
    lhand_lower_arm.rot.x = 90;
    useTexture("box");
    drawCylinder(lhand_lower_arm, 2, 1, 4, 30, 30);

    Prop3D lhand_palm;
    lhand_palm.rot.x = 90;
    lhand_palm.pos = {2.5, -12, 0};
    drawRobotPalm(lhand_palm);
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

    Prop3D lhand_fing_1;
    lhand_fing_1.pos = {-1.1, 0, 2};
    drawRobotFinger(lhand_fing_1, {0, 0, 0}, {0, 0, 0});

    Prop3D lhand_fing_2;
    lhand_fing_2.pos = {-0.4, 0, 2};
    drawRobotFinger(lhand_fing_2, {0, 0, 0}, {0, 0, 0});

    Prop3D lhand_fing_3;
    lhand_fing_3.pos = {0.3, 0, 2};
    drawRobotFinger(lhand_fing_3, {0, 0, 0}, {0, 0, 0});

    Prop3D lhand_fing_4;
    lhand_fing_4.pos = {1, 0, 2};
    drawRobotFinger(lhand_fing_4, {0, 0, 0}, {0, 0, 0});

    // Thumb
    Prop3D lhand_fing_5;
    lhand_fing_5.rot.y = 30;
    lhand_fing_5.pos = {1, 0, 2};
    drawRobotFinger(lhand_fing_5, {0, 0, 0}, {0, -30, 0});

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