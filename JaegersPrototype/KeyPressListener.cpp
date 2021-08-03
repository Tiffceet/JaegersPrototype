#include "KeyPressListener.h"
#include <iostream>
#include "Engine.h"

void KeyPressListener::listen(unsigned char key, int x, int y) {
	std::cout << "I heard something";
	Object3D* o = EngineInstance->GetObject();
	o->setPosition({0.2, 0,0});
}