#include "Object3D.h"
#include <GL/glut.h>

Object3D::Object3D() {
	this->position = { 0,0,0 };
	this->rotation = { 0,0,0,0 };
	this->color = { 1,1,1 };
}

Object3D::Object3D(Vector3Df position, Rotation rotation, Color3f color) {
	this->position = position;
	this->rotation = rotation;
	this->color = color;
}

void Object3D::Draw(int frameNumber) {
	glColor3f(this->color.r, this->color.g, this->color.b);
	glRotatef(this->rotation.angle, this->rotation.axis.x, this->rotation.axis.y, this->rotation.axis.z);
}