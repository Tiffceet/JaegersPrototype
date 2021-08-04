#pragma once

#include "Vector3Df.h"
#include "Rotation.h"
#include "Color3f.h"
#include <iostream>

class Object3D {
public:
	Object3D(std::string id);
	Object3D(std::string id, Vector3Df position, Rotation rotation, Color3f color);
	
	virtual void Draw(int frameNumber);
	void setPosition(Vector3Df pos);
	void setRotation(Rotation rotate);
	void setColor(Color3f color);

	Vector3Df getPosition();
	Rotation getRotation();
	Color3f getColor();
	std::string getId();
private:
	Vector3Df position;
	Rotation rotation;
	Color3f color;
	std::string id;
};