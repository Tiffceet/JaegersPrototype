#include "_hand.h"
#include <gl/freeglut.h>
#include "typedefs.h"
#include "primitives.h"
#include "texture.h"
int hand_frame = 0;
Prop3D lhand_upper_joint;
Prop3D lhand_arm;
Prop3D lhand_upper_arm;
Prop3D lhand_lower_arm;
Prop3D lhand_palm;
Prop3D lhand_fing_1;
Vec3d lhand_fing_1_lower_rot;
Vec3d lhand_fing_1_upper_rot;
Prop3D lhand_fing_2;
Vec3d lhand_fing_2_lower_rot;
Vec3d lhand_fing_2_upper_rot;
Prop3D lhand_fing_3;
Vec3d lhand_fing_3_lower_rot;
Vec3d lhand_fing_3_upper_rot;
Prop3D lhand_fing_4;
Vec3d lhand_fing_4_lower_rot;
Vec3d lhand_fing_4_upper_rot;
Prop3D lhand_fing_5;
Vec3d lhand_fing_5_lower_rot;
Vec3d lhand_fing_5_upper_rot;
Prop3D rhand_upper_joint;
Prop3D rhand_arm;
Prop3D rhand_upper_arm;
Prop3D rhand_lower_arm;
Prop3D rhand_palm;
Prop3D rhand_fing_1;
Vec3d rhand_fing_1_lower_rot;
Vec3d rhand_fing_1_upper_rot;
Prop3D rhand_fing_2;
Vec3d rhand_fing_2_lower_rot;
Vec3d rhand_fing_2_upper_rot;
Prop3D rhand_fing_3;
Vec3d rhand_fing_3_lower_rot;
Vec3d rhand_fing_3_upper_rot;
Prop3D rhand_fing_4;
Vec3d rhand_fing_4_lower_rot;
Vec3d rhand_fing_4_upper_rot;
Prop3D rhand_fing_5;
Vec3d rhand_fing_5_lower_rot;
Vec3d rhand_fing_5_upper_rot;
void drawRobotLeftHand(Prop3D props)
{
    glPushMatrix();
    applyProps(props);
    useDefaultTexture();
    glColor3f(1, 1, 1);

    glPushMatrix();
    applyProps(lhand_arm);
    useTexture("shiny");
    drawCube(lhand_upper_joint, {2, 5, 2});

    glPushMatrix();
    applyProps(lhand_upper_arm);
    useTexture("armor");
    Prop3D clean;
    drawCylinder(clean, 1, 2, 4, 30, 30);

    glPushMatrix();
    applyProps(lhand_lower_arm);
    useTexture("armor");
    drawCylinder(clean, 2, 1, 4, 30, 30);
    drawRobotPalm(lhand_palm, 'l');

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}
void drawRobotRightHand(Prop3D props)
{
    glPushMatrix();
    applyProps(props);
    useDefaultTexture();
    glColor3f(1, 1, 1);

    glPushMatrix();
    applyProps(rhand_arm);
    useTexture("shiny");
    drawCube(rhand_upper_joint, {2, 5, 2});

    glPushMatrix();
    applyProps(rhand_upper_arm);
    useTexture("armor");
    Prop3D clean;
    drawCylinder(clean, 1, 2, 4, 30, 30);

    glPushMatrix();
    applyProps(rhand_lower_arm);
    useTexture("armor");
    drawCylinder(clean, 2, 1, 4, 30, 30);
    drawRobotPalm(rhand_palm, 'r');

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void drawRobotPalm(Prop3D props, char side)
{
    glPushMatrix();
    applyProps(props);
    Prop3D palm;
    palm.origin = {0, 0, 1};
    useTexture("shiny");
    drawCube(palm, {3, 1, 3});
    if (side == 'l')
    {
        drawRobotFinger(lhand_fing_1, lhand_fing_1_lower_rot, lhand_fing_1_upper_rot);
        drawRobotFinger(lhand_fing_2, lhand_fing_2_lower_rot, lhand_fing_2_upper_rot);
        drawRobotFinger(lhand_fing_3, lhand_fing_3_lower_rot, lhand_fing_3_upper_rot);
        drawRobotFinger(lhand_fing_4, lhand_fing_4_lower_rot, lhand_fing_4_upper_rot);
        // Thumb
        drawRobotFinger(lhand_fing_5, lhand_fing_5_lower_rot, lhand_fing_5_upper_rot);
    } else {
        drawRobotFinger(rhand_fing_1, rhand_fing_1_lower_rot, rhand_fing_1_upper_rot);
        drawRobotFinger(rhand_fing_2, rhand_fing_2_lower_rot, rhand_fing_2_upper_rot);
        drawRobotFinger(rhand_fing_3, rhand_fing_3_lower_rot, rhand_fing_3_upper_rot);
        drawRobotFinger(rhand_fing_4, rhand_fing_4_lower_rot, rhand_fing_4_upper_rot);
        // Thumb
        drawRobotFinger(rhand_fing_5, rhand_fing_5_lower_rot, rhand_fing_5_upper_rot);
    }

    glPopMatrix();
}

void drawRobotFinger(Prop3D props, Vec3d lower_fing_rotation, Vec3d upper_fing_rotation)
{
    glPushMatrix();
    applyProps(props);

    Prop3D lower_fing;
    Prop3D finger_joint;
    Prop3D upper_fing;
    Prop3D clean_props;
    
    useTexture("shiny");
    lower_fing.origin = {0, 0, 1};
    lower_fing.rot = lower_fing_rotation;
    applyProps(lower_fing);
    drawCube(clean_props, {0.5, 0.5, 2});

    useTexture("armor");
    finger_joint.pos = {0, 0, 1};
    drawSphere(finger_joint, 0.2, 30, 30);

    useTexture("shiny");
    upper_fing.pos = {0, 0, 1.15};
    upper_fing.rot = upper_fing_rotation;
    upper_fing.origin = {0, 0, 0.75};
    drawCube(upper_fing, {0.5, 0.5, 1.5});

    glPopMatrix();
}