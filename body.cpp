#include "body.h"
#include <GL/freeglut.h>
#include "typedefs.h"
#include "primitives.h"
#include "texture.h"

int gemrot = 0;

void drawRobotBody(double x, Prop3D props) {
	drawAbdomen(x, props);


	drawGem(x, props);


	drawArmor(x, props);

	glPushMatrix();
	Prop3D props_wing_right;
	props_wing_right.pos.x = 1.25 * x;
	props_wing_right.pos.z = (-3.6 * x);
	props_wing_right.pos.y = (5 * x);
	//props_wing_right.rot.z = (75);
	applyProps(props_wing_right);
	drawWingRight(x, props_wing_right);
	glPopMatrix();

	glPushMatrix();
	Prop3D props_wing_left;
	props_wing_left.pos.x = -1.25 * x;
	props_wing_left.pos.z = (-3.6 * x);
	props_wing_left.pos.y = (5 * x);
	//props_wing_left.rot.z = (-75);
	applyProps(props_wing_left);
	drawWingLeft(x, props_wing_left);
	glPopMatrix();
}

void drawAbdomen(double x, Prop3D props) {
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

void drawGem(double x, Prop3D props) {
	glPushMatrix();

	useTexture("shiny");
	glColor3f(0, 0, 1);
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

	glPopMatrix();
}

void drawArmor(double x, Prop3D props) {
	useTexture("box");

	glBegin(GL_QUADS);
	//Armor_top_top
	glTexCoord2f(0, 1);
	glVertex3f(-x, 7.5 * x, -3.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(x, 7.5 * x, -3.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(x, 7.5 * x, -1.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-x, 7.5 * x, -1.5 * x);

	//Armor_top_front
	glTexCoord2f(0, 1);
	glVertex3f(-x, 7.5 * x, -1.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(x, 7.5 * x, -1.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(3 * x, 7 * x, -x);
	glTexCoord2f(0, 0);
	glVertex3f(-3 * x, 7 * x, -x);

	//Armor_top_back
	glTexCoord2f(0, 1);
	glVertex3f(-x, 7.5 * x, -3.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(x, 7.5 * x, -3.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(3 * x, 7 * x, -3.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-3 * x, 7 * x, -3.5 * x);

	//Armor_top_left
	glTexCoord2f(0, 1);
	glVertex3f(-x, 7.5 * x, -3.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-x, 7.5 * x, -1.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-3 * x, 7 * x, -x);
	glTexCoord2f(0, 0);
	glVertex3f(-3 * x, 7 * x, -3.5 * x);

	//Armor_top_right
	glTexCoord2f(0, 1);
	glVertex3f(x, 7.5 * x, -3.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(x, 7.5 * x, -1.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(3 * x, 7 * x, -x);
	glTexCoord2f(0, 0);
	glVertex3f(3 * x, 7 * x, -3.5 * x);
	glEnd();

	glBegin(GL_QUADS);
	//Armor_middle_back
	glTexCoord2f(0, 1);
	glVertex3f(-3 * x, 7 * x, -3.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(3 * x, 7 * x, -3.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(3 * x, 4 * x, -3.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-3 * x, 4 * x, -3.5 * x);

	//Armor_bottom_back
	glTexCoord2f(0, 1);
	glVertex3f(-3 * x, 4 * x, -3.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(3 * x, 4 * x, -3.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2.5 * x, 1.5 * x, -3.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-2.5 * x, 1.5 * x, -3.5 * x);
	glEnd();

	//Armor_middle_left
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 1);
	glVertex3f(-3 * x, 7 * x, -3.5 * x);
	glTexCoord2f(0.75, 1);
	glVertex3f(-3 * x, 7 * x, -x);
	glTexCoord2f(1, 0);
	glVertex3f(-3 * x, 4 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-3 * x, 4 * x, -3.5 * x);
	glEnd();

	//Armor_middle_right
	glBegin(GL_POLYGON);
	glTexCoord2f(0, 1);
	glVertex3f(3 * x, 7 * x, -3.5 * x);
	glTexCoord2f(0.75, 1);
	glVertex3f(3 * x, 7 * x, -x);
	glTexCoord2f(1, 0);
	glVertex3f(3 * x, 4 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(3 * x, 4 * x, -3.5 * x);
	glEnd();

	//Armor_middle_front
	glBegin(GL_QUADS);
	glTexCoord2f(1, 0);
	glVertex3f(-3 * x, 7 * x, -x);
	glTexCoord2f(1, 1);
	glVertex3f(3 * x, 7 * x, -x);
	glTexCoord2f(0, 1);
	glVertex3f(3 * x, 4 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-3 * x, 4 * x, 0.5 * x);
	glEnd();

	glBegin(GL_QUADS);
	//Armor_bottom_front_right
	glTexCoord2f(0, 1);
	glVertex3f(0.5 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(3 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2.5 * x, 1.5 * x, 0);
	glTexCoord2f(0, 0);
	glVertex3f(1.7 * x, 1.5 * x, 0);

	//Armor_bottom_front_right_bottom
	glTexCoord2f(0, 1);
	glVertex3f(0.5 * x, 4 * x, -3.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(0.5 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(1.7 * x, 1.5 * x, 0);
	glTexCoord2f(0, 0);
	glVertex3f(1.7 * x, 1.5 * x, -3.5 * x);

	//Armor_bottom_front_left
	glTexCoord2f(0, 1);
	glVertex3f(-3 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-0.5 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-1.7 * x, 1.5 * x, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-2.5 * x, 1.5 * x, 0);

	//Armor_bottom_front_left_bottom
	glTexCoord2f(0, 1);
	glVertex3f(-0.5 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-0.5 * x, 4 * x, -3.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-1.7 * x, 1.5 * x, -3.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-1.7 * x, 1.5 * x, 0);

	//Armor_bottom_left
	glTexCoord2f(1, 0);
	glVertex3f(-3 * x, 4 * x, -3.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-3 * x, 4 * x, 0.5 * x);
	glTexCoord2f(0, 1);
	glVertex3f(-2.5 * x, 1.5 * x, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-2.5 * x, 1.5 * x, -3.5 * x);

	//Armor_bottom_left_bottom
	glTexCoord2f(1, 0);
	glVertex3f(-2.5 * x, 1.5 * x, 0);
	glTexCoord2f(1, 1);
	glVertex3f(-1.7 * x, 1.5 * x, 0);
	glTexCoord2f(0, 1);
	glVertex3f(-1.7 * x, 1.5 * x, -3.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-2.5 * x, 1.5 * x, -3.5 * x);

	//Armor_bottom_right
	glTexCoord2f(1, 0);
	glVertex3f(3 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(3 * x, 4 * x, -3.5 * x);
	glTexCoord2f(0, 1);
	glVertex3f(2.5 * x, 1.5 * x, -3.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(2.5 * x, 1.5 * x, 0);

	//Armor_bottom_right_bottom
	glTexCoord2f(1, 0);
	glVertex3f(2.5 * x, 1.5 * x, 0);
	glTexCoord2f(1, 1);
	glVertex3f(1.7 * x, 1.5 * x, 0);
	glTexCoord2f(0, 1);
	glVertex3f(1.7 * x, 1.5 * x, -3.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(2.5 * x, 1.5 * x, -3.5 * x);
	glEnd();

	glBegin(GL_QUADS);
	//middle_front_gem_top
	glTexCoord2f(0, 1);
	glVertex3f(-0.5 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(0.5 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(0.5 * x, 4 * x, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-0.5 * x, 4 * x, 0);
	glEnd();
}

void drawWingLeft(double x, Prop3D props) {

	drawSphere(1.2 * x);

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	//back
	glVertex3f(-x, 0, 0);
	glVertex3f(x, 0, 0);
	glVertex3f(x, -9.5 * x, 0);
	glVertex3f(0, -9 * x, 0);

	glColor3f(1, 0, 0);
	//top
	glVertex3f(-x, 0, 0);
	glVertex3f(x, 0, 0);
	glVertex3f(x, 0, -0.5 * x);
	glVertex3f(-0.75 * x, 0, -0.5 * x);

	//left
	glVertex3f(x, 0, 0);
	glVertex3f(x, 0, -0.5 * x);
	glVertex3f(x, -9.25 * x, -0.5 * x);
	glVertex3f(x, -9.5 * x, 0);

	//right
	glVertex3f(-x, 0, 0);
	glVertex3f(-0.75 * x, 0, -0.5 * x);
	glVertex3f(0.25 * x, -8.75 * x, -0.5 * x);
	glVertex3f(0, -9 * x, 0);

	//bottom
	glVertex3f(x, -9.5 * x, 0);
	glVertex3f(x, -9.25 * x, -0.5 * x);
	glVertex3f(0.25 * x, -8.75 * x, -0.5 * x);
	glVertex3f(0, -9 * x, 0);

	//front
	glColor3f(0, 0, 0);
	glVertex3f(-0.75 * x, 0, -0.5 * x);
	glVertex3f(x, 0, -0.5 * x);
	glVertex3f(x, -9.25 * x, -0.5 * x);
	glVertex3f(0.25 * x, -8.75 * x, -0.5 * x);
	glEnd();
}

void drawWingRight(double x, Prop3D props) {

	drawSphere(1.2 * x);

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	//back
	glVertex3f(x, 0, 0);
	glVertex3f(-x, 0, 0);
	glVertex3f(-x, -9.5 * x, 0);
	glVertex3f(0, -9 * x, 0);

	glColor3f(1, 0, 0);
	//top
	glVertex3f(x, 0, 0);
	glVertex3f(-x, 0, 0);
	glVertex3f(-x, 0, -0.5 * x);
	glVertex3f(0.75 * x, 0, -0.5 * x);

	//left
	glVertex3f(-x, 0, 0);
	glVertex3f(-x, 0, -0.5 * x);
	glVertex3f(-x, -9.25 * x, -0.5 * x);
	glVertex3f(-x, -9.5 * x, 0);

	//right
	glVertex3f(x, 0, 0);
	glVertex3f(0.75 * x, 0, -0.5 * x);
	glVertex3f(-0.25 * x, -8.75 * x, -0.5 * x);
	glVertex3f(0, -9 * x, 0);

	//bottom
	glVertex3f(-x, -9.5 * x, 0);
	glVertex3f(-x, -9.25 * x, -0.5 * x);
	glVertex3f(-0.25 * x, -8.75 * x, -0.5 * x);
	glVertex3f(0, -9 * x, 0);

	//front
	glColor3f(0, 0, 0);
	glVertex3f(0.75 * x, 0, -0.5 * x);
	glVertex3f(-x, 0, -0.5 * x);
	glVertex3f(-x, -9.25 * x, -0.5 * x);
	glVertex3f(-0.25 * x, -8.75 * x, -0.5 * x);
	glEnd();
}

void drawSphere(double r) {
	useTexture("shiny");

	GLUquadricObj* sphere1 = NULL;
	sphere1 = gluNewQuadric();
	gluQuadricTexture(sphere1, true);
	gluSphere(sphere1, r, 50, 50);
	gluDeleteQuadric(sphere1);
}