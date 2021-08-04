#include <iostream>
#include "Engine.h"
#include "Rectangle.h"
#include "KeyPressListener.h"
#include "Triangle.h"
Engine* EngineInstance;

int main(int argc, char** argv) {
	// There can be only 1 instance of Engine because of opengl
	// This instance can be accessed using EngineInstance static variable by including Engine.h
	Engine e("Window Title here", 800, 800, 60);

	EngineInstance->registerKeyboardListener(KeyPressListener::listen);

	Rectangle r("rect", { 0, 0, 0 }, { 60,{0,0,1} }, { 1,0,0 }, 1, 1);
	Rectangle r2("rectB", { 0, 0, 0 }, { 120,{0,0,1} }, { 0,1,0 }, 1, 1);
	Rectangle r3("rectC", { 0, 0, 0 }, { 190,{0,0,1} }, { 0,0,1 }, 1, 1);
	// Triangle(std::string id, Vector3Df position, Rotation rotation, Color3f color);
	// Triangle t("triangle", { 0,0,0 }, { 0, {0,0,0} }, { 1,0,0 });
	EngineInstance->Add(r);
	EngineInstance->Add(r2);
	EngineInstance->Add(r3);
	// EngineInstance->Add(t);

	EngineInstance->Start(argc, argv);
	return 0;
}