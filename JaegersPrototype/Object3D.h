#pragma once

#include "Vector3Df.h"
#include "Rotation.h"

class Object3D {
public:
	Vector3Df position;
	Rotation rotation;
	void Draw();
private:
};