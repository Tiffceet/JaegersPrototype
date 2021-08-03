#include <iostream>
#include "Engine.h"
int main(int argc, char** argv) {
	Engine e("Window Title here", 800, 600, 60);
	e.Start(argc, argv);
	return 0;
}