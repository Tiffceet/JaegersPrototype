#include "body.h"
#include <GL/freeglut.h>

void body() {
	glPointSize(15);
	glColor3f(1, 1, 1);
	glBegin(GL_POINTS);
	glVertex3f(0,0,-2);
	glEnd();
}