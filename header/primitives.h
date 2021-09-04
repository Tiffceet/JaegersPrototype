#ifndef PRIMITIVES_H
#define PRIMITIVES_H
#include <GL/freeglut.h>
#include "typedefs.h"

void applyProps(Prop3D props);
void drawCube(Prop3D props, Vec3f size);
void draw2DCircle(Prop3D props, float r);
void drawCylinder(Prop3D props, GLdouble baseRadius, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks);
void drawPyramid(Prop3D props, float length, float width, float height);

#endif