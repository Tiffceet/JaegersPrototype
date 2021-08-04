#include "Triangle.h"
#include <GL/glut.h>
Triangle::Triangle(std::string id) : Object3D(id) {

}

Triangle::Triangle(std::string id, Vector3Df position, Rotation rotation, Color3f color) : Object3D(id, position, rotation, color){

}

void Triangle::Draw(int frame) {
	Object3D::Draw(frame);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0, 0);
	glVertex2f(0, 1);
	glEnd();
}