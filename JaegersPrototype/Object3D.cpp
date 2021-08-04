#include "Object3D.h"
#include <GL/glut.h>
#include <iostream>

Object3D::Object3D(std::string id) {
	this->id = id;
	this->position = { 0,0,0 };
	this->rotation = { 0,0,0,0 };
	this->color = { 1,1,1 };
}

Object3D::Object3D(std::string id, Vector3Df position, Rotation rotation, Color3f color) {
	this->id = id;
	this->position = position;
	this->rotation = rotation;
	this->color = color;
}

void Object3D::Draw(int frameNumber) {
	glColor3f(this->color.r, this->color.g, this->color.b);
	glTranslatef(this->position.x, this->position.y, this->position.z);
	glRotatef(this->rotation.angle, this->rotation.axis.x, this->rotation.axis.y, this->rotation.axis.z);
}

void Object3D::setPosition(Vector3Df pos) {
	this->position = pos;
}
void Object3D::setRotation(Rotation rotate) {
	this->rotation = rotate;
}
void Object3D::setColor(Color3f color) {
	this->color = color;
}

Vector3Df Object3D::getPosition() {
	return this->position;
}
Rotation Object3D::getRotation() {
	return this->rotation;
}
Color3f Object3D::getColor() {
	return this->color;
}

std::string Object3D::getId() {
	return this->id;
}