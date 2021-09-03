#include "camera.h"
#include <GL/freeglut.h>

float camera_pos[] = {0, 0, 0};

int angleX = 0;
int angleY = 0;
int angleZ = 0;

float zoom_scale = 0.5;

/**
 * 0 = Ortho
 * 1 = Pers
 **/
int view_mode = 1;

void initCamera(int world_size, int world_sight)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (!view_mode)
    {
        glOrtho(-world_size, world_size, -world_size, world_size, 1, world_sight);
    }
    else
    {
        glFrustum(-world_size, world_size, -world_size, world_size, 1, world_sight);
    }
    glMatrixMode(GL_MODELVIEW);
    glScalef(zoom_scale, zoom_scale, zoom_scale);
    glTranslatef(0 - camera_pos[0], 0 - camera_pos[1], world_size / -2 - camera_pos[2]);
    glRotatef(angleX, 1, 0, 0);
    glRotatef(angleY, 0, 1, 0);
    glRotatef(angleZ, 0, 0, 1);
}

void moveCamera(float x, float y, float z)
{
    camera_pos[0] += x;
    camera_pos[1] += y;
    camera_pos[2] += z;
}

void resetCamera()
{
    camera_pos[0] = 0;
    camera_pos[1] = 0;
    camera_pos[2] = 0;
    angleX = 0;
    angleY = 0;
    angleZ = 0;
    zoom_scale = 0.5;
    view_mode = 1;
}

/**
 * 0 = Ortho
 * 1 = Pers
 **/
void setViewMode(int vm)
{
    view_mode = vm;
}

/**
 * Rotate the camera by certain angle
 * @param angle rotate by how many angle
 * @param x set 1 to ratate this axis
 * @param y set 1 to ratate this axis
 * @param z set 1 to ratate this axis
 **/
void rotateCamera(int angle, float x, float y, float z)
{
    if (x == 1)
    {
        angleX += angle;
    }
    if (y == 1)
    {
        angleY += angle;
    }
    if (z == 1)
    {
        angleZ += angle;
    }
}

/**
 * @param modifier to be added into current scale
 **/
void zoomCamera(float modifier)
{
    zoom_scale += modifier;
}