#include <iostream>
#include "Engine.h"
#include "Rectangle.h"
#include "KeyPressListener.h"

Engine* EngineInstance;

int main(int argc, char** argv) {
	// There can be only 1 instance of Engine because of opengl
	// This instance can be accessed using EngineInstance static variable by including Engine.h
	EngineInstance = new Engine("Window Title here", 800, 800, 60);

	EngineInstance->registerKeyboardListener(KeyPressListener::listen);

	Rectangle r({ 0,0,0 }, { 60,{0,0,1} }, { 1,0,0 }, 1, 1);
	EngineInstance->Add(r);

	EngineInstance->Start(argc, argv);
	return 0;
}