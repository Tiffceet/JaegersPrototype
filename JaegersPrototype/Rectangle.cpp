#include "Rectangle.h"
#include <GL/glut.h>

Rectangle::Rectangle() : Object3D() {
	this->width = 0;
	this->height = 0;
}

Rectangle::Rectangle(Vector3Df position, Rotation rotation, Color3f color) : Object3D(position, rotation, color) {
	this->width = 0;
	this->height = 0;
}

Rectangle::Rectangle(Vector3Df position, Rotation rotation, Color3f color, float width, float height) : Rectangle(position, rotation, color) {
	this->width = width;
	this->height = height;
}

void Rectangle::Draw(int frameNumber) {
	Object3D::Draw(frameNumber);
	float halve_w = this->width / 2;
	float halve_h = this->height / 2;
	glBegin(GL_QUADS);
	glVertex2f(-halve_w, halve_h);
	glVertex2f(halve_w, halve_h);
	glVertex2f(halve_w, -halve_h);
	glVertex2f(-halve_w, -halve_h);
	glEnd();
}

void Rectangle::setWidth(float width) { this->width = width; }
void Rectangle::setHeight(float height) { this->height = height; }

float Rectangle::getWidth() { return this->width; }
float Rectangle::getHeight() { return this->height; }