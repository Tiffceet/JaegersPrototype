#ifndef _HAND_H
#define _HAND_H
#include <gl/freeglut.h>
#include "typedefs.h"

extern Prop3D lhand_upper_joint;
extern Prop3D lhand_arm;
extern Prop3D lhand_upper_arm;
extern Prop3D lhand_lower_arm;
extern Prop3D lhand_palm;
extern Prop3D lhand_fing_1;
extern Prop3D lhand_fing_2;
extern Prop3D lhand_fing_3;
extern Prop3D lhand_fing_4;
extern Prop3D lhand_fing_5;

void drawRobotLeftHand(Prop3D props);
void drawLeftArm(Prop3D props);
void drawLeftUpperArm(Prop3D props);
void drawLeftLowerArm(Prop3D props);
void drawRobotPalm(Prop3D props);
void drawRobotFinger(Prop3D props, Vec3d lower_fing_rotation, Vec3d upper_fing_rotation);
#endif