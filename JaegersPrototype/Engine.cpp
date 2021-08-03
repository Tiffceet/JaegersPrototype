#include "Engine.h"

#include <iostream>
#include <GL/glut.h>
#include <list>
#include "Object3D.h"

int Engine::FRAME_RATE;
std::list<Object3D> object_list;

Engine::Engine(std::string window_title, int win_width, int win_height, int FRAME_RATE) {
	this->window_title = window_title;
	this->win_width = win_width;
	this->win_height = win_height;
	Engine::FRAME_RATE = FRAME_RATE;
}

void Engine::Start(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(this->win_width, this->win_height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(this->window_title.c_str());
	glutDisplayFunc(Display);
	glutTimerFunc(0, Timer, 0);
	glutMainLoop();
}

void Engine::Add(Object3D obj) {
	
}

void Engine::Display(void) {
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/*glBegin(GL_LINE_LOOP);
	glVertex2f(0, 0);
	glVertex2f(0, 1);
	glEnd();*/

	glFlush();
}

void Engine::Timer(int) {
	glutTimerFunc(1000 / Engine::FRAME_RATE, Timer, 0);
	glutPostRedisplay();
}
