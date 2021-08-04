#include "KeyPressListener.h"
#include <iostream>
#include "Engine.h"

void KeyPressListener::listen(unsigned char key, int x, int y) {
	std::cout << "I heard something";
	Object3D* o = EngineInstance->GetObject("rect");
	o->setPosition({ o->getPosition().x + 0.1f, 0,0 });
}