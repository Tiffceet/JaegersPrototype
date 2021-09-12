#include "body.h"
#include <GL/freeglut.h>
#include "typedefs.h"
#include "primitives.h"
#include "texture.h"

void drowRobotBody(double x, Prop3D props) {
	drowAbdomen(x, props);
	drowGem(x, props);
	drowArmor(x, props);
}

void drowAbdomen(double x, Prop3D props) {
	useTexture("brick");

	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, 5 * x, -3 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2 * x, 5 * x, -3 * x);
	glTexCoord2f(1, 0.66);
	glVertex3f(2 * x, 5 * x, -x);
	glTexCoord2f(0.75, 1);
	glVertex3f(x, 5 * x, 0);
	glTexCoord2f(0.25, 1);
	glVertex3f(-x, 5 * x, 0);
	glTexCoord2f(0, 0.66);
	glVertex3f(-2 * x, 5 * x, -x);
	glEnd();

	glBegin(GL_QUADS);
	//back//
	glTexCoord2f(0, 1);
	glVertex3f(-2 * x, 5 * x, -3 * x);
	glTexCoord2f(1, 1);
	glVertex3f(2 * x, 5 * x, -3 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2 * x, 0, -3 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, 0, -3 * x);

	//front//
	glTexCoord2f(0, 1);
	glVertex3f(-x, 5 * x, 0);
	glTexCoord2f(1, 1);
	glVertex3f(x, 5 * x, 0);
	glTexCoord2f(1, 0);
	glVertex3f(x, 0, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-x, 0, 0);

	//left//
	glTexCoord2f(0, 1);
	glVertex3f(-2 * x, 5 * x, -3 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-2 * x, 5 * x, -x);
	glTexCoord2f(1, 0);
	glVertex3f(-2 * x, 0, -x);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, 0, -3 * x);

	//right//
	glTexCoord2f(0, 1);
	glVertex3f(2 * x, 5 * x, -3 * x);
	glTexCoord2f(1, 1);
	glVertex3f(2 * x, 5 * x, -x);
	glTexCoord2f(1, 0);
	glVertex3f(2 * x, 0, -x);
	glTexCoord2f(0, 0);
	glVertex3f(2 * x, 0, -3 * x);

	//left_side//
	glTexCoord2f(0, 1);
	glVertex3f(-2 * x, 5 * x, -x);
	glTexCoord2f(1, 1);
	glVertex3f(-x, 5 * x, 0);
	glTexCoord2f(1, 0);
	glVertex3f(-x, 0, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, 0, -x);

	//right_side//
	glTexCoord2f(0, 1);
	glVertex3f(2 * x, 5 * x, -x);
	glTexCoord2f(1, 1);
	glVertex3f(x, 5 * x, 0);
	glTexCoord2f(1, 0);
	glVertex3f(x, 0, 0);
	glTexCoord2f(0, 0);
	glVertex3f(2 * x, 0, -x);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, 0, -3 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2 * x, 0, -3 * x);
	glTexCoord2f(1, 0.66);
	glVertex3f(2 * x, 0, -x);
	glTexCoord2f(0.75, 1);
	glVertex3f(x, 0, 0);
	glTexCoord2f(0.25, 1);
	glVertex3f(-x, 0, 0);
	glTexCoord2f(0, 0.66);
	glVertex3f(-2 * x, 0, -x);
	glEnd();
}

void drowGem(double x, Prop3D props) {
	useTexture("shiny");

	//back//
	glBegin(GL_POLYGON);
	glTexCoord2f(0.25, 1);
	glVertex3f(-0.5 * x, 4 * x, 0);
	glTexCoord2f(0.75, 1);
	glVertex3f(0.5 * x, 4 * x, 0);
	glTexCoord2f(1, 0.5);
	glVertex3f(x, 3 * x, 0);
	glTexCoord2f(0.75, 0);
	glVertex3f(0.5 * x, 2 * x, 0);
	glTexCoord2f(0.25, 0);
	glVertex3f(-0.5 * x, 2 * x, 0);
	glTexCoord2f(0, 0.5);
	glVertex3f(-x, 3 * x, 0);
	glEnd();

	//front//
	glBegin(GL_POLYGON);
	glTexCoord2f(0.25, 1);
	glVertex3f(-0.3 * x, 3.8 * x, 0.5 * x);
	glTexCoord2f(0.75, 1);
	glVertex3f(0.3 * x, 3.8 * x, 0.5 * x);
	glTexCoord2f(1, 0.5);
	glVertex3f(0.8 * x, 3 * x, 0.5 * x);
	glTexCoord2f(0.75, 0);
	glVertex3f(0.3 * x, 2.2 * x, 0.5 * x);
	glTexCoord2f(0.25, 0);
	glVertex3f(-0.3 * x, 2.2 * x, 0.5 * x);
	glTexCoord2f(0, 0.5);
	glVertex3f(-0.8 * x, 3 * x, 0.5 * x);
	glEnd();

	//top//
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(-0.5 * x, 4 * x, 0);
	glTexCoord2f(1, 1);
	glVertex3f(0.5 * x, 4 * x, 0);
	glTexCoord2f(1, 0);
	glVertex3f(0.3 * x, 3.8 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-0.3 * x, 3.8 * x, 0.5 * x);

	//bottom//
	glTexCoord2f(0, 1);
	glVertex3f(-0.5 * x, 2 * x, 0);
	glTexCoord2f(1, 1);
	glVertex3f(0.5 * x, 2 * x, 0);
	glTexCoord2f(1, 0);
	glVertex3f(0.3 * x, 2.2 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-0.3 * x, 2.2 * x, 0.5 * x);

	//top_left
	glTexCoord2f(0, 1);
	glVertex3f(-0.5 * x, 4 * x, 0);
	glTexCoord2f(1, 1);
	glVertex3f(-0.3 * x, 3.8 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-0.8 * x, 3 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-x, 3 * x, 0);

	//bottom_left
	glTexCoord2f(0, 1);
	glVertex3f(-x, 3 * x, 0);
	glTexCoord2f(1, 1);
	glVertex3f(-0.8 * x, 3 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-0.3 * x, 2.2 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-0.5 * x, 2 * x, 0);

	//top_right
	glTexCoord2f(0, 1);
	glVertex3f(0.3 * x, 3.8 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(0.5 * x, 4 * x, 0);
	glTexCoord2f(1, 0);
	glVertex3f(x, 3 * x, 0);
	glTexCoord2f(0, 0);
	glVertex3f(0.8 * x, 3 * x, 0.5 * x);

	//bottom_right
	glTexCoord2f(0, 1);
	glVertex3f(0.8 * x, 3 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(x, 3 * x, 0);
	glTexCoord2f(1, 0);
	glVertex3f(0.5 * x, 2 * x, 0);
	glTexCoord2f(0, 0);
	glVertex3f(0.3 * x, 2.2 * x, 0.5 * x);
	glEnd();
}

void drowArmor(double x, Prop3D props) {
	useTexture("box");

	//back//
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(-3 * x, 7 * x, -3.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(3 * x, 7 * x, -3.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(3 * x, 3 * x, -3.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-3 * x, 3 * x, -3.5 * x);
	glEnd();

	//middle_left
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 1);
	glVertex3f(-3 * x, 7 * x, -3.5 * x);
	glTexCoord2f(0.75, 1);
	glVertex3f(-3 * x, 7 * x, -x);
	glTexCoord2f(1, 0.5);
	glVertex3f(-3 * x, 5 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-3 * x, 3 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-3 * x, 3 * x, -3.5 * x);
	glEnd();

	//middle_right
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 1);
	glVertex3f(3 * x, 7 * x, -3.5 * x);
	glTexCoord2f(0.75, 1);
	glVertex3f(3 * x, 7 * x, -x);
	glTexCoord2f(1, 0.5);
	glVertex3f(3 * x, 5 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(3 * x, 3 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(3 * x, 3 * x, -3.5 * x);
	glEnd();

	//middle_front
	glBegin(GL_QUADS);
	glTexCoord2f(1, 0);
	glVertex3f(-3 * x, 7 * x, -x);
	glTexCoord2f(1, 1);
	glVertex3f(3 * x, 7 * x, -x);
	glTexCoord2f(0, 1);
	glVertex3f(3 * x, 5 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-3 * x, 5 * x, 0.5 * x);
	glEnd();

	//middle_front
	glBegin(GL_QUADS);
	glTexCoord2f(0, 1);
	glVertex3f(-3 * x, 5 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(3 * x, 5 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(3 * x, 4 * x, 0.5 * x); 
	glTexCoord2f(0, 0);
	glVertex3f(-3 * x, 4 * x, 0.5 * x);

	glTexCoord2f(0, 1);
	glVertex3f(0.5 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(3 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(3 * x, 3 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(x, 3 * x, 0.5 * x);

	glTexCoord2f(0, 1);
	glVertex3f(-3 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-0.5 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-x, 3 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-3 * x, 3 * x, 0.5 * x);
	glEnd();

}