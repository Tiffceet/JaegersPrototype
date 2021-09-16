#ifndef _SPAWNABLE_OBJECT_H_
#define _SPAWNABLE_OBJECT_H_

#include <gl/freeglut.h>
#include "typedefs.h"
#include "primitives.h"
#include <iostream>
#include <map>

extern std::map<std::string, bool> spawn_state;
extern std::map<std::string, Prop3D> spawnables_props;

void InitSpawnables();
void DrawSpawnables();
void SpawnSphere();

#endif