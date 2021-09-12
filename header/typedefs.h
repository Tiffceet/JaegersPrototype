#ifndef TYPEDEFS_H
#define TYPEDEFS_H
#include <gl/freeglut.h>
struct Vec2d
{
    int x;
    int y;
};
struct Vec3f
{
    float x;
    float y;
    float z;
};

struct Vec4f
{
    float w;
    float x;
    float y;
    float z;
};

struct Vec3d
{
    int x;
    int y;
    int z;
};
struct Vec4d
{
    int w;
    int x;
    int y;
    int z;
};

struct Rgba4f
{
    float r;
    float g;
    float b;
    float a;
};

struct Prop3D
{
    Vec3f origin = {0, 0, 0};
    Vec3f pos = {0, 0, 0};
    Vec3f scale = {1, 1, 1};
    Vec3d rot = {0, 0, 0};
};

struct Material
{
    Rgba4f amb;
    Rgba4f diff;
    Rgba4f spec;
    GLfloat shinyness;
};

#endif