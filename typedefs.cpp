#include "typedefs.h"

struct Vec3f {
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

struct Prop3D {
    Vec3f pos;
    Vec3f scale;
    Vec3d rot;
};