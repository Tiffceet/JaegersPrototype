#pragma once
#include "Object3D.h"
#include <iostream>
class Triangle : public Object3D {
public:
	Triangle(std::string id);
	Triangle(std::string id, Vector3Df position, Rotation rotation, Color3f color);
	void Draw(int);

	//Triangle(std::string id, Vector3Df position, Rotation rotation, Color3f color, float width, float height);
	//

	//void setWidth(float width);
	//void setHeight(float height);

	//float getWidth();
	//float getHeight();
private:
	float width;
	float height;
};