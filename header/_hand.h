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
extern Vec3d lhand_fing_1_lower_rot;
extern Vec3d lhand_fing_1_upper_rot;
extern Prop3D lhand_fing_2;
extern Vec3d lhand_fing_2_lower_rot;
extern Vec3d lhand_fing_2_upper_rot;
extern Prop3D lhand_fing_3;
extern Vec3d lhand_fing_3_lower_rot;
extern Vec3d lhand_fing_3_upper_rot;
extern Prop3D lhand_fing_4;
extern Vec3d lhand_fing_4_lower_rot;
extern Vec3d lhand_fing_4_upper_rot;
extern Prop3D lhand_fing_5;
extern Vec3d lhand_fing_5_lower_rot;
extern Vec3d lhand_fing_5_upper_rot;
extern Prop3D rhand_upper_joint;
extern Prop3D rhand_arm;
extern Prop3D rhand_upper_arm;
extern Prop3D rhand_lower_arm;
extern Prop3D rhand_palm;
extern Prop3D rhand_fing_1;
extern Vec3d rhand_fing_1_lower_rot;
extern Vec3d rhand_fing_1_upper_rot;
extern Prop3D rhand_fing_2;
extern Vec3d rhand_fing_2_lower_rot;
extern Vec3d rhand_fing_2_upper_rot;
extern Prop3D rhand_fing_3;
extern Vec3d rhand_fing_3_lower_rot;
extern Vec3d rhand_fing_3_upper_rot;
extern Prop3D rhand_fing_4;
extern Vec3d rhand_fing_4_lower_rot;
extern Vec3d rhand_fing_4_upper_rot;
extern Prop3D rhand_fing_5;
extern Vec3d rhand_fing_5_lower_rot;
extern Vec3d rhand_fing_5_upper_rot;

void drawRobotLeftHand(Prop3D props);
void drawRobotRightHand(Prop3D props);
void drawRobotPalm(Prop3D props, char side);
void drawRobotFinger(Prop3D props, Vec3d lower_fing_rotation, Vec3d upper_fing_rotation);
#endif