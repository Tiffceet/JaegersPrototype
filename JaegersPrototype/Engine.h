#pragma once

#include <iostream>
#include <GL/glut.h>
#include <vector>
#include "Object3D.h"
class Engine {
public:
	Engine(std::string window_title, int win_width, int win_height, int FRAME_RATE);
	void Start(int argc, char** argv);

	void registerKeyboardListener(void (*)(unsigned char, int , int));
	void Add(Object3D& obj);
	Object3D* GetObject();
private:
	
	void Display(void);
	void Timer(int);

	std::string window_title;
	int win_width;
	int win_height;
	int frame_rate;

	std::vector<Object3D*> object_list;

	static void DisplayCallback(void);
	static void TimerCallback(int);
};
static Engine* EngineInstance;
static void (*kbListener)(unsigned char, int, int);