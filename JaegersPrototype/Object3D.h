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
	void setOrigin(Vector3Df origin);

	Vector3Df getPosition();
	Rotation getRotation();
	Color3f getColor();
	Vector3Df getOrigin();
	std::string getId();
private:
	Vector3Df position;
	Rotation rotation;
	Color3f color;

	// Represent which part of the shape should be on origin
	// {0,0,0} would mean the center of the shape = origin
	// {1,0,0} would mean the most right of the shape = origin
	Vector3Df origin;
	std::string id;
};