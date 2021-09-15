#include "head.h"
#include <GL/freeglut.h>
#include "typedefs.h"
#include "primitives.h"
#include "texture.h"

void drawRobotHead(double x, Prop3D props) {
	glPushMatrix();
	/*applyProps(props);*/
	drawRobotMouth(x, props);
	/*drawRobotEye(x, props);

	drawRobotCheek(x, props);
	
	drawRobotForehead(x, props);
	drawRobotLeftEar(x, props); 
	drawRobotRightEar(x, props);*/

	//glPushMatrix();
	//Prop3D props_neek;
	//props_neek.rot.x = 90;
	////props_neek.pos.y = -2;
	//applyProps(props_neek);
	//drawRobotNeck(x, props_neek);
	//glPopMatrix();

	glPopMatrix();
}

void drawRobotEye(float x, Prop3D props) {
	useTexture("shiny");
	//eye
	glBegin(GL_QUADS);
	//top

	glTexCoord2f(0, 1);
	glVertex3f(-2 * x, 3 * x, -2 * x);
	glTexCoord2f(1, 1);
	glVertex3f(2 * x, 3 * x, -2 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2 * x, 3 * x, 2 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, 3 * x, 2 * x);
	glEnd();

	glBegin(GL_QUADS);
	//bottom
	glTexCoord2f(0, 1);
	glVertex3f(-2 * x, x, -2 * x);
	glTexCoord2f(1, 1);
	glVertex3f(2 * x, x, -2 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2 * x, x, 2 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, x, 2 * x);
	glEnd();

	glBegin(GL_QUADS);
	//front
	
	glTexCoord2f(0, 1);
	glVertex3f(-2 * x, 3 * x, 2 * x);
	glTexCoord2f(1, 1);
	glVertex3f(2 * x, 3 * x, 2 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2 * x, x, 2 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, x, 2 * x);
	glEnd();

	glBegin(GL_QUADS);
	//left
	Vec3f norm = calculate_normal({ -2 * x, 3 * x, -2 * x }, { -2 * x, 3 * x, 2 * x }, { -2 * x, x, 2 * x });
	glNormal3f(-norm.x, -norm.y, -norm.z);
	glTexCoord2f(0, 1);
	glVertex3f(-2 * x, 3 * x, -2 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-2 * x, 3 * x, 2 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-2 * x, x, 2 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, x, -2 * x);
	glEnd();

	glBegin(GL_QUADS);
	//right
	/*Vec3f norm = calculate_normal(f_1, f_2, f_3);
	glNormal3f(norm.x, norm.y, norm.z);*/
	glTexCoord2f(0, 1);
	glVertex3f(2 * x, 3 * x, -2 * x);
	glTexCoord2f(1, 1);
	glVertex3f(2 * x, 3 * x, 2 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2 * x, x, 2 * x);
	glTexCoord2f(0, 0);
	glVertex3f(2 * x, x, -2 * x);
	glEnd();
}

void drawRobotCheek(double x, Prop3D props) {
	useTexture("brick");
	//mouth
	glBegin(GL_QUADS);
	//bottom
	glTexCoord2f(0, 1);
	glVertex3f(-x, -x, -x);
	glTexCoord2f(1, 1);
	glVertex3f(x, -x, -x);
	glTexCoord2f(1, 0);
	glVertex3f(x, -x, x);
	glTexCoord2f(0, 0);
	glVertex3f(-x, -x, x);

	//front
	glTexCoord2f(0, 1);
	glVertex3f(-2 * x, x, 1.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(2 * x, x, 1.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(x, -x, x);
	glTexCoord2f(0, 0);
	glVertex3f(-x, -x, x);

	//back
	glTexCoord2f(0, 1);
	glVertex3f(2 * x, x, -2 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-2 * x, x, -2 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-x, -x, -x);
	glTexCoord2f(0, 0);
	glVertex3f(x, -x, -x);

	//left
	glTexCoord2f(0, 1);
	glVertex3f(-2 * x, x, -2 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-2 * x, x, 1.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-x, -x, x);
	glTexCoord2f(0, 0);
	glVertex3f(-x, -x, -x);

	//right
	glTexCoord2f(0, 1);
	glVertex3f(2 * x, x, -2 * x);
	glTexCoord2f(1, 1);
	glVertex3f(2 * x, x, 1.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(x, -x, x);
	glTexCoord2f(0, 0);
	glVertex3f(x, -x, -x);
	glEnd();

}

void drawRobotMouth(float x, Prop3D props) {
	useTexture("shiny");
	//mouth
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	//front
	glTexCoord2f(0, 1);
	glVertex3f(-0.5 * x, 0.75 * x, 2 * x);
	glTexCoord2f(1, 1);
	glVertex3f(0.5 * x, 0.75 * x, 2 * x);
	glTexCoord2f(1, 0);
	glVertex3f(0.5 * x, -0.75 * x, 2 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-0.5 * x, -0.75 * x, 2 * x);
	
	//top
	glTexCoord2f(0, 1);
	glVertex3f(-x, x, 1.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(x, x, 1.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(0.5 * x, 0.75 * x, 2 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-0.5 * x, 0.75 * x, 2 * x);
	glEnd();

	glBegin(GL_QUADS);
	//bottom
	/*Vec3f norm = calculate_normal({ 0.5 * x, -0.75 * x, 2 * x }, { -0.5 * x, -0.75 * x, 2 * x }, { -x, -x, x });
	glNormal3f(-norm.x, -norm.y, -norm.z);*/
	glTexCoord2f(0, 1);
	glVertex3f(0.5 * x, -0.75 * x, 2 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-0.5 * x, -0.75 * x, 2 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-x, -x, x);
	glTexCoord2f(0, 0);
	glVertex3f(x, -x, x);
	glEnd();

	glBegin(GL_QUADS);
	//left
	glTexCoord2f(0, 1);
	glVertex3f(-x, x, 1.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-0.5 * x, 0.75 * x, 2 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-0.5 * x, -0.75 * x, 2 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-x, -x, x);

	//right
	glTexCoord2f(0, 1);
	glVertex3f(0.5 * x, 0.75 * x, 2 * x);
	glTexCoord2f(1, 1);
	glVertex3f(x, x, 1.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(x, -x, x);
	glTexCoord2f(0, 0);
	glVertex3f(0.5 * x, -0.75 * x, 2 * x);
	glEnd();
}

void drawRobotForehead(double x, Prop3D props) {
	useTexture("brick");
	//forehead
	glBegin(GL_QUADS);
	//top
	glTexCoord2f(0, 1);
	glVertex3f(-x, 4 * x, -1.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(x, 4 * x, -1.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(x, 4 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-x, 4 * x, 0.5 * x);

	//front
	glTexCoord2f(0, 1);
	glVertex3f(-x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2 * x, 3 * x, 1.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, 3 * x, 1.5 * x);

	//back
	glTexCoord2f(0, 1);
	glVertex3f(x, 4 * x, -1.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-x, 4 * x, -1.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-2 * x, 3 * x, -2 * x);
	glTexCoord2f(0, 0);
	glVertex3f(2 * x, 3 * x, -2 * x);

	//left
	glTexCoord2f(0, 1);
	glVertex3f(-x, 4 * x, -1.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-2 * x, 3 * x, 1.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, 3 * x, -2 * x);

	//right
	glTexCoord2f(0, 1);
	glVertex3f(x, 4 * x, -1.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(x, 4 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2 * x, 3 * x, 1.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(2 * x, 3 * x, -2 * x);

	//head_back
	glTexCoord2f(0, 1);
	glVertex3f(-2 * x, 3 * x, -2 * x);
	glTexCoord2f(1, 1);
	glVertex3f(2 * x, 3 * x, -2 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2 * x, x, -2 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, x, -2 * x);
	glEnd();
}

void drawRobotLeftEar(double x, Prop3D props) {
	useTexture("box");
	//left ear
	glBegin(GL_QUADS);
	//front
	glTexCoord2f(0, 1);
	glVertex3f(-2.5 * x, 2.5 * x, -0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-2.5 * x, 2.5 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-2.5 * x, 1.5 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-2.5 * x, 1.5 * x, -0.5 * x);

	//top
	glTexCoord2f(0, 1);
	glVertex3f(-2 * x, 3 * x, -2 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-2 * x, 3 * x, x);
	glTexCoord2f(1, 0);
	glVertex3f(-2.5 * x, 2.5 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-2.5 * x, 2.5 * x, -0.5 * x);

	//bottom
	glTexCoord2f(0, 1);
	glVertex3f(-2.5 * x, 1.5 * x, -0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-2.5 * x, 1.5 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-2 * x, x, x);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, x, -2 * x);

	//left
	glTexCoord2f(0, 1);
	glVertex3f(-2 * x, 3 * x, -2 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-2.5 * x, 2.5 * x, -0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(-2.5 * x, 1.5 * x, -0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(-2 * x, x, -2 * x);

	//left
	glTexCoord2f(0, 1);
	glVertex3f(-2.5 * x, 2.5 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(-2 * x, 3 * x, x);
	glTexCoord2f(1, 0);
	glVertex3f(-2 * x, x, x);
	glTexCoord2f(0, 0);
	glVertex3f(-2.5 * x, 1.5 * x, 0.5 * x);
	glEnd();
}

void drawRobotRightEar(double x, Prop3D props) {
	useTexture("box");
	//right ear
	glBegin(GL_QUADS);
	//front
	glTexCoord2f(0, 1);
	glVertex3f(2.5 * x, 2.5 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(2.5 * x, 2.5 * x, -0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2.5 * x, 1.5 * x, -0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(2.5 * x, 1.5 * x, 0.5 * x);

	//top
	glTexCoord2f(0, 1);
	glVertex3f(2 * x, 3 * x, x);
	glTexCoord2f(1, 1);
	glVertex3f(2 * x, 3 * x, -2 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2.5 * x, 2.5 * x, -0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(2.5 * x, 2.5 * x, 0.5 * x);

	//bottom
	glTexCoord2f(0, 1);
	glVertex3f(2.5 * x, 1.5 * x, 0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(2.5 * x, 1.5 * x, -0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2 * x, x, -2 * x);
	glTexCoord2f(0, 0);
	glVertex3f(2 * x, x, x);

	//left
	glTexCoord2f(0, 1);
	glVertex3f(2.5 * x, 2.5 * x, -0.5 * x);
	glTexCoord2f(1, 1);
	glVertex3f(2 * x, 3 * x, -2 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2 * x, x, -2 * x);
	glTexCoord2f(0, 0);
	glVertex3f(2.5 * x, 1.5 * x, -0.5 * x);

	//left
	glTexCoord2f(0, 1);
	glVertex3f(2 * x, 3 * x, x);
	glTexCoord2f(1, 1);
	glVertex3f(2.5 * x, 2.5 * x, 0.5 * x);
	glTexCoord2f(1, 0);
	glVertex3f(2.5 * x, 1.5 * x, 0.5 * x);
	glTexCoord2f(0, 0);
	glVertex3f(2 * x, x, x);
	glEnd();
}

void drawRobotNeck(double x, Prop3D props) {
	useTexture("box");
	GLUquadricObj* cylinder = NULL;
	cylinder = gluNewQuadric();
	gluQuadricTexture(cylinder, true);
	gluCylinder(cylinder, 0.75 * x, 0.75 * x, 3 * x, 50, 50);
	gluDeleteQuadric(cylinder);
}