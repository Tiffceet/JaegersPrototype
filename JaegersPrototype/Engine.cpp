#include "Engine.h"

#include <iostream>
#include <GL/glut.h>
#include <list>

#include "Rectangle.h"
#include "Object3D.h"

Engine::Engine(std::string window_title, int win_width, int win_height, int frame_rate) {
	this->window_title = window_title;
	this->win_width = win_width;
	this->win_height = win_height;
	this->frame_rate = frame_rate;
	EngineInstance = this;
	kbListener = NULL;
}

void Engine::Start(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(this->win_width, this->win_height);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(this->window_title.c_str());
	glutDisplayFunc(DisplayCallback);
	glutTimerFunc(0, TimerCallback, 0);
	glutMainLoop();
}

void Engine::registerKeyboardListener(void (*f)(unsigned char, int, int)) {
	kbListener = f;
}

void Engine::Add(Object3D &obj) {
	this->object_list.push_back(&obj);
}

Object3D* Engine::GetObject() {
	return NULL;
}

void Engine::Display(void) {
	glutKeyboardFunc(kbListener);

	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	for (Object3D* obj : this->object_list) {
		obj->Draw(0);
	}

	glFlush();
}

void Engine::Timer(int) {
	glutTimerFunc(1000 / this->frame_rate, TimerCallback, 0);
	glutPostRedisplay();
}

// ===========================================
// Static functions
// ===========================================
void Engine::DisplayCallback(void) {
	EngineInstance->Display();
}

void Engine::TimerCallback(int time) {
	EngineInstance->Timer(time);
}

// ===========================================
// ===========================================