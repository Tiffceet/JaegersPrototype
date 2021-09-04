#ifndef CAMERA_H
#define CAMERA_H
#include "typedefs.h"
void initCamera(float world_size, float view_sight);
void resetCamera();
void moveCamera(Vec3f delta);
void setViewMode(char vm);
void rotateCamera(Vec3d delta);
void changeZoom(float delta);

#endif