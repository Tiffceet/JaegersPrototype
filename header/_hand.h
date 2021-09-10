#ifndef _HAND_H
#define _HAND_H
#include <gl/freeglut.h>
#include "typedefs.h"

void drawRobotHand(Prop3D props);
void drawRobotPalm(Prop3D props);
void drawRobotFinger(Prop3D props, Vec3d lower_fing_rotation, Vec3d upper_fing_rotation);
#endif