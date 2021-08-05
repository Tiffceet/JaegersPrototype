#include <iostream>
#include "Engine.h"
#include "Rectangle.h"
#include "KeyPressListener.h"
#include "Triangle.h"
#include "Sphere.h"
Engine* EngineInstance;

int main(int argc, char** argv) {
	// There can be only 1 instance of Engine because of opengl
	// This instance can be accessed using EngineInstance static variable by including Engine.h
	Engine e("Window Title here", 800, 800, 60);

	EngineInstance->registerKeyboardListener(KeyPressListener::listen);
	
	Sphere s("s", { 0,0,0 }, { 60,{1,1,1} }, { 1,1,1 }, 0.5f);
	EngineInstance->Add(s);


	EngineInstance->Start(argc, argv);
	return 0;
}