#include <GL/freeglut.h>
#include "typedefs.h"
#include <iostream>

Vec3f camera_pos = {0, 0, 50};
Vec3f look_direction = {0, 0, -1};
Vec3f camera_rot = {0, 0, 0};
float zoom_factor = 1;
char view_mode = 'o';
float w_size;
float v_sight;
float win_ratio = 1;

void initCamera(float world_size, float view_sight)
{
    w_size = world_size;
    v_sight = view_sight;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    switch (view_mode)
    {
    case 'o':
        glOrtho(-w_size * zoom_factor * win_ratio, w_size * zoom_factor * win_ratio, -w_size * zoom_factor, w_size * zoom_factor, 1, v_sight);
        break;
    case 'p':
        glFrustum(-w_size * zoom_factor * win_ratio, w_size * zoom_factor * win_ratio, -w_size * zoom_factor, w_size * zoom_factor, 1, v_sight);
        break;
    }
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(camera_pos.x, camera_pos.y, camera_pos.z, camera_pos.x + look_direction.x, camera_pos.y + look_direction.y, camera_pos.z + look_direction.z, 0, 1, 0);
    glRotatef(camera_rot.x, 1, 0, 0);
    glRotatef(camera_rot.y, 0, 1, 0);
    glRotatef(camera_rot.z, 0, 0, 1);

    // Debug
    std::cout << "Pos: {" << camera_pos.x << ", " << camera_pos.y << ", " << camera_pos.z << "}; ";
    std::cout << "Cam Rotate: {" << camera_rot.x << ", " << camera_rot.y << ", " << camera_rot.z << "}; ";
    std::cout << "Zoom: " << zoom_factor << std::endl;
}

void reshapeWindow(int w, int h)
{
    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0)
        h = 1;

    float ratio = w * 1.0 / h;
    win_ratio = ratio;

    glViewport(0, 0, w, h);
}

void setCameraAt(Vec3f pos, Vec3f rot, float zoom)
{
    camera_pos = pos;
    camera_rot = rot;
    zoom_factor = zoom;
}

void resetCamera()
{
    camera_pos = {0, 0, 0};
    camera_rot = {0, 0, 0};
    zoom_factor = 1;
}

void moveCamera(Vec3f delta)
{
    camera_pos.x += delta.x;
    camera_pos.y += delta.y;
    camera_pos.z += delta.z;
}

void setViewMode(char vm)
{
    view_mode = vm;
}

void rotateCamera(Vec3f delta)
{
    camera_rot.x += delta.x;
    camera_rot.y += delta.y;
    camera_rot.z += delta.z;
}

void changeZoom(float delta)
{
    zoom_factor += delta;
}