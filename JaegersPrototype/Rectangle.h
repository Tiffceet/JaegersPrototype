#pragma once
#include "Object3D.h"
#include <iostream>
class Rectangle : public Object3D {
public:
	Rectangle(std::string id);
	Rectangle(std::string id, Vector3Df position, Rotation rotation, Color3f color);
	Rectangle(std::string id, Vector3Df position, Rotation rotation, Color3f color, float width, float height);
	void Draw(int);

	void setWidth(float width);
	void setHeight(float height);

	float getWidth();
	float getHeight();
private:
	float width;
	float height;
};