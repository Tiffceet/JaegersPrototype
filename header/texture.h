#ifndef TEXTURE_H
#define TEXTURE_H
#include <gl/freeglut.h>

void loadTexture(LPCSTR filename);
void LoadAllTexture();
void bindTexture(int idx);

#endif