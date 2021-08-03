#include <iostream>
#include "Engine.h"
#include "Rectangle.h"
#include "KeyPressListener.h"
int main(int argc, char** argv) {
	Engine e("Window Title here", 800, 800, 60);
	e.registerKeyboardListener(KeyPressListener::listen);

	Rectangle r({ 0,0,0 }, { 60,{0,0,1} }, { 1,0,0 }, 1, 1);
	// Rectangle r;
	e.Add(r);
	e.Start(argc, argv);
	return 0;
}