#include "Sphere.h"
#include <GL/glut.h>
Sphere::Sphere(std::string id):Object3D(id) {
	this->radius = 0;
}

Sphere::Sphere(std::string id, Vector3Df position, Rotation rotation, Color3f color) : Object3D(id,position, rotation, color) {
	this->radius = 0;
}

Sphere::Sphere(std::string id, Vector3Df position, Rotation rotation, Color3f color, float radius) : Object3D(id, position, rotation, color) {
	this->radius = radius;
}

void Sphere::Draw(int frame) {
	Object3D::Draw(frame);
	GLUquadricObj* var = gluNewQuadric();
	glRotatef(frame, 1, 1, 1);
	gluQuadricDrawStyle(var, GLU_LINE);
	gluSphere(var, this->radius, 30000, 30000);
}