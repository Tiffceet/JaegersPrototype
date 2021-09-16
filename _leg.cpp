#include <gl/freeglut.h>
#define _USE_MATH_DEFINES
#include "_leg.h"
#include "typedefs.h"
#include "primitives.h"
#include "texture.h"
#include "math.h"
int foot_frame = 0;
void drawRobotLeftLeg(Prop3D props)
{
    Prop3D clean;
    glPushMatrix();
    applyProps(props);
    Prop3D lleg_leg_badge_props;
    lleg_leg_badge_props.pos = {0, 6, 1};
    drawLegBadge(lleg_leg_badge_props);

    glPushMatrix();
    Prop3D lleg_upper_foot;
    lleg_upper_foot.origin = {0, -2.5, 0};
    lleg_upper_foot.pos = {0, 5.5, 0};
    applyProps(lleg_upper_foot);
    useTexture("shiny");
    drawCube(clean, {1.9, 5, 1.9});

    glPushMatrix();
    Prop3D lleg_foot_joint;
    lleg_foot_joint.pos = {0, -3, -1};
    useTexture("brick");
    drawCylinder(lleg_foot_joint, 0.75, 0.75, 2, 30, 30);

    Prop3D lleg_lower_leg;
    lleg_lower_leg.pos = {1, -3, 0};
    lleg_lower_leg.origin = {-1, -2.5, 0};
    // lleg_lower_leg.rot.x = foot_frame++;
    glPushMatrix();
    applyProps(lleg_lower_leg);
    useTexture("shiny");
    drawCube(clean, {1.9, 5, 1.9});

    Prop3D lleg_base;
    lleg_base.scale = {2, 2, 2};
    lleg_base.pos = {-0.5, -1.75, 0};
    useTexture("box");
    drawTrapezoid(lleg_base);

    Prop3D lleg_blueball_1;
    lleg_blueball_1.pos = {0.2, -3.5, 0.75};
    useTexture("shiny");
    drawSphere(lleg_blueball_1, 0.75, 30, 30);

    Prop3D lleg_blueball_2;
    lleg_blueball_2.pos = {0.2, -3.5, -0.75};
    useTexture("shiny");
    drawSphere(lleg_blueball_2, 0.75, 30, 30);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}
void drawRobotRightLeg(Prop3D props)
{
    Prop3D clean;
    glPushMatrix();
    applyProps(props);
    Prop3D rleg_leg_badge_props;
    rleg_leg_badge_props.pos = {0, 6, -1};

    rleg_leg_badge_props.rot.y = 180;

    drawLegBadge(rleg_leg_badge_props);

    glPushMatrix();
    Prop3D rleg_upper_foot;
    rleg_upper_foot.origin = {0, -2.5, 0};
    rleg_upper_foot.pos = {0, 5.5, 0};
    applyProps(rleg_upper_foot);
    useTexture("shiny");
    drawCube(clean, {1.9, 5, 1.9});

    glPushMatrix();
    Prop3D rleg_foot_joint;
    rleg_foot_joint.pos = {0, -3, -1};
    useTexture("brick");
    drawCylinder(rleg_foot_joint, 0.75, 0.75, 2, 30, 30);

    Prop3D rleg_lower_leg;
    rleg_lower_leg.pos = {1, -3, 0};
    rleg_lower_leg.origin = {-1, -2.5, 0};
    // rleg_lower_leg.rot.x = foot_frame++;
    glPushMatrix();
    applyProps(rleg_lower_leg);
    useTexture("shiny");
    drawCube(clean, {1.9, 5, 1.9});

    Prop3D rleg_base;
    rleg_base.scale = {2, 2, 2};
    rleg_base.pos = {-0.5, -1.75, 0};
    useTexture("box");
    drawTrapezoid(rleg_base);

    Prop3D rleg_blueball_1;
    rleg_blueball_1.pos = {0.2, -3.5, 0.75};
    useTexture("shiny");
    drawSphere(rleg_blueball_1, 0.75, 30, 30);

    Prop3D rleg_blueball_2;
    rleg_blueball_2.pos = {0.2, -3.5, -0.75};
    useTexture("shiny");
    drawSphere(rleg_blueball_2, 0.75, 30, 30);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
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
