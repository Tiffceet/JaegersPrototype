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

    Prop3D leg_badge_props;
    leg_badge_props.pos = {0, 6, 1};
    drawLegBadge(leg_badge_props);

    Prop3D leg_shield_1;
    leg_shield_1.pos = {-0.25, 6, 1.25};
    leg_shield_1.rot.y = -60;
    drawLegShield(leg_shield_1);

    Prop3D leg_shield_2;
    leg_shield_2.pos = {0.25, 6, 1.25};
    leg_shield_2.rot.y = 60;
    drawLegShield(leg_shield_2);

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
void drawOctoid(Prop3D props, float thickness)
{
    glPushMatrix();
    applyProps(props);
    Vec3f f_1 = {cos(0 * M_PI / 180.0), sin(0 * M_PI / 180.0), thickness / 2};
    Vec3f f_2 = {cos(45 * M_PI / 180.0), sin(45 * M_PI / 180.0), thickness / 2};
    Vec3f f_3 = {cos(90 * M_PI / 180.0), sin(90 * M_PI / 180.0), thickness / 2};
    Vec3f f_4 = {cos(135 * M_PI / 180.0), sin(135 * M_PI / 180.0), thickness / 2};
    Vec3f f_5 = {cos(180 * M_PI / 180.0), sin(180 * M_PI / 180.0), thickness / 2};
    Vec3f f_6 = {cos(225 * M_PI / 180.0), sin(225 * M_PI / 180.0), thickness / 2};
    Vec3f f_7 = {cos(270 * M_PI / 180.0), sin(270 * M_PI / 180.0), thickness / 2};
    Vec3f f_8 = {cos(315 * M_PI / 180.0), sin(315 * M_PI / 180.0), thickness / 2};

    Vec3f b_1 = {1.1 * cos(0 * M_PI / 180.0), 1.1 * sin(0 * M_PI / 180.0), -thickness / 2};
    Vec3f b_2 = {1.1 * cos(45 * M_PI / 180.0), 1.1 * sin(45 * M_PI / 180.0), -thickness / 2};
    Vec3f b_3 = {1.1 * cos(90 * M_PI / 180.0), 1.1 * sin(90 * M_PI / 180.0), -thickness / 2};
    Vec3f b_4 = {1.1 * cos(135 * M_PI / 180.0), 1.1 * sin(135 * M_PI / 180.0), -thickness / 2};
    Vec3f b_5 = {1.1 * cos(180 * M_PI / 180.0), 1.1 * sin(180 * M_PI / 180.0), -thickness / 2};
    Vec3f b_6 = {1.1 * cos(225 * M_PI / 180.0), 1.1 * sin(225 * M_PI / 180.0), -thickness / 2};
    Vec3f b_7 = {1.1 * cos(270 * M_PI / 180.0), 1.1 * sin(270 * M_PI / 180.0), -thickness / 2};
    Vec3f b_8 = {1.1 * cos(315 * M_PI / 180.0), 1.1 * sin(315 * M_PI / 180.0), -thickness / 2};

    useDefaultTexture();
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    Vec3f norm = calculate_normal(f_1, f_2, f_3);
    glNormal3f(norm.x, norm.y, norm.z);
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
    norm = calculate_normal(b_1, b_2, b_3);
    norm = -norm;
    glNormal3f(norm.x, norm.y, norm.z);
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
    norm = calculate_normal(b_1, f_1, f_2);
    glNormal3f(norm.x, norm.y, norm.z);
    glNormal3f(-norm.x, -norm.y, -norm.z);
    glVertex3f(b_1.x, b_1.y, b_1.z);
    glVertex3f(f_1.x, f_1.y, f_1.z);
    glVertex3f(f_2.x, f_2.y, f_2.z);
    glVertex3f(b_2.x, b_2.y, b_2.z);
    glEnd();

    glBegin(GL_QUADS);
    norm = calculate_normal(b_2, f_2, f_3);
    glNormal3f(norm.x, norm.y, norm.z);
    glNormal3f(-norm.x, -norm.y, -norm.z);
    glVertex3f(b_2.x, b_2.y, b_2.z);
    glVertex3f(f_2.x, f_2.y, f_2.z);
    glVertex3f(f_3.x, f_3.y, f_3.z);
    glVertex3f(b_3.x, b_3.y, b_3.z);
    glEnd();

    glBegin(GL_QUADS);
    norm = calculate_normal(b_3, f_3, f_4);
    glNormal3f(norm.x, norm.y, norm.z);
    glNormal3f(-norm.x, -norm.y, -norm.z);
    glVertex3f(b_3.x, b_3.y, b_3.z);
    glVertex3f(f_3.x, f_3.y, f_3.z);
    glVertex3f(f_4.x, f_4.y, f_4.z);
    glVertex3f(b_4.x, b_4.y, b_4.z);
    glEnd();

    glBegin(GL_QUADS);
    norm = calculate_normal(b_4, f_4, f_5);
    glNormal3f(norm.x, norm.y, norm.z);
    glNormal3f(-norm.x, -norm.y, -norm.z);
    glVertex3f(b_4.x, b_4.y, b_4.z);
    glVertex3f(f_4.x, f_4.y, f_4.z);
    glVertex3f(f_5.x, f_5.y, f_5.z);
    glVertex3f(b_5.x, b_5.y, b_5.z);
    glEnd();

    glBegin(GL_QUADS);
    norm = calculate_normal(b_5, f_5, f_6);
    glNormal3f(norm.x, norm.y, norm.z);
    glNormal3f(-norm.x, -norm.y, -norm.z);
    glVertex3f(b_5.x, b_5.y, b_5.z);
    glVertex3f(f_5.x, f_5.y, f_5.z);
    glVertex3f(f_6.x, f_6.y, f_6.z);
    glVertex3f(b_6.x, b_6.y, b_6.z);
    glEnd();

    glBegin(GL_QUADS);
    norm = calculate_normal(b_6, f_6, f_7);
    glNormal3f(norm.x, norm.y, norm.z);
    glNormal3f(-norm.x, -norm.y, -norm.z);
    glVertex3f(b_6.x, b_6.y, b_6.z);
    glVertex3f(f_6.x, f_6.y, f_6.z);
    glVertex3f(f_7.x, f_7.y, f_7.z);
    glVertex3f(b_7.x, b_7.y, b_7.z);
    glEnd();

    glBegin(GL_QUADS);
    norm = calculate_normal(b_7, f_7, f_8);
    glNormal3f(norm.x, norm.y, norm.z);
    glNormal3f(-norm.x, -norm.y, -norm.z);
    glVertex3f(b_7.x, b_7.y, b_7.z);
    glVertex3f(f_7.x, f_7.y, f_7.z);
    glVertex3f(f_8.x, f_8.y, f_8.z);
    glVertex3f(b_8.x, b_8.y, b_8.z);
    glEnd();

    glBegin(GL_QUADS);
    norm = calculate_normal(b_8, f_8, b_1);
    glNormal3f(norm.x, norm.y, norm.z);
    glNormal3f(-norm.x, -norm.y, -norm.z);
    glVertex3f(b_8.x, b_8.y, b_8.z);
    glVertex3f(f_8.x, f_8.y, f_8.z);
    glVertex3f(f_1.x, f_1.y, f_1.z);
    glVertex3f(b_1.x, b_1.y, b_1.z);
    glEnd();

    glPopMatrix();
}

void drawLegBadge(Prop3D props)
{
    glPushMatrix();
    applyProps(props);
    Prop3D badge_props;
    badge_props.pos = {0, 0, 0.5};
    drawOctoid(badge_props, 0.2);

    Prop3D badge_cont_props;
    badge_cont_props.scale = {1.5, 1.5, 1.5};
    drawOctoid(badge_cont_props, 0.5);
    glPopMatrix();
}

void drawLegShield(Prop3D props)
{
    glPushMatrix();
    applyProps(props);

    Prop3D leg_shield_prop;
    leg_shield_prop.pos = {0, -1, 0.5};
    leg_shield_prop.scale = {2, 3, 2};
    drawLegShieldCont(leg_shield_prop);
    glPopMatrix();
}

void drawLegShieldCont(Prop3D props)
{
    glPushMatrix();
    applyProps(props);
    Prop3D p1;
    p1.pos.x = -0.5;
    p1.rot.y = -20;
    useTexture("box");
    drawLegShieldPiece(p1);
    Prop3D p2;
    p2.pos.x = 0.5;
    p2.rot.y = 200;
    drawLegShieldPiece(p2);
    glPopMatrix();
}

void drawLegShieldPiece(Prop3D props)
{
    glPushMatrix();
    applyProps(props);
    Prop3D vertical_cube;
    drawCube(vertical_cube, {1, 2, 0.2});

    Prop3D slanted_cube;
    slanted_cube.pos = {0.5, -1, 0};
    slanted_cube.origin = {-0.5, -0.5, 0};
    slanted_cube.rot.z = -30;
    drawCube(slanted_cube, {1, 1, 0.19});
    glPopMatrix();
}

void drawPantShield(Prop3D props)
{
    glPushMatrix();
    applyProps(props);
    Prop3D pointed_part_1;
    drawPantShieldPointedPart(pointed_part_1);
    Prop3D pointed_part_2;
    pointed_part_2.pos.x = 2;
    drawPantShieldPointedPart(pointed_part_2);
    glPopMatrix();
}

void drawPantShieldPointedPart(Prop3D props)
{
    glPushMatrix();
    applyProps(props);
    Vec3f ftl = {0, 0, 0.1};
    Vec3f ftr = {1, 0, 0.1};
    Vec3f fbl = {0, -1.5, 0.1};
    Vec3f fbr = {1, -1.5, 0.1};
    Vec3f fbm = {0.5, -2, 0.1};

    Vec3f btl = {0, 0, -0.1};
    Vec3f btr = {1, 0, -0.1};
    Vec3f bbl = {0, -1.5, -0.1};
    Vec3f bbr = {1, -1.5, -0.1};
    Vec3f bbm = {0.5, -2, -0.1};

    // front
    glBegin(GL_POLYGON);
    Vec3f norm = -calculate_normal(ftl, ftr, fbr);
    glNormal3f(norm.x, norm.y, norm.z);
    glVertex3f(ftl.x, ftl.y, ftl.z);
    glVertex3f(ftr.x, ftr.y, ftr.z);
    glVertex3f(fbr.x, fbr.y, fbr.z);
    glVertex3f(fbm.x, fbm.y, fbm.z);
    glVertex3f(fbl.x, fbl.y, fbl.z);
    glEnd();

    //back
    glBegin(GL_POLYGON);
    norm = calculate_normal(btl, btr, bbr);
    glNormal3f(norm.x, norm.y, norm.z);
    glVertex3f(btl.x, btl.y, btl.z);
    glVertex3f(btr.x, btr.y, btr.z);
    glVertex3f(bbr.x, bbr.y, bbr.z);
    glVertex3f(bbm.x, bbm.y, bbm.z);
    glVertex3f(bbl.x, bbl.y, bbl.z);
    glEnd();

    //top
    glBegin(GL_QUADS);
    norm = calculate_normal(ftl, ftr, btr);
    glNormal3f(norm.x, norm.y, norm.z);
    glVertex3f(ftl.x, ftl.y, ftl.z);
    glVertex3f(ftr.x, ftr.y, ftr.z);
    glVertex3f(btr.x, btr.y, btr.z);
    glVertex3f(btl.x, btl.y, btl.z);
    glEnd();

    // left
    glBegin(GL_QUADS);
    norm = calculate_normal(ftl, fbl, bbl);
    glNormal3f(norm.x, norm.y, norm.z);
    glVertex3f(ftl.x, ftl.y, ftl.z);
    glVertex3f(fbl.x, fbl.y, fbl.z);
    glVertex3f(bbl.x, bbl.y, bbl.z);
    glVertex3f(btl.x, btl.y, btl.z);
    glEnd();

    // right
    glBegin(GL_QUADS);
    norm = calculate_normal(ftr, fbr, bbr);
    glNormal3f(norm.x, norm.y, norm.z);
    glVertex3f(ftr.x, ftr.y, ftr.z);
    glVertex3f(fbr.x, fbr.y, fbr.z);
    glVertex3f(bbr.x, bbr.y, bbr.z);
    glVertex3f(btr.x, btr.y, btr.z);
    glEnd();

    // lower left
    glBegin(GL_QUADS);
    norm = calculate_normal(fbl, fbm, bbm);
    glNormal3f(norm.x, norm.y, norm.z);
    glVertex3f(fbl.x, fbl.y, fbl.z);
    glVertex3f(fbm.x, fbm.y, fbm.z);
    glVertex3f(bbm.x, bbm.y, bbm.z);
    glVertex3f(bbl.x, bbl.y, bbl.z);
    glEnd();

    // lower right
    glBegin(GL_QUADS);
    norm = calculate_normal(fbr, fbm, bbm);
    glNormal3f(norm.x, norm.y, norm.z);
    glVertex3f(fbr.x, fbr.y, fbr.z);
    glVertex3f(fbm.x, fbm.y, fbm.z);
    glVertex3f(bbm.x, bbm.y, bbm.z);
    glVertex3f(bbr.x, bbr.y, bbr.z);
    glEnd();
    glPopMatrix();
}