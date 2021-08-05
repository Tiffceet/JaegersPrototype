#pragma once
#include "Object3D.h"
#include <iostream>
class Sphere : public Object3D {
public:
	Sphere(std::string id);
	Sphere(std::string id, Vector3Df position, Rotation rotation, Color3f color);
	Sphere(std::string id, Vector3Df position, Rotation rotation, Color3f color, float radius);

	void Draw(int);
private:
	float radius;
};