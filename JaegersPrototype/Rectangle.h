#pragma once
#include "Object3D.h"
class Rectangle : public Object3D {
public:
	Rectangle();
	Rectangle(Vector3Df position, Rotation rotation, Color3f color);
	void Draw(int);
};