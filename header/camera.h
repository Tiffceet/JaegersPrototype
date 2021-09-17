#ifndef CAMERA_H
#define CAMERA_H
#include "typedefs.h"
void initCamera(float world_size, float view_sight);
void setCameraAt(Vec3f pos, Vec3f rot, float zoom);
void resetCamera();
void reshapeWindow(int w, int h);
void moveCamera(Vec3f delta);
void setViewMode(char vm);
void rotateCamera(Vec3f delta);
void changeZoom(float delta);

#endif