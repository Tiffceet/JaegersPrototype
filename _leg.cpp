#include <gl/freeglut.h>
#define _USE_MATH_DEFINES
#include "_leg.h"
#include "typedefs.h"
#include "primitives.h"
#include "texture.h"
#include "math.h"
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
    Prop3D upper_foot;
    drawUpperFoot(upper_foot);
    glPopMatrix();
}

void drawUpperFoot(Prop3D props)
{
    glPushMatrix();
    applyProps(props);

    Prop3D lower_foot;
    lower_foot.origin = {-1, -6, 0};
    drawLowerFoot(lower_foot);

    Prop3D foot_joint;
    foot_joint.pos = {0, 0, -1};
    useTexture("brick");
    drawCylinder(foot_joint, 0.75, 0.75, 2, 30, 30);

    Prop3D upper_foot;
    useTexture("shiny");
    upper_foot.origin = {0, -2.5, 0};
    upper_foot.pos = {0, 5.5, 0};
    // upper_foot.rot.x = foot_frame++;
    drawCube(upper_foot, {1.9, 5, 1.9});

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

void p(Vec3f v, std::string label)
{
    std::cout << label << ": " << v.x << ", " << v.y << ", " << v.z << std::endl;
}

/**
 *    _
 *  /   \
 * |    |
 * \ _ / 
 **/
void drawOctoid(Prop3D props)
{
    glPushMatrix();
    applyProps(props);
    Vec3f f_1 = {cos(0 * M_PI / 180.0), sin(0 * M_PI / 180.0), 0.1};
    Vec3f f_2 = {cos(45 * M_PI / 180.0), sin(45 * M_PI / 180.0), 0.1};
    Vec3f f_3 = {cos(90 * M_PI / 180.0), sin(90 * M_PI / 180.0), 0.1};
    Vec3f f_4 = {cos(135 * M_PI / 180.0), sin(135 * M_PI / 180.0), 0.1};
    Vec3f f_5 = {cos(180 * M_PI / 180.0), sin(180 * M_PI / 180.0), 0.1};
    Vec3f f_6 = {cos(225 * M_PI / 180.0), sin(225 * M_PI / 180.0), 0.1};
    Vec3f f_7 = {cos(270 * M_PI / 180.0), sin(270 * M_PI / 180.0), 0.1};
    Vec3f f_8 = {cos(315 * M_PI / 180.0), sin(315 * M_PI / 180.0), 0.1};

    Vec3f b_1 = {1.1 * cos(0 * M_PI / 180.0), 1.1 * sin(0 * M_PI / 180.0), -0.1};
    Vec3f b_2 = {1.1 * cos(45 * M_PI / 180.0), 1.1 * sin(45 * M_PI / 180.0), -0.1};
    Vec3f b_3 = {1.1 * cos(90 * M_PI / 180.0), 1.1 * sin(90 * M_PI / 180.0), -0.1};
    Vec3f b_4 = {1.1 * cos(135 * M_PI / 180.0), 1.1 * sin(135 * M_PI / 180.0), -0.1};
    Vec3f b_5 = {1.1 * cos(180 * M_PI / 180.0), 1.1 * sin(180 * M_PI / 180.0), -0.1};
    Vec3f b_6 = {1.1 * cos(225 * M_PI / 180.0), 1.1 * sin(225 * M_PI / 180.0), -0.1};
    Vec3f b_7 = {1.1 * cos(270 * M_PI / 180.0), 1.1 * sin(270 * M_PI / 180.0), -0.1};
    Vec3f b_8 = {1.1 * cos(315 * M_PI / 180.0), 1.1 * sin(315 * M_PI / 180.0), -0.1};

    useDefaultTexture();
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex3f(f_1.x, f_1.y, f_1.z);
    glVertex3f(f_2.x, f_2.y, f_2.z);
    glVertex3f(f_3.x, f_3.y, f_3.z);
    glVertex3f(f_4.x, f_4.y, f_4.z);
    glVertex3f(f_5.x, f_5.y, f_5.z);
    glVertex3f(f_6.x, f_6.y, f_6.z);
    glVertex3f(f_7.x, f_7.y, f_7.z);
    glVertex3f(f_8.x, f_8.y, f_8.z);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(b_1.x, b_1.y, b_1.z);
    glVertex3f(b_2.x, b_2.y, b_2.z);
    glVertex3f(b_3.x, b_3.y, b_3.z);
    glVertex3f(b_4.x, b_4.y, b_4.z);
    glVertex3f(b_5.x, b_5.y, b_5.z);
    glVertex3f(b_6.x, b_6.y, b_6.z);
    glVertex3f(b_7.x, b_7.y, b_7.z);
    glVertex3f(b_8.x, b_8.y, b_8.z);
    glEnd();

    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
    glVertex3f(b_1.x, b_1.y, b_1.z);
    glVertex3f(f_1.x, f_1.y, f_1.z);
    glVertex3f(f_2.x, f_2.y, f_2.z);
    glVertex3f(b_2.x, b_2.y, b_2.z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(b_2.x, b_2.y, b_2.z);
    glVertex3f(f_2.x, f_2.y, f_2.z);
    glVertex3f(f_3.x, f_3.y, f_3.z);
    glVertex3f(b_3.x, b_3.y, b_3.z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(b_3.x, b_3.y, b_3.z);
    glVertex3f(f_3.x, f_3.y, f_3.z);
    glVertex3f(f_4.x, f_4.y, f_4.z);
    glVertex3f(b_4.x, b_4.y, b_4.z);
    glEnd();
    
    glBegin(GL_QUADS);
    glVertex3f(b_4.x, b_4.y, b_4.z);
    glVertex3f(f_4.x, f_4.y, f_4.z);
    glVertex3f(f_5.x, f_5.y, f_5.z);
    glVertex3f(b_5.x, b_5.y, b_5.z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(b_5.x, b_5.y, b_5.z);
    glVertex3f(f_5.x, f_5.y, f_5.z);
    glVertex3f(f_6.x, f_6.y, f_6.z);
    glVertex3f(b_6.x, b_6.y, b_6.z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(b_6.x, b_6.y, b_6.z);
    glVertex3f(f_6.x, f_6.y, f_6.z);
    glVertex3f(f_7.x, f_7.y, f_7.z);
    glVertex3f(b_7.x, b_7.y, b_7.z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(b_7.x, b_7.y, b_7.z);
    glVertex3f(f_7.x, f_7.y, f_7.z);
    glVertex3f(f_8.x, f_8.y, f_8.z);
    glVertex3f(b_8.x, b_8.y, b_8.z);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(b_8.x, b_8.y, b_8.z);
    glVertex3f(f_8.x, f_8.y, f_8.z);
    glVertex3f(f_1.x, f_1.y, f_1.z);
    glVertex3f(b_1.x, b_1.y, b_1.z);
    glEnd();

    glPopMatrix();
}