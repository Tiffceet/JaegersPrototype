#define _USE_MATH_DEFINES
#include "primitives.h"
#include "typedefs.h"
#include <GL/freeglut.h>
#include <cmath>
#include "texture.h"

void applyProps(Prop3D props)
{
    glScalef(props.scale.x, props.scale.y, props.scale.z);
    glTranslatef(props.pos.x, props.pos.y, props.pos.z);
    glRotatef(props.rot.z, 0, 0, 1);
    glRotatef(props.rot.y, 0, 1, 0);
    glRotatef(props.rot.x, 1, 0, 0);
    glTranslatef(props.origin.x, props.origin.y, props.origin.z);
}

void clearProps(Prop3D &props)
{
    props.origin = {0, 0, 0};
    props.pos = {0, 0, 0};
    props.scale = {1, 1, 1};
    props.rot = {0, 0, 0};
}

void applyPropsDebug(Prop3D props)
{
    glScalef(props.scale.x, props.scale.y, props.scale.z);
    glTranslatef(props.pos.x, props.pos.y, props.pos.z);
    glRotatef(props.rot.x, 1, 0, 0);
    glRotatef(props.rot.y, 0, 1, 0);
    glRotatef(props.rot.z, 0, 0, 1);

    // Debug: Draw origin
    glDisable(GL_DEPTH_TEST);
    glColor3f(1, 1, 1);
    glPointSize(10);
    glBegin(GL_POINTS);
    glVertex3f(0, 0, 0);
    glEnd();
    glEnable(GL_DEPTH_TEST);

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
    glNormal3f(0, 0, -1);
    glTexCoord2f(0, 1);
    glVertex3f(ftl[0], ftl[1], ftl[2]);
    glTexCoord2f(1, 1);
    glVertex3f(ftr[0], ftr[1], ftr[2]);
    glTexCoord2f(1, 0);
    glVertex3f(fbr[0], fbr[1], fbr[2]);
    glTexCoord2f(0, 0);
    glVertex3f(fbl[0], fbl[1], fbl[2]);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(ftr[0], ftr[1], ftr[2]);
    glTexCoord2f(1, 1);
    glVertex3f(btr[0], btr[1], btr[2]);
    glTexCoord2f(1, 0);
    glVertex3f(bbr[0], bbr[1], bbr[2]);
    glTexCoord2f(0, 0);
    glVertex3f(fbr[0], fbr[1], fbr[2]);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(0, -1, 0);
    glTexCoord2f(0, 1);
    glVertex3f(fbl[0], fbl[1], fbl[2]);
    glTexCoord2f(1, 1);
    glVertex3f(fbr[0], fbr[1], fbr[2]);
    glTexCoord2f(1, 0);
    glVertex3f(bbr[0], bbr[1], bbr[2]);
    glTexCoord2f(0, 0);
    glVertex3f(bbl[0], bbl[1], bbl[2]);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0, 1);
    glVertex3f(fbl[0], fbl[1], fbl[2]);
    glTexCoord2f(1, 1);
    glVertex3f(bbl[0], bbl[1], bbl[2]);
    glTexCoord2f(1, 0);
    glVertex3f(btl[0], btl[1], btl[2]);
    glTexCoord2f(0, 0);
    glVertex3f(ftl[0], ftl[1], ftl[2]);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(0, 1, 0);
    glTexCoord2f(0, 1);
    glVertex3f(btl[0], btl[1], btl[2]);
    glTexCoord2f(1, 1);
    glVertex3f(btr[0], btr[1], btr[2]);
    glTexCoord2f(1, 0);
    glVertex3f(ftr[0], ftr[1], ftr[2]);
    glTexCoord2f(0, 0);
    glVertex3f(ftl[0], ftl[1], ftl[2]);
    glEnd();

    glBegin(GL_QUADS);
    glNormal3f(0, 0, 1);
    glTexCoord2f(0, 1);
    glVertex3f(btl[0], btl[1], btl[2]);
    glTexCoord2f(1, 1);
    glVertex3f(btr[0], btr[1], btr[2]);
    glTexCoord2f(1, 0);
    glVertex3f(bbr[0], bbr[1], bbr[2]);
    glTexCoord2f(0, 0);
    glVertex3f(bbl[0], bbl[1], bbl[2]);
    glEnd();
    glPopMatrix();
}

void draw2DCircle(Prop3D props, float r)
{
    glPushMatrix();
    applyProps(props);
    float i = 0.0f;

    glBegin(GL_TRIANGLE_FAN);
    for (i = 0.0f; i <= 360; i++)
        glVertex2f(r * cos(M_PI * i / 180.0), r * sin(M_PI * i / 180.0));

    glEnd();
    glPopMatrix();
}

void draw2DSquare(Prop3D props, float size)
{
    glPushMatrix();
    applyProps(props);

    Vec3f p1 = {-size / 2, size / 2, 0};
    Vec3f p2 = {size / 2, size / 2, 0};
    Vec3f p3 = {size / 2, -size / 2, 0};
    Vec3f p4 = {-size / 2, -size / 2, 0};

    glBegin(GL_QUADS);
    Vec3f norm = calculate_normal(p1, p2, p3);
    glNormal3f(norm.x, norm.y, norm.z);
    glTexCoord2f(0, 1);
    glVertex3f(p1.x, p1.y, p1.z);
    glTexCoord2f(1, 1);
    glVertex3f(p2.x, p2.y, p2.z);
    glTexCoord2f(1, 0);
    glVertex3f(p3.x, p3.y, p3.z);
    glTexCoord2f(0, 0);
    glVertex3f(p4.x, p4.y, p4.z);
    glEnd();

    glPopMatrix();
}

void drawCylinder(Prop3D props, GLdouble baseRadius, GLdouble topRadius, GLdouble height, GLint slices, GLint stacks)
{
    glPushMatrix();
    applyProps(props);
    GLUquadricObj *cylinder = gluNewQuadric();
    gluQuadricTexture(cylinder, true);
    gluQuadricDrawStyle(cylinder, GL_FILL);
    gluCylinder(cylinder, baseRadius, topRadius, height, slices, stacks);
    gluDeleteQuadric(cylinder);

    Prop3D cover_props;
    draw2DCircle(cover_props, baseRadius);
    cover_props.pos = {0, 0, (float)height};
    draw2DCircle(cover_props, topRadius);

    glPopMatrix();
}

void drawSphere(Prop3D props, GLdouble radius, GLint slices, GLint stacks)
{
    glPushMatrix();
    applyProps(props);
    GLUquadricObj *sphere = gluNewQuadric();
    gluQuadricTexture(sphere, true);
    gluQuadricDrawStyle(sphere, GL_FILL);
    gluSphere(sphere, radius, slices, stacks);
    gluDeleteQuadric(sphere);
    glPopMatrix();
}

void drawPyramid(Prop3D props, float length, float width, float height)
{
    glPushMatrix();
    applyProps(props);
    Vec3f peak = {0, height / 2, 0};
    Vec3f tl = {-length / 2, -height / 2, width / 2};
    Vec3f tr = {length / 2, -height / 2, width / 2};
    Vec3f bl = {-length / 2, -height / 2, -width / 2};
    Vec3f br = {length / 2, -height / 2, -width / 2};

    glBegin(GL_QUADS);
    glTexCoord2f(0, 1);
    glVertex3f(tl.x, tl.y, tl.z);
    glTexCoord2f(1, 1);
    glVertex3f(tr.x, tr.y, tr.z);
    glTexCoord2f(1, 0);
    glVertex3f(br.x, br.y, br.z);
    glTexCoord2f(0, 0);
    glVertex3f(bl.x, bl.y, bl.z);
    glEnd();

    glBegin(GL_TRIANGLES);
    glTexCoord2f(0, 0);
    glVertex3f(tl.x, tl.y, tl.z);
    glTexCoord2f(1, 0);
    glVertex3f(tr.x, tr.y, tr.z);
    glTexCoord2f(0.5, 1);
    glVertex3f(peak.x, peak.y, peak.z);

    glTexCoord2f(0, 0);
    glVertex3f(tr.x, tr.y, tr.z);
    glTexCoord2f(1, 0);
    glVertex3f(br.x, br.y, br.z);
    glTexCoord2f(0.5, 1);
    glVertex3f(peak.x, peak.y, peak.z);

    glTexCoord2f(0, 0);
    glVertex3f(br.x, br.y, br.z);
    glTexCoord2f(1, 0);
    glVertex3f(bl.x, bl.y, bl.z);
    glTexCoord2f(0.5, 1);
    glVertex3f(peak.x, peak.y, peak.z);

    glTexCoord2f(0, 0);
    glVertex3f(bl.x, bl.y, bl.z);
    glTexCoord2f(1, 0);
    glVertex3f(tl.x, tl.y, tl.z);
    glTexCoord2f(0.5, 1);
    glVertex3f(peak.x, peak.y, peak.z);
    glEnd();

    glPopMatrix();
}

Vec3f calculate_normal(Vec3f pt1, Vec3f pt2, Vec3f pt3)
{
    // Calculate 2 vector + cross product
    Vec3f x = pt2 - pt1;
    Vec3f y = pt3 - pt1;
    Vec3f norm = x * y;

    // Normalize the vector
    float magnitude = sqrt(norm.x * norm.x + norm.y * norm.y + norm.z * norm.z);
    norm.x = norm.x / magnitude;
    norm.y = norm.y / magnitude;
    norm.z = norm.z / magnitude;
    return norm;
}

Vec3lf calculate_normallf(Vec3lf pt1, Vec3lf pt2, Vec3lf pt3)
{
    // Calculate 2 vector + cross product
    Vec3lf x = pt2 - pt1;
    Vec3lf y = pt3 - pt1;
    Vec3lf norm = x * y;

    // Normalize the vector
    double magnitude = sqrt(norm.x * norm.x + norm.y * norm.y + norm.z * norm.z);
    norm.x = norm.x / magnitude;
    norm.y = norm.y / magnitude;
    norm.z = norm.z / magnitude;
    return norm;
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

    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    Vec3f norm = calculate_normal(f_1, f_2, f_3);
    glNormal3f(norm.x, norm.y, norm.z);
    glTexCoord2f((f_1.x + 1.0) / 2, (f_1.y + 1.0) / 2);
    glVertex3f(f_1.x, f_1.y, f_1.z);
    glTexCoord2f((f_2.x + 1.0) / 2, (f_2.y + 1.0) / 2);
    glVertex3f(f_2.x, f_2.y, f_2.z);
    glTexCoord2f((f_3.x + 1.0) / 2, (f_3.y + 1.0) / 2);
    glVertex3f(f_3.x, f_3.y, f_3.z);
    glTexCoord2f((f_4.x + 1.0) / 2, (f_4.y + 1.0) / 2);
    glVertex3f(f_4.x, f_4.y, f_4.z);
    glTexCoord2f((f_5.x + 1.0) / 2, (f_5.y + 1.0) / 2);
    glVertex3f(f_5.x, f_5.y, f_5.z);
    glTexCoord2f((f_6.x + 1.0) / 2, (f_6.y + 1.0) / 2);
    glVertex3f(f_6.x, f_6.y, f_6.z);
    glTexCoord2f((f_7.x + 1.0) / 2, (f_7.y + 1.0) / 2);
    glVertex3f(f_7.x, f_7.y, f_7.z);
    glTexCoord2f((f_8.x + 1.0) / 2, (f_8.y + 1.0) / 2);
    glVertex3f(f_8.x, f_8.y, f_8.z);
    glEnd();

    useTexture("armor");
    glBegin(GL_POLYGON);
    norm = calculate_normal(b_1, b_2, b_3);
    norm = -norm;
    glNormal3f(norm.x, norm.y, norm.z);
    glTexCoord2f((f_1.x + 1.0) / 2, (f_1.y + 1.0) / 2);
    glVertex3f(b_1.x, b_1.y, b_1.z);
    glTexCoord2f((f_2.x + 1.0) / 2, (f_2.y + 1.0) / 2);
    glVertex3f(b_2.x, b_2.y, b_2.z);
    glTexCoord2f((f_3.x + 1.0) / 2, (f_3.y + 1.0) / 2);
    glVertex3f(b_3.x, b_3.y, b_3.z);
    glTexCoord2f((f_4.x + 1.0) / 2, (f_4.y + 1.0) / 2);
    glVertex3f(b_4.x, b_4.y, b_4.z);
    glTexCoord2f((f_5.x + 1.0) / 2, (f_5.y + 1.0) / 2);
    glVertex3f(b_5.x, b_5.y, b_5.z);
    glTexCoord2f((f_6.x + 1.0) / 2, (f_6.y + 1.0) / 2);
    glVertex3f(b_6.x, b_6.y, b_6.z);
    glTexCoord2f((f_7.x + 1.0) / 2, (f_7.y + 1.0) / 2);
    glVertex3f(b_7.x, b_7.y, b_7.z);
    glTexCoord2f((f_8.x + 1.0) / 2, (f_8.y + 1.0) / 2);
    glVertex3f(b_8.x, b_8.y, b_8.z);
    glEnd();

    glBegin(GL_QUADS);
    norm = calculate_normal(b_1, f_1, f_2);
    glNormal3f(norm.x, norm.y, norm.z);
    glNormal3f(-norm.x, -norm.y, -norm.z);
    glTexCoord2f(0, 0);
    glVertex3f(b_1.x, b_1.y, b_1.z);
    glTexCoord2f(0, 1);
    glVertex3f(f_1.x, f_1.y, f_1.z);
    glTexCoord2f(1, 1);
    glVertex3f(f_2.x, f_2.y, f_2.z);
    glTexCoord2f(1, 0);
    glVertex3f(b_2.x, b_2.y, b_2.z);
    glEnd();

    glBegin(GL_QUADS);
    norm = calculate_normal(b_2, f_2, f_3);
    glNormal3f(norm.x, norm.y, norm.z);
    glNormal3f(-norm.x, -norm.y, -norm.z);
    glTexCoord2f(0, 0);
    glVertex3f(b_2.x, b_2.y, b_2.z);
    glTexCoord2f(0, 1);
    glVertex3f(f_2.x, f_2.y, f_2.z);
    glTexCoord2f(1, 1);
    glVertex3f(f_3.x, f_3.y, f_3.z);
    glTexCoord2f(1, 0);
    glVertex3f(b_3.x, b_3.y, b_3.z);
    glEnd();

    glBegin(GL_QUADS);
    norm = calculate_normal(b_3, f_3, f_4);
    glNormal3f(norm.x, norm.y, norm.z);
    glNormal3f(-norm.x, -norm.y, -norm.z);
    glTexCoord2f(0, 0);
    glVertex3f(b_3.x, b_3.y, b_3.z);
    glTexCoord2f(0, 1);
    glVertex3f(f_3.x, f_3.y, f_3.z);
    glTexCoord2f(1, 1);
    glVertex3f(f_4.x, f_4.y, f_4.z);
    glTexCoord2f(1, 0);
    glVertex3f(b_4.x, b_4.y, b_4.z);
    glEnd();

    glBegin(GL_QUADS);
    norm = calculate_normal(b_4, f_4, f_5);
    glNormal3f(norm.x, norm.y, norm.z);
    glNormal3f(-norm.x, -norm.y, -norm.z);
    glTexCoord2f(0, 0);
    glVertex3f(b_4.x, b_4.y, b_4.z);
    glTexCoord2f(0, 1);
    glVertex3f(f_4.x, f_4.y, f_4.z);
    glTexCoord2f(1, 1);
    glVertex3f(f_5.x, f_5.y, f_5.z);
    glTexCoord2f(1, 0);
    glVertex3f(b_5.x, b_5.y, b_5.z);
    glEnd();

    glBegin(GL_QUADS);
    norm = calculate_normal(b_5, f_5, f_6);
    glNormal3f(norm.x, norm.y, norm.z);
    glNormal3f(-norm.x, -norm.y, -norm.z);
    glTexCoord2f(0, 0);
    glVertex3f(b_5.x, b_5.y, b_5.z);
    glTexCoord2f(0, 1);
    glVertex3f(f_5.x, f_5.y, f_5.z);
    glTexCoord2f(1, 1);
    glVertex3f(f_6.x, f_6.y, f_6.z);
    glTexCoord2f(1, 0);
    glVertex3f(b_6.x, b_6.y, b_6.z);
    glEnd();

    glBegin(GL_QUADS);
    norm = calculate_normal(b_6, f_6, f_7);
    glNormal3f(norm.x, norm.y, norm.z);
    glNormal3f(-norm.x, -norm.y, -norm.z);
    glTexCoord2f(0, 0);
    glVertex3f(b_6.x, b_6.y, b_6.z);
    glTexCoord2f(0, 1);
    glVertex3f(f_6.x, f_6.y, f_6.z);
    glTexCoord2f(1, 1);
    glVertex3f(f_7.x, f_7.y, f_7.z);
    glTexCoord2f(1, 0);
    glVertex3f(b_7.x, b_7.y, b_7.z);
    glEnd();

    glBegin(GL_QUADS);
    norm = calculate_normal(b_7, f_7, f_8);
    glNormal3f(norm.x, norm.y, norm.z);
    glNormal3f(-norm.x, -norm.y, -norm.z);
    glTexCoord2f(0, 0);
    glVertex3f(b_7.x, b_7.y, b_7.z);
    glTexCoord2f(0, 1);
    glVertex3f(f_7.x, f_7.y, f_7.z);
    glTexCoord2f(1, 1);
    glVertex3f(f_8.x, f_8.y, f_8.z);
    glTexCoord2f(1, 0);
    glVertex3f(b_8.x, b_8.y, b_8.z);
    glEnd();

    glBegin(GL_QUADS);
    norm = calculate_normal(b_8, f_8, b_1);
    glNormal3f(norm.x, norm.y, norm.z);
    glNormal3f(-norm.x, -norm.y, -norm.z);
    glTexCoord2f(0, 0);
    glVertex3f(b_8.x, b_8.y, b_8.z);
    glTexCoord2f(0, 1);
    glVertex3f(f_8.x, f_8.y, f_8.z);
    glTexCoord2f(1, 1);
    glVertex3f(f_1.x, f_1.y, f_1.z);
    glTexCoord2f(1, 0);
    glVertex3f(b_1.x, b_1.y, b_1.z);
    glEnd();

    glPopMatrix();
}