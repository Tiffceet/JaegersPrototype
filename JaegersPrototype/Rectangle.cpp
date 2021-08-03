#include "Rectangle.h"
#include <GL/glut.h>

Rectangle::Rectangle() {
	Object3D();
}

void Rectangle::Draw(int frameNumber) {
	Object3D::Draw(frameNumber);
	glBegin(GL_QUADS);
	glVertex2f(0,0);
	glVertex2f(0.5, 0);
	glVertex2f(0.5, -0.5);
	glVertex2f(0, -0.5);
	glEnd();
}