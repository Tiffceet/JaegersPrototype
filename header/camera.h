#ifndef CAMERA_H
#define CAMERA_H

/**
 * Set projection matrix
 * @param world_size (Optional) how big should the world be; Default = 10
 * @param world_sight (Optional) how far should the projection able to project; Default = 10
 **/
void initCamera(int world_size = 10, int world_sight = 10);

void moveCamera(float x, float y, float z);
void rotateCamera(int angle, float x, float y, float z);
void zoomCamera(float modifier);
void setViewMode(int vm);
void resetCamera();

#endif