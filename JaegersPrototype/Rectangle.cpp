#include "Rectangle.h"
#include <GL/glut.h>
Rectangle::Rectangle(std::string id) : Object3D(id) {
	this->width = 0;
	this->height = 0;
}

Rectangle::Rectangle(std::string id, Vector3Df position, Rotation rotation, Color3f color) : Object3D(id, position, rotation, color) {
	this->width = 0;
	this->height = 0;
}

Rectangle::Rectangle(std::string id, Vector3Df position, Rotation rotation, Color3f color, float width, float height) : Object3D(id, position, rotation, color) {
	this->width = width;
	this->height = height;
}

void Rectangle::Draw(int frameNumber) {
	Object3D::Draw(frameNumber);
	Vector3Df origin = this->getOrigin();
	float halve_w = this->width / 2;
	float halve_h = this->height / 2;

	glPushMatrix();
	glTranslatef(-origin.x * halve_w, -origin.y * halve_h, 0);
	glBegin(GL_QUADS);
	glVertex2f(-halve_w, halve_h);
	glVertex2f(halve_w, halve_h);
	glVertex2f(halve_w, -halve_h);
	glVertex2f(-halve_w, -halve_h);
	glEnd();
	glPopMatrix();

	// Debug: Draw Point on origin
	glPointSize(10);
	glColor3f(1, 1, 1);
	glBegin(GL_POINTS);
	glVertex3f(0,0, -0.5);
	glEnd();
}

void Rectangle::setWidth(float width) { this->width = width; }
void Rectangle::setHeight(float height) { this->height = height; }

float Rectangle::getWidth() { return this->width; }
float Rectangle::getHeight() { return this->height; }