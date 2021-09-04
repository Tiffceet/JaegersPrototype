#include "texture.h"
#include <GL/freeglut.h>
#include <vector>

std::vector<GLuint> textures;

void LoadAllTexture()
{
    loadTexture((LPCSTR) "texture/Brick.bmp");
    loadTexture((LPCSTR) "texture/Shiny.bmp");
    loadTexture((LPCSTR) "texture/Box.bmp");
}

// "resources/Brick.bmp"
void loadTexture(LPCSTR filename)
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
    textures.push_back(tex);
}

void useTexture(int idx) {
    glBindTexture(GL_TEXTURE_2D, textures.at(idx));
}