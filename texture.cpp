#include "texture.h"
#include <GL/freeglut.h>
#include <iostream>
#include <map>

std::map<std::string, GLuint> textures;

void LoadAllTexture()
{
    loadTexture((LPCSTR) "texture/Body.bmp", "body");
    loadTexture((LPCSTR) "texture/sky.bmp", "sky");
    loadTexture((LPCSTR)"texture/Gem.bmp", "gem");
    loadTexture((LPCSTR)"texture/Armor.bmp", "armor");
    loadTexture((LPCSTR)"texture/shiny.bmp", "shiny");
    loadTexture((LPCSTR)"texture/water-badge.bmp", "water-b");
}

// "resources/Brick.bmp"
void loadTexture(LPCSTR filename, std::string label)
{
    GLuint tex;
    BITMAP BMP;
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    HBITMAP hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), filename, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE);
    GetObject(hBMP, sizeof(BMP), &BMP);

    glEnable(GL_TEXTURE_2D);
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
    DeleteObject(hBMP);
    textures[label] = tex;
}

void useTexture(std::string label)
{
    glColor3f(1,1,1);
    glBindTexture(GL_TEXTURE_2D, textures[label]);
}

void useDefaultTexture() {
    glBindTexture(GL_TEXTURE_2D, 0);
}