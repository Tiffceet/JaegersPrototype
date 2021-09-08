#include "_hand.h"
#include <gl/freeglut.h>
#include "typedefs.h"
#include "primitives.h"
#include "texture.h"
int hand_frame = 0;
void drawRobotHand(Prop3D props) {
    glPushMatrix();
    applyProps(props);
    useTexture(-1);
    glColor3f(1,1,1);
    Prop3D upper_joint;
    upper_joint.origin.y = -2.5;
    upper_joint.rot.z = 30;
    drawCube(upper_joint, {2,5,2});

    Prop3D upper_arm; 
    upper_arm.pos = {2.5, -4, 0};
    upper_arm.rot.x = 90;
    drawCylinder(upper_arm, 1, 2, 4, 30, 30);

    Prop3D lower_arm;
    lower_arm.pos = {2.5, -8, 0};
    lower_arm.rot.x = 90;
    drawCylinder(lower_arm, 2, 1, 4, 30, 30);

    glColor3f(1,0,0);
    Prop3D palm;
    palm.pos = {2.5, -13.5, 0};
    drawSphere(palm, 2, 30, 30);

    glPopMatrix();
}