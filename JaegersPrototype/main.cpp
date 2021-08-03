#include <iostream>
#include "Engine.h"
#include "Rectangle.h"
int main(int argc, char** argv) {
	Engine e("Window Title here", 800, 600, 60);
	// Rectangle r({ 0,0,0 }, { 0,{0,0,0} }, { 1,0,0 });
	Rectangle r;
	e.Add(r);
	e.Start(argc, argv);
	
	return 0;
}