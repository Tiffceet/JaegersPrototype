#pragma once
#include "Engine.h"
class KeyPressListener {
public:
	static void Init(Engine* EngineInstance);
	static void listen(unsigned char key, int x, int y);
};