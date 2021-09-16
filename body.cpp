#include "body.h"
#include <GL/freeglut.h>
#include "typedefs.h"
#include "primitives.h"
#include "texture.h"

int wing_left_rot = 0, wing_right_rot = 0;

void drawRobotBody(double x, Prop3D props, int animation_wing) {
	drawAbdomen(x, props);
	drawGem(x, props);
	drawArmor(x, props);

	glPushMatrix();
	Prop3D props_wing_right;
	props_wing_right.pos.x = 1.25 * x;
	props_wing_right.pos.z = (-3.6 * x);
	props_wing_right.pos.y = (5 * x);
	if (animation_wing == 1) {
		if (wing_right_rot < 75) {
			props_wing_right.rot.z = wing_right_rot++;
			drawWingRight(x, props_wing_right);
		}
		else {
			props_wing_right.rot.z = 75;
			drawWingRight(x, props_wing_right);
		}
	}
	else {
		if (wing_right_rot > 0) {
			props_wing_right.rot.z = wing_right_rot--;
			drawWingRight(x, props_wing_right);
		}
		else {
			drawWingRight(x, props_wing_right);
		}
	}
	glPopMatrix();

	glPushMatrix();
	Prop3D props_wing_left;
	props_wing_left.pos.x = -1.25 * x;
	props_wing_left.pos.z = (-3.6 * x);
	props_wing_left.pos.y = (5 * x);
	if (animation_wing == 1) {
		if (wing_left_rot > -75) {
			props_wing_left.rot.z = wing_left_rot--;
			drawWingLeft(x, props_wing_left);
		}
		else {
			props_wing_left.rot.z = -75;
			drawWingLeft(x, props_wing_left);
		}
	}
	else {
		if (wing_left_rot < 0) {
			props_wing_left.rot.z = wing_left_rot++;
			drawWingLeft(x, props_wing_left);
		}
		else {
			drawWingLeft(x, props_wing_left);
		}
	}
	glPopMatrix();
}

void drawAbdomen(double x, Prop3D props) {
	useTexture("shiny");

	glBegin(GL_POLYGON); 
	Vec3lf ab1 = calculate_normallf({ -2 * x, 5 * x, -3 * x }, { 2 * x, 5 * x, -3 * x }, { 2 * x, 5 * x, -x });
	glNormal3f(ab1.x, ab1.y, ab1.z);
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

	//back//
	glBegin(GL_QUADS);
	Vec3lf ab2 = calculate_normallf({ -2 * x, 5 * x, -3 * x }, { 2 * x, 5 * x, -3 * x }, { 2 * x, 0, -3 * x });
	glNormal3f(ab2.x, ab2.y, ab2.z);
	glTexCoord2f(0, 1);
	glVertex3f(-2 * x, 5 * x, -3 * x);
	glTexCoord2f(1, 1);
	glVertex3f(2 * x, 5 * x, -3 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2 * x, 0, -3 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, 0, -3 * x);
	glEnd();

	//front//
	glBegin(GL_QUADS);
	Vec3lf ab3 = calculate_normallf({ -x, 5 * x, 0 }, { x, 5 * x, 0 }, { x, 0, 0 });
	glNormal3f(-ab3.x, -ab3.y, -ab3.z);
	glTexCoord2f(0, 1);
	glVertex3f(-x, 5 * x, 0);
	glTexCoord2f(1, 1);
	glVertex3f(x, 5 * x, 0);
	glTexCoord2f(1, 0);
	glVertex3f(x, 0, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-x, 0, 0);
	glEnd();

	//left//
	glBegin(GL_QUADS);
	Vec3lf ab4 = calculate_normallf({ -2 * x, 5 * x, -3 * x }, { -2 * x, 5 * x, -x }, { -2 * x, 0, -x });
	glNormal3f(-ab4.x, -ab4.y, -ab4.z);
	glTexCoord2f(0, 1);
	glVertex3f(-2 * x, 5 * x, -3 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-2 * x, 5 * x, -x);
	glTexCoord2f(1, 0);
	glVertex3f(-2 * x, 0, -x);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, 0, -3 * x);
	glEnd();

	//right//
	glBegin(GL_QUADS);
	Vec3lf ab5 = calculate_normallf({ 2 * x, 5 * x, -3 * x }, { 2 * x, 5 * x, -x }, { 2 * x, 0, -x });
	glNormal3f(ab5.x, ab5.y, ab5.z);
	glTexCoord2f(0, 1);
	glVertex3f(2 * x, 5 * x, -3 * x);
	glTexCoord2f(1, 1);
	glVertex3f(2 * x, 5 * x, -x);
	glTexCoord2f(1, 0);
	glVertex3f(2 * x, 0, -x);
	glTexCoord2f(0, 0);
	glVertex3f(2 * x, 0, -3 * x);
	glEnd();

	//left_side//
	glBegin(GL_QUADS);
	Vec3lf ab6 = calculate_normallf({ -2 * x, 5 * x, -x }, { -x, 5 * x, 0 }, { -x, 0, 0 });
	glNormal3f(-ab6.x, -ab6.y, -ab6.z);
	glTexCoord2f(0, 1);
	glVertex3f(-2 * x, 5 * x, -x);
	glTexCoord2f(1, 1);
	glVertex3f(-x, 5 * x, 0);
	glTexCoord2f(1, 0);
	glVertex3f(-x, 0, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, 0, -x);
	glEnd();

	//right_side//
	glBegin(GL_QUADS);
	Vec3lf ab7 = calculate_normallf({ 2 * x, 5 * x, -x }, { x, 5 * x, 0 }, { x, 0, 0 });
	glNormal3f(ab7.x, ab7.y, ab7.z);
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
	Vec3lf ab8 = calculate_normallf({ -2 * x, 0, -3 * x }, { 2 * x, 0, -3 * x }, { 2 * x, 0, -x });
	glNormal3f(ab8.x, ab8.y, ab8.z);
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
	useTexture("gem");

	//back//
	glBegin(GL_POLYGON);
	Vec3lf gm1 = calculate_normallf({ -0.5 * x, 4 * x, 0 }, { 0.5 * x, 4 * x, 0 }, { x, 3 * x, 0 });
	glNormal3f(-gm1.x, -gm1.y,- gm1.z);
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
	Vec3lf gm2 = calculate_normallf({ -0.3 * x, 3.8 * x, 0.5 * x }, { 0.3 * x, 3.8 * x, 0.5 * x }, { 0.8 * x, 3 * x, 0.5 * x });
	glNormal3f(-gm2.x, -gm2.y, -gm2.z);
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
	Vec3lf gm3 = calculate_normallf({ -0.5 * x, 4 * x, 0 }, { 0.5 * x, 4 * x, 0 }, { 0.3 * x, 3.8 * x, 0.5 * x });
	glNormal3f(-gm3.x, -gm3.y, -gm3.z);
	glTexCoord2f(0, 1);
	glVertex3f(-0.5 * x, 4 * x, 0);
	glTexCoord2f(1, 1);
	glVertex3f(0.5 * x, 4 * x, 0);
	glTexCoord2f(1, 0);
	glVertex3f(0.3 * x, 3.8 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-0.3 * x, 3.8 * x, 0.5 * x);
	glEnd();

	//bottom//
	glBegin(GL_QUADS);
	Vec3lf gm4 = calculate_normallf({ -0.5 * x, 2 * x, 0 }, { 0.5 * x, 2 * x, 0 }, { 0.3 * x, 2.2 * x, 0.5 * x });
	glNormal3f(gm4.x, gm4.y, gm4.z);
	glTexCoord2f(0, 1);
	glVertex3f(-0.5 * x, 2 * x, 0);
	glTexCoord2f(1, 1);
	glVertex3f(0.5 * x, 2 * x, 0);
	glTexCoord2f(1, 0);
	glVertex3f(0.3 * x, 2.2 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-0.3 * x, 2.2 * x, 0.5 * x);
	glEnd();

	//top_left
	glBegin(GL_QUADS);
	Vec3lf gm5 = calculate_normallf({ -0.5 * x, 4 * x, 0 }, { -0.3 * x, 3.8 * x, 0.5 * x }, { -0.8 * x, 3 * x, 0.5 * x });
	glNormal3f(-gm5.x, -gm5.y, -gm5.z);
	glTexCoord2f(0, 1);
	glVertex3f(-0.5 * x, 4 * x, 0);
	glTexCoord2f(1, 1);
	glVertex3f(-0.3 * x, 3.8 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-0.8 * x, 3 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-x, 3 * x, 0);
	glEnd();

	//bottom_left
	glBegin(GL_QUADS);
	Vec3lf gm6 = calculate_normallf({ -x, 3 * x, 0 }, { -0.8 * x, 3 * x, 0.5 * x }, { -0.3 * x, 2.2 * x, 0.5 * x });
	glNormal3f(-gm6.x, -gm6.y, -gm6.z);
	glTexCoord2f(0, 1);
	glVertex3f(-x, 3 * x, 0);
	glTexCoord2f(1, 1);
	glVertex3f(-0.8 * x, 3 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-0.3 * x, 2.2 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-0.5 * x, 2 * x, 0);
	glEnd();

	//top_right
	glBegin(GL_QUADS);
	Vec3lf gm7 = calculate_normallf({ 0.3 * x, 3.8 * x, 0.5 * x }, { 0.5 * x, 4 * x, 0 }, { x, 3 * x, 0 });
	glNormal3f(-gm7.x, -gm7.y, -gm7.z);
	glTexCoord2f(0, 1);
	glVertex3f(0.3 * x, 3.8 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(0.5 * x, 4 * x, 0);
	glTexCoord2f(1, 0);
	glVertex3f(x, 3 * x, 0);
	glTexCoord2f(0, 0);
	glVertex3f(0.8 * x, 3 * x, 0.5 * x);
	glEnd();

	//bottom_right
	glBegin(GL_QUADS);
	Vec3lf gm8 = calculate_normallf({ 0.8 * x, 3 * x, 0.5 * x }, { x, 3 * x, 0 }, { 0.5 * x, 2 * x, 0 });
	glNormal3f(-gm8.x, -gm8.y, -gm8.z);
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

void drawArmor(double x, Prop3D props) {
	useTexture("armor");

	//Armor_top_top
	glBegin(GL_QUADS);
	Vec3lf am1 = calculate_normallf({ -x, 7.5 * x, -3.5 * x }, { x, 7.5 * x, -3.5 * x }, { x, 7.5 * x, -1.5 * x });
	glNormal3f(-am1.x, -am1.y, -am1.z);
	glTexCoord2f(0, 1);
	glVertex3f(-x, 7.5 * x, -3.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(x, 7.5 * x, -3.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(x, 7.5 * x, -1.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-x, 7.5 * x, -1.5 * x);
	glEnd();

	//Armor_top_front
	glBegin(GL_QUADS);
	Vec3lf am2 = calculate_normallf({ -x, 7.5 * x, -1.5 * x }, { x, 7.5 * x, -1.5 * x }, { 3 * x, 7 * x, -x });
	glNormal3f(-am2.x, -am2.y, -am2.z);
	glTexCoord2f(0, 1);
	glVertex3f(-x, 7.5 * x, -1.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(x, 7.5 * x, -1.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(3 * x, 7 * x, -x);
	glTexCoord2f(0, 0);
	glVertex3f(-3 * x, 7 * x, -x);
	glEnd();

	//Armor_top_back
	glBegin(GL_QUADS);
	Vec3lf am3 = calculate_normallf({ -x, 7.5 * x, -3.5 * x }, { x, 7.5 * x, -3.5 * x }, { 3 * x, 7 * x, -3.5 * x });
	glNormal3f(am3.x, am3.y, am3.z);
	glTexCoord2f(0, 1);
	glVertex3f(-x, 7.5 * x, -3.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(x, 7.5 * x, -3.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(3 * x, 7 * x, -3.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-3 * x, 7 * x, -3.5 * x);
	glEnd();

	//Armor_top_left
	glBegin(GL_QUADS);
	Vec3lf am4 = calculate_normallf({ -x, 7.5 * x, -3.5 * x }, { -x, 7.5 * x, -1.5 * x }, { -3 * x, 7 * x, -x });
	glNormal3f(-am4.x, -am4.y, -am4.z);
	glTexCoord2f(0, 1);
	glVertex3f(-x, 7.5 * x, -3.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-x, 7.5 * x, -1.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-3 * x, 7 * x, -x);
	glTexCoord2f(0, 0);
	glVertex3f(-3 * x, 7 * x, -3.5 * x);
	glEnd();

	//Armor_top_right
	glBegin(GL_QUADS);
	Vec3lf am5 = calculate_normallf({ x, 7.5 * x, -3.5 * x }, { x, 7.5 * x, -1.5 * x }, { 3 * x, 7 * x, -x });
	glNormal3f(am5.x, am5.y, am5.z);
	glTexCoord2f(0, 1);
	glVertex3f(x, 7.5 * x, -3.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(x, 7.5 * x, -1.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(3 * x, 7 * x, -x);
	glTexCoord2f(0, 0);
	glVertex3f(3 * x, 7 * x, -3.5 * x);
	glEnd();

	//Armor_middle_back
	glBegin(GL_QUADS);
	Vec3lf am6 = calculate_normallf({ -3 * x, 7 * x, -3.5 * x }, { 3 * x, 7 * x, -3.5 * x }, { 3 * x, 4 * x, -3.5 * x });
	glNormal3f(am6.x, am6.y, am6.z);
	glTexCoord2f(0, 1);
	glVertex3f(-3 * x, 7 * x, -3.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(3 * x, 7 * x, -3.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(3 * x, 4 * x, -3.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-3 * x, 4 * x, -3.5 * x);
	glEnd();

	//Armor_bottom_back
	glBegin(GL_QUADS);
	Vec3lf am7 = calculate_normallf({ 3 * x, 4 * x, -3.5 * x }, { -3 * x, 4 * x, -3.5 * x }, { -2.5 * x, 1.5 * x, -3.5 * x });
	glNormal3f(-am7.x, -am7.y, -am7.z);
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
	Vec3lf am8 = calculate_normallf({ -3 * x, 7 * x, -3.5 * x }, { -3 * x, 7 * x, -x }, { -3 * x, 4 * x, 0.5 * x });
	glNormal3f(-am8.x, -am8.y, -am8.z);
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
	Vec3lf am9 = calculate_normallf({ 3 * x, 7 * x, -3.5 * x }, { 3 * x, 7 * x, -x }, { 3 * x, 4 * x, 0.5 * x });
	glNormal3f(am9.x, am9.y, am9.z);
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
	Vec3lf am10 = calculate_normallf({ -3 * x, 7 * x, -x }, { 3 * x, 7 * x, -x }, { 3 * x, 4 * x, 0.5 * x });
	glNormal3f(-am10.x, -am10.y, -am10.z);
	glTexCoord2f(1, 0);
	glVertex3f(-3 * x, 7 * x, -x);
	glTexCoord2f(1, 1);
	glVertex3f(3 * x, 7 * x, -x);
	glTexCoord2f(0, 1);
	glVertex3f(3 * x, 4 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-3 * x, 4 * x, 0.5 * x);
	glEnd();

	//Armor_bottom_front_right
	glBegin(GL_QUADS);
	Vec3lf am11 = calculate_normallf({ 0.5 * x, 4 * x, 0.5 * x }, { 3 * x, 4 * x, 0.5 * x }, { 2.5 * x, 1.5 * x, 0 });
	glNormal3f(-am11.x, -am11.y, -am11.z);
	glTexCoord2f(0, 1);
	glVertex3f(0.5 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(3 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2.5 * x, 1.5 * x, 0);
	glTexCoord2f(0, 0);
	glVertex3f(1.7 * x, 1.5 * x, 0);
	glEnd();

	//Armor_bottom_front_right_bottom
	glBegin(GL_QUADS);
	Vec3lf am12 = calculate_normallf({ 0.5 * x, 4 * x, -3.5 * x }, { 0.5 * x, 4 * x, 0.5 * x }, { 1.7 * x, 1.5 * x, 0 });
	glNormal3f(-am12.x, -am12.y, -am12.z);
	glTexCoord2f(0, 1);
	glVertex3f(0.5 * x, 4 * x, -3.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(0.5 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(1.7 * x, 1.5 * x, 0);
	glTexCoord2f(0, 0);
	glVertex3f(1.7 * x, 1.5 * x, -3.5 * x);
	glEnd();

	//Armor_bottom_front_left
	glBegin(GL_QUADS);
	Vec3lf am13 = calculate_normallf({ -3 * x, 4 * x, 0.5 * x }, { -0.5 * x, 4 * x, 0.5 * x }, { -1.7 * x, 1.5 * x, 0 });
	glNormal3f(-am13.x, -am13.y, -am13.z);
	glTexCoord2f(0, 1);
	glVertex3f(-3 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-0.5 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-1.7 * x, 1.5 * x, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-2.5 * x, 1.5 * x, 0);
	glEnd();

	//Armor_bottom_front_left_bottom
	glBegin(GL_QUADS);
	Vec3lf am14 = calculate_normallf({ -0.5 * x, 4 * x, 0.5 * x }, { -0.5 * x, 4 * x, -3.5 * x }, { -1.7 * x, 1.5 * x, -3.5 * x });
	glNormal3f(am14.x, am14.y, am14.z);
	glTexCoord2f(0, 1);
	glVertex3f(-0.5 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-0.5 * x, 4 * x, -3.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-1.7 * x, 1.5 * x, -3.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-1.7 * x, 1.5 * x, 0);
	glEnd();

	//Armor_bottom_left
	glBegin(GL_QUADS);
	Vec3lf am15 = calculate_normallf({ -3 * x, 4 * x, -3.5 * x }, { -3 * x, 4 * x, 0.5 * x }, { -2.5 * x, 1.5 * x, 0 });
	glNormal3f(-am15.x, -am15.y, -am15.z);
	glTexCoord2f(1, 0);
	glVertex3f(-3 * x, 4 * x, -3.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-3 * x, 4 * x, 0.5 * x);
	glTexCoord2f(0, 1);
	glVertex3f(-2.5 * x, 1.5 * x, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-2.5 * x, 1.5 * x, -3.5 * x);
	glEnd();

	//Armor_bottom_left_bottom
	glBegin(GL_QUADS);
	Vec3lf am16 = calculate_normallf({ -2.5 * x, 1.5 * x, 0 }, { -1.7 * x, 1.5 * x, 0 }, { -1.7 * x, 1.5 * x, -3.5 * x });
	glNormal3f(-am16.x, -am16.y, -am16.z);
	glTexCoord2f(1, 0);
	glVertex3f(-2.5 * x, 1.5 * x, 0);
	glTexCoord2f(1, 1);
	glVertex3f(-1.7 * x, 1.5 * x, 0);
	glTexCoord2f(0, 1);
	glVertex3f(-1.7 * x, 1.5 * x, -3.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-2.5 * x, 1.5 * x, -3.5 * x);
	glEnd();

	//Armor_bottom_right
	glBegin(GL_QUADS);
	Vec3lf am17 = calculate_normallf({ 3 * x, 4 * x, 0.5 * x }, { 3 * x, 4 * x, -3.5 * x }, { 2.5 * x, 1.5 * x, -3.5 * x });
	glNormal3f(-am17.x, -am17.y, -am17.z);
	glTexCoord2f(1, 0);
	glVertex3f(3 * x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(3 * x, 4 * x, -3.5 * x);
	glTexCoord2f(0, 1);
	glVertex3f(2.5 * x, 1.5 * x, -3.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(2.5 * x, 1.5 * x, 0);
	glEnd();

	//Armor_bottom_right_bottom
	glBegin(GL_QUADS);
	Vec3lf am18 = calculate_normallf({ 2.5 * x, 1.5 * x, 0 }, { 1.7 * x, 1.5 * x, 0 }, { 1.7 * x, 1.5 * x, -3.5 * x });
	glNormal3f(am18.x, am18.y, am18.z);
	glTexCoord2f(1, 0);
	glVertex3f(2.5 * x, 1.5 * x, 0);
	glTexCoord2f(1, 1);
	glVertex3f(1.7 * x, 1.5 * x, 0);
	glTexCoord2f(0, 1);
	glVertex3f(1.7 * x, 1.5 * x, -3.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(2.5 * x, 1.5 * x, -3.5 * x);
	glEnd();

	//middle_front_gem_top
	glBegin(GL_QUADS);
	Vec3lf am19 = calculate_normallf({ -0.5 * x, 4 * x, 0.5 * x }, { 0.5 * x, 4 * x, 0.5 * x }, { 0.5 * x, 4 * x, 0 });
	glNormal3f(-am19.x, -am19.y, -am19.z);
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
	applyProps(props);

	useTexture("shiny");

	drawSphere(1.2 * x);

	//back
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	Vec3lf wl1 = calculate_normallf({ -x, 0, 0 }, { x, 0, 0 }, { x, -9.5 * x, 0 });
	glNormal3f(-wl1.x, -wl1.y, -wl1.z);
	glVertex3f(-x, 0, 0);
	glVertex3f(x, 0, 0);
	glVertex3f(x, -9.5 * x, 0);
	glVertex3f(0, -9 * x, 0);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	Vec3lf wl2 = calculate_normallf({ -x, 0, 0 }, { x, 0, 0 }, { x, 0, -0.5 * x });
	glNormal3f(wl2.x, wl2.y, wl2.z);
	glVertex3f(-x, 0, 0);
	glVertex3f(x, 0, 0);
	glVertex3f(x, 0, -0.5 * x);
	glVertex3f(-0.75 * x, 0, -0.5 * x);
	glEnd();

	//left
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	Vec3lf wl3 = calculate_normallf({ x, 0, 0 }, { x, 0, -0.5 * x }, { x, -9.25 * x, -0.5 * x });
	glNormal3f(-wl3.x, -wl3.y, -wl3.z);
	glVertex3f(x, 0, 0);
	glVertex3f(x, 0, -0.5 * x);
	glVertex3f(x, -9.25 * x, -0.5 * x);
	glVertex3f(x, -9.5 * x, 0);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	Vec3lf wl4 = calculate_normallf({ -x, 0, 0 }, { -0.75 * x, 0, -0.5 * x }, { 0.25 * x, -8.75 * x, -0.5 * x });
	glNormal3f(wl4.x, wl4.y, wl4.z);
	glVertex3f(-x, 0, 0);
	glVertex3f(-0.75 * x, 0, -0.5 * x);
	glVertex3f(0.25 * x, -8.75 * x, -0.5 * x);
	glVertex3f(0, -9 * x, 0);
	glEnd();

	//bottom
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	Vec3lf wl5 = calculate_normallf({ x, -9.5 * x, 0 }, { x, -9.25 * x, -0.5 * x }, { 0.25 * x, -8.75 * x, -0.5 * x });
	glNormal3f(-wl5.x, -wl5.y, -wl5.z);
	glVertex3f(x, -9.5 * x, 0);
	glVertex3f(x, -9.25 * x, -0.5 * x);
	glVertex3f(0.25 * x, -8.75 * x, -0.5 * x);
	glVertex3f(0, -9 * x, 0);
	glEnd();

	//front
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	Vec3lf wl6 = calculate_normallf({ -0.75 * x, 0, -0.5 * x }, { x, 0, -0.5 * x }, { x, -9.25 * x, -0.5 * x });
	glNormal3f(wl6.x, wl6.y, wl6.z);
	glVertex3f(-0.75 * x, 0, -0.5 * x);
	glVertex3f(x, 0, -0.5 * x);
	glVertex3f(x, -9.25 * x, -0.5 * x);
	glVertex3f(0.25 * x, -8.75 * x, -0.5 * x);
	glEnd();
}

void drawWingRight(double x, Prop3D props) {
	applyProps(props);

	useTexture("shiny");

	drawSphere(1.2 * x);

	//back
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	Vec3lf wr1 = calculate_normallf({ x, 0, 0 }, { -x, 0, 0 }, { -x, -9.5 * x, 0 });
	glNormal3f(wr1.x, wr1.y, wr1.z);
	glVertex3f(x, 0, 0);
	glVertex3f(-x, 0, 0);
	glVertex3f(-x, -9.5 * x, 0);
	glVertex3f(0, -9 * x, 0);
	glEnd();

	//top
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	Vec3lf wr2 = calculate_normallf({ x, 0, 0 }, { -x, 0, 0 }, { -x, 0, -0.5 * x });
	glNormal3f(wr2.x, wr2.y, wr2.z);
	glVertex3f(x, 0, 0);
	glVertex3f(-x, 0, 0);
	glVertex3f(-x, 0, -0.5 * x);
	glVertex3f(0.75 * x, 0, -0.5 * x);
	glEnd();

	//left
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	Vec3lf wr3 = calculate_normallf({ -x, 0, 0 }, { -x, 0, -0.5 * x }, { -x, -9.25 * x, -0.5 * x });
	glNormal3f(wr3.x, wr3.y, wr3.z);
	glVertex3f(-x, 0, 0);
	glVertex3f(-x, 0, -0.5 * x);
	glVertex3f(-x, -9.25 * x, -0.5 * x);
	glVertex3f(-x, -9.5 * x, 0);
	glEnd();

	//right
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	Vec3lf wr4 = calculate_normallf({ x, 0, 0 }, { 0.75 * x, 0, -0.5 * x }, { -0.25 * x, -8.75 * x, -0.5 * x });
	glNormal3f(-wr4.x, -wr4.y, -wr4.z);
	glVertex3f(x, 0, 0);
	glVertex3f(0.75 * x, 0, -0.5 * x);
	glVertex3f(-0.25 * x, -8.75 * x, -0.5 * x);
	glVertex3f(0, -9 * x, 0);
	glEnd();

	//bottom
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	Vec3lf wr5 = calculate_normallf({ -x, -9.5 * x, 0 }, { -x, -9.25 * x, -0.5 * x }, { -0.25 * x, -8.75 * x, -0.5 * x });
	glNormal3f(wr5.x, wr5.y, wr5.z);
	glVertex3f(-x, -9.5 * x, 0);
	glVertex3f(-x, -9.25 * x, -0.5 * x);
	glVertex3f(-0.25 * x, -8.75 * x, -0.5 * x);
	glVertex3f(0, -9 * x, 0);
	glEnd();

	//front
	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	Vec3lf wr6 = calculate_normallf({ 0.75 * x, 0, -0.5 * x }, { -x, 0, -0.5 * x }, { -x, -9.25 * x, -0.5 * x });
	glNormal3f(-wr6.x, -wr6.y, -wr6.z);
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