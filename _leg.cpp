#include <gl/freeglut.h>
#include "_leg.h"
#include "typedefs.h"
#include "primitives.h"
#include "texture.h"
void drawRobotLeg(Prop3D props)
{
    glPushMatrix();
    applyProps(props);

    Prop3D foot_props;
    drawFoot(foot_props);

    glPopMatrix();
}

void drawFoot(Prop3D props)
{
    glPushMatrix();
    applyProps(props);

    Prop3D base;
    useTexture("box");
    drawTrapezoid(base);
    glPopMatrix();
}

void drawTrapezoid(Prop3D props)
{
    glPushMatrix();
    applyProps(props);

    Vec3f ftl = {0, 0.5, 0.5};
    Vec3f ftr = {1, 0.5, 0.5};
    Vec3f fbl = {-1, -0.5, 0.5};
    Vec3f fbr = {1, -0.5, 0.5};
    Vec3f btl = {0, 0.5, -0.5};
    Vec3f btr = {1, 0.5, -0.5};
    Vec3f bbl = {-1, -0.5, -0.5};
    Vec3f bbr = {1, -0.5, -0.5};

    // Front
    glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    glTexCoord2f(0.5, 1);
    glVertex3f(ftl.x, ftl.y, ftl.z);
    glTexCoord2f(1, 1);
    glVertex3f(ftr.x, ftr.y, ftr.z);
    glTexCoord2f(1, 0);
    glVertex3f(fbr.x, fbr.y, fbr.z);
    glTexCoord2f(0, 0);
    glVertex3f(fbl.x, fbl.y, fbl.z);
    glEnd();

    // Back
    glBegin(GL_QUADS);
    glNormal3f(0, 0, -1);
    glTexCoord2f(0.5, 1);
    glVertex3f(btl.x, btl.y, btl.z);
    glTexCoord2f(1, 1);
    glVertex3f(btr.x, btr.y, btr.z);
    glTexCoord2f(1, 0);
    glVertex3f(bbr.x, bbr.y, bbr.z);
    glTexCoord2f(0, 0);
    glVertex3f(bbl.x, bbl.y, bbl.z);
    glEnd();

    // Right
    glBegin(GL_QUADS);
    glNormal3f(1, 0, 0);
    glTexCoord2d(0, 1);
    glVertex3f(ftr.x, ftr.y, ftr.z);
    glTexCoord2d(1, 1);
    glVertex3f(btr.x, btr.y, btr.z);
    glTexCoord2d(1, 0);
    glVertex3f(bbr.x, bbr.y, bbr.z);
    glTexCoord2d(0, 0);
    glVertex3f(fbr.x, fbr.y, fbr.z);
    glEnd();

    // Down
    glBegin(GL_QUADS);
    glNormal3f(0, -1, 0);
    glTexCoord2d(1, 0);
    glVertex3f(fbl.x, fbl.y, fbl.z);
    glTexCoord2d(0, 0);
    glVertex3f(fbr.x, fbr.y, fbr.z);
    glTexCoord2d(0, 1);
    glVertex3f(bbr.x, bbr.y, bbr.z);
    glTexCoord2d(1, 1);
    glVertex3f(bbl.x, bbl.y, bbl.z);
    glEnd();

    // Left
    glBegin(GL_QUADS);
    glNormal3f(-1, 1, 0);
    glTexCoord2d(1, 1);
    glVertex3f(ftl.x, ftl.y, ftl.z);
    glTexCoord2d(1, 0);
    glVertex3f(fbl.x, fbl.y, fbl.z);
    glTexCoord2d(0, 0);
    glVertex3f(bbl.x, bbl.y, bbl.z);
    glTexCoord2d(0, 1);
    glVertex3f(btl.x, btl.y, btl.z);
    glEnd();

    // Top
    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glTexCoord2d(0, 0);
    glVertex3f(ftl.x, ftl.y, ftl.z);
    glTexCoord2d(1, 0);
    glVertex3f(ftr.x, ftr.y, ftr.z);
    glTexCoord2d(1, 1);
    glVertex3f(btr.x, btr.y, btr.z);
    glTexCoord2d(0, 1);
    glVertex3f(btl.x, btl.y, btl.z);
    glEnd();

    glPopMatrix();
}