#pragma once

#include <iostream>
#include <GL/glut.h>
#include <list>
#include "Object3D.h"
class Engine {
public:
	Engine(std::string window_title, int win_width, int win_height, int FRAME_RATE);
	void Start(int argc, char** argv);
	void Add(Object3D obj);
private:
	static int FRAME_RATE;

	static void Display(void);
	static void Timer(int);

	std::string window_title;
	int win_width;
	int win_height;

	static std::list<Object3D> object_list;
};