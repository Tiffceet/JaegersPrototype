#pragma once

#include "Vector3Df.h"
#include "Rotation.h"
#include "Color3f.h"
class Object3D {
public:
	Vector3Df position;
	Rotation rotation;
	Color3f color;

	Object3D();
	Object3D(Vector3Df position, Rotation rotation, Color3f color);
	virtual void Draw(int frameNumber);
	
private:
};