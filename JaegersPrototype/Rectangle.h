#pragma once
#include "Object3D.h"
class Rectangle : public Object3D {
public:
	Rectangle();
	Rectangle(Vector3Df position, Rotation rotation, Color3f color);
	Rectangle(Vector3Df position, Rotation rotation, Color3f color, float width, float height);
	void Draw(int);

	void setWidth(float width);
	void setHeight(float height);

	float getWidth();
	float getHeight();
private:
	float width;
	float height;
};