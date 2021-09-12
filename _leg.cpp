#include <gl/freeglut.h>
#include "_leg.h"
#include "typedefs.h"
#include "primitives.h"
#include "texture.h"
int foot_frame = 0;
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

    Prop3D lower_foot;
    lower_foot.origin = {-1, -6, 0};
    lower_foot.rot.z = -foot_frame++;
    drawLowerFoot(lower_foot);

    Prop3D foot_joint;
    foot_joint.pos = {0, 0, -1};
    useTexture("brick");
    drawCylinder(foot_joint, 0.75, 0.75, 2, 30, 30);

    glPopMatrix();
}

void drawLowerFoot(Prop3D props)
{
    glPushMatrix();
    applyProps(props);

    Prop3D base;
    base.scale = {2, 2, 2};
    useTexture("box");
    drawTrapezoid(base);

    Prop3D lower_foot;
    useTexture("shiny");
    lower_foot.pos = {1, 3.5, 0};
    drawCube(lower_foot, {1.9, 5, 1.9});

    Prop3D blueball_1;
    blueball_1.pos = {0.2, 0, 0.75};
    useTexture("shiny");
    drawSphere(blueball_1, 0.75, 30, 30);

    Prop3D blueball_2;
    blueball_1.pos = {0.2, 0, -0.75};
    useTexture("shiny");
    drawSphere(blueball_1, 0.75, 30, 30);

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