#include "primitives.h"
#include "typedefs.h"
#include <GL/freeglut.h>

void applyProps(Prop3D props)
{
    glScalef(props.scale.x, props.scale.y, props.scale.z);
    glTranslatef(props.pos.x, props.pos.y, props.pos.z);
    glRotatef(props.rot.x, 1, 0, 0);
    glRotatef(props.rot.y, 0, 1, 0);
    glRotatef(props.rot.z, 0, 0, 1);
    glTranslatef(props.origin.x, props.origin.y, props.origin.z);
}

/**
 * Draw a cube on screen
 * @param props
 * @param size [x=length, y=height, z=width]
 **/
void drawCube(Prop3D props, Vec3f size)
{
    glPushMatrix();
    applyProps(props);
    GLfloat ftl[3] = {-size.x / 2, size.y / 2, -size.z / 2};
    GLfloat ftr[3] = {size.x / 2, size.y / 2, -size.z / 2};
    GLfloat fbl[3] = {-size.x / 2, -size.y / 2, -size.z / 2};
    GLfloat fbr[3] = {size.x / 2, -size.y / 2, -size.z / 2};
    GLfloat btl[3] = {-size.x / 2, size.y / 2, size.z / 2};
    GLfloat btr[3] = {size.x / 2, size.y / 2, size.z / 2};
    GLfloat bbl[3] = {-size.x / 2, -size.y / 2, size.z / 2};
    GLfloat bbr[3] = {size.x / 2, -size.y / 2, size.z / 2};
    glBegin(GL_QUADS);
    glVertex3f(ftl[0], ftl[1], ftl[2]);
    glVertex3f(ftr[0], ftr[1], ftr[2]);
    glVertex3f(fbr[0], fbr[1], fbr[2]);
    glVertex3f(fbl[0], fbl[1], fbl[2]);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(ftr[0], ftr[1], ftr[2]);
    glVertex3f(btr[0], btr[1], btr[2]);
    glVertex3f(bbr[0], bbr[1], bbr[2]);
    glVertex3f(fbr[0], fbr[1], fbr[2]);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(fbl[0], fbl[1], fbl[2]);
    glVertex3f(fbr[0], fbr[1], fbr[2]);
    glVertex3f(bbr[0], bbr[1], bbr[2]);
    glVertex3f(bbl[0], bbl[1], bbl[2]);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(fbl[0], fbl[1], fbl[2]);
    glVertex3f(bbl[0], bbl[1], bbl[2]);
    glVertex3f(btl[0], btl[1], btl[2]);
    glVertex3f(ftl[0], ftl[1], ftl[2]);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(btl[0], btl[1], btl[2]);
    glVertex3f(btr[0], btr[1], btr[2]);
    glVertex3f(ftr[0], ftr[1], ftr[2]);
    glVertex3f(ftl[0], ftl[1], ftl[2]);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(btl[0], btl[1], btl[2]);
    glVertex3f(btr[0], btr[1], btr[2]);
    glVertex3f(bbr[0], bbr[1], bbr[2]);
    glVertex3f(bbl[0], bbl[1], bbl[2]);
    glEnd();
    glPopMatrix();
}
