#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include <GL/freeglut.h>
#include "typedefs.h"

void applyProps(Prop3D props);
void applyPropsDebug(Prop3D props);
void drawCube(Prop3D props, Vec3f size);
void draw2DCircle(Prop3D props, float r);
void draw2DSquare(Prop3D props, float size);
void drawCylinder(Prop3D props, GLdouble baseRadius, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks);
void drawSphere(Prop3D props, GLdouble radius, GLint slices, GLint stacks);
void drawPyramid(Prop3D props, float length, float width, float height);
Vec3f calculate_normal(Vec3f pt1, Vec3f pt2, Vec3f pt3);

#endif