#ifndef LIGHTING_H
#define LIGHTING_H
#include "typedefs.h"
#include <gl/freeglut.h>
extern bool light_state;
void SetDistantLighting(Vec4f position, Rgba4f diff_l, Rgba4f amb_l, Rgba4f spec_l);
void toggleLight();
void ApplyLight();
void setMaterial(Material mat);
void moveLightPosition(Vec3f delta);
#endif