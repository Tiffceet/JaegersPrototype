#include "KeyPressListener.h"
#include <iostream>
#include "Engine.h"

void KeyPressListener::listen(unsigned char key, int x, int y) {
	std::cout << "I heard something";
	Object3D* o = EngineInstance->GetObject("rect");
	Object3D* o2 = EngineInstance->GetObject("rect2");
	Object3D* o3 = EngineInstance->GetObject("rect3");
	o->setRotation({ o->getRotation().angle + 2, {0,0,1} });
	o2->setRotation({ o2->getRotation().angle - 2, {0,0,1} });
	o3->setRotation({ o3->getRotation().angle - 2, {0,0,1} });
}