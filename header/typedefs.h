#ifndef TYPEDEFS_H
#define TYPEDEFS_H

struct Vec3f
{
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

struct Prop3D
{
    Vec3f origin = {0, 0, 0};
    Vec3f pos = {0, 0, 0};
    Vec3f scale = {1, 1, 1};
    Vec3d rot = {0, 0, 0};
};

#endif