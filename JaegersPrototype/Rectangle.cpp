#include "Rectangle.h"
#include <GL/glut.h>

Rectangle::Rectangle() : Object3D() {
	
}

Rectangle::Rectangle(Vector3Df position, Rotation rotation, Color3f color): Object3D(position, rotation, color) {

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