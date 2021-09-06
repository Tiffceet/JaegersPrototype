#ifndef LIGHTING_H
#define LIGHTING_H
#include "typedefs.h"
#include <gl/freeglut.h>
void SetDistantLighting(Vec4f position, Rgba4f diff_l, Rgba4f amb_l, Rgba4f spec_l);
void toggleLight();
void ApplyLight();
void setMaterial(Rgba4f amb, Rgba4f diff, Rgba4f spec, GLfloat shinyness);
void moveLightPosition(Vec3f delta);
#endif