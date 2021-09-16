#include "spawnable_object.h"
#include <gl/freeglut.h>
#include "typedefs.h"
#include "primitives.h"
#include <map>
#include <iostream>
#include "texture.h"

std::map<std::string, bool> spawn_state;
std::map<std::string, Prop3D> spawnables_props;

void InitSpawnables()
{
    Prop3D empty_props;
    spawn_state["sphere"] = false;
    spawnables_props["sphere"] = empty_props;
}

void DrawSpawnables()
{
    SpawnSphere();
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