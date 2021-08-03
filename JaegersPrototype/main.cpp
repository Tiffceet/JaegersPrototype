#include <iostream>
#include "Engine.h"
#include "Rectangle.h"
#include "KeyPressListener.h"
int main(int argc, char** argv) {
	// There can be only 1 instance of Engine because of opengl
	// This instance can be accessed using EngineInstance static variable by including Engine.h
	Engine e("Window Title here", 800, 800, 60);

	e.registerKeyboardListener(KeyPressListener::listen);

	Rectangle r({ 0,0,0 }, { 60,{0,0,1} }, { 1,0,0 }, 1, 1);
	e.Add(r);

	e.Start(argc, argv);
	return 0;
}