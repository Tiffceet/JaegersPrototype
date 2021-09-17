#include "spawnable_object.h"
#include <gl/freeglut.h>
#include "typedefs.h"
#include "primitives.h"
#include <map>
#include <iostream>
#include "texture.h"
#include "lighting.h"

std::map<std::string, bool> spawn_state;
std::map<std::string, Prop3D> spawnables_props;

void InitSpawnables()
{
    Prop3D empty_props;
    spawn_state["sphere"] = false;
    spawn_state["lazer"] = false;

    spawnables_props["sphere"] = empty_props;
    spawnables_props["lazer"] = empty_props;
}

void DrawSpawnables()
{
    SpawnSphere();
    SpawnCyLazer();
}

void SpawnSphere()
{
    if (!spawn_state["sphere"])
    {
        return;
    }
    useDefaultTexture();
    drawSphere(spawnables_props["sphere"], 1, 30, 30);
}

void SpawnCyLazer()
{
    if (!spawn_state["lazer"])
    {
        return;
    }
    useDefaultTexture();
    glColor3f(1,0,0);
    glDisable(GL_LIGHTING);
    drawCylinder(spawnables_props["lazer"], 1, 1.1, 2, 30, 30);
    if (light_state)
    {
        glEnable(GL_LIGHTING);
    }
}