#ifndef TEXTURE_H
#define TEXTURE_H
#include <gl/freeglut.h>
#include <iostream>

void LoadAllTexture();
void loadTexture(LPCSTR filename, std::string label);
void useTexture(std::string label);
void useDefaultTexture();

#endif