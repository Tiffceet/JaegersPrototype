#include "head.h"
#include <GL/freeglut.h>
#include "typedefs.h"
#include "primitives.h"
#include "texture.h"

void drawRobotHead(double x, Prop3D props)
{

    glPushMatrix();

    Prop3D clean;
    clean.pos.y = 4;
    clean.scale = {0.5, 0.5, 0.5};
    drawRobotHorn(clean);

    drawRobotMouth(x, props);
    drawRobotEye(x, props);

    drawRobotCheek(x, props);

    drawRobotForehead(x, props);
    drawRobotLeftEar(x, props);
    drawRobotRightEar(x, props);

    glPushMatrix();
    Prop3D props_neek;
    props_neek.rot.x = 90;
    //props_neek.pos.y = -2;
    applyProps(props_neek);
    drawRobotNeck(x, props_neek);
    glPopMatrix();

    glPopMatrix();
}

void drawRobotHorn(Prop3D props)
{
    glPushMatrix();
    applyProps(props);

    Prop3D cube_l;
    Prop3D cube_m;
    cube_l.origin = {-1, 0.25, 0};
    cube_l.pos = {-1, -0.25, 0};
    cube_l.rot = {0, 0, -60};
    Prop3D cube_r;
    cube_r.origin = {1, 0.25, 0};
    cube_r.pos = {1, -0.25, 0};
    cube_r.rot = {0, 0, 60};

    useTexture("armor");
    drawCube(cube_l, {2, 0.5, 0.5});
    drawCube(cube_m, {2, 0.5, 0.5});
    drawCube(cube_r, {2, 0.5, 0.5});

    glPopMatrix();
}

void drawRobotEye(double x, Prop3D props)
{
    useTexture("body");
    //eye

    //top
    glBegin(GL_QUADS);
    Vec3lf eye1 = calculate_normallf({-2 * x, 3 * x, -2 * x}, {2 * x, 3 * x, -2 * x}, {2 * x, 3 * x, 2 * x});
    glNormal3f(-eye1.x, -eye1.y, -eye1.z);
    glTexCoord2f(0, 1);
    glVertex3f(-2 * x, 3 * x, -2 * x);
    glTexCoord2f(1, 1);
    glVertex3f(2 * x, 3 * x, -2 * x);
    glTexCoord2f(1, 0);
    glVertex3f(2 * x, 3 * x, 2 * x);
    glTexCoord2f(0, 0);
    glVertex3f(-2 * x, 3 * x, 2 * x);
    glEnd();

    //bottom
    glBegin(GL_QUADS);
    Vec3lf eye2 = calculate_normallf({-2 * x, x, -2 * x}, {2 * x, x, -2 * x}, {2 * x, x, 2 * x});
    glNormal3f(eye2.x, eye2.y, eye2.z);
    glTexCoord2f(0, 1);
    glVertex3f(-2 * x, x, -2 * x);
    glTexCoord2f(1, 1);
    glVertex3f(2 * x, x, -2 * x);
    glTexCoord2f(1, 0);
    glVertex3f(2 * x, x, 2 * x);
    glTexCoord2f(0, 0);
    glVertex3f(-2 * x, x, 2 * x);
    glEnd();

    //front
    glBegin(GL_QUADS);
    Vec3lf eye3 = calculate_normallf({-2 * x, 3 * x, 2 * x}, {2 * x, 3 * x, 2 * x}, {2 * x, x, 2 * x});
    glNormal3f(-eye3.x, -eye3.y, -eye3.z);
    glTexCoord2f(0, 1);
    glVertex3f(-2 * x, 3 * x, 2 * x);
    glTexCoord2f(1, 1);
    glVertex3f(2 * x, 3 * x, 2 * x);
    glTexCoord2f(1, 0);
    glVertex3f(2 * x, x, 2 * x);
    glTexCoord2f(0, 0);
    glVertex3f(-2 * x, x, 2 * x);
    glEnd();

    //back
    glBegin(GL_QUADS);
    Vec3lf eye_back = calculate_normallf({-2 * x, 3 * x, 2 * x}, {2 * x, 3 * x, 2 * x}, {2 * x, x, 2 * x});
    glNormal3f(eye_back.x, eye_back.y, eye_back.z);
    glTexCoord2f(0, 1);
    glVertex3f(-2 * x, 3 * x, -2 * x);
    glTexCoord2f(1, 1);
    glVertex3f(2 * x, 3 * x, -2 * x);
    glTexCoord2f(1, 0);
    glVertex3f(2 * x, x, -2 * x);
    glTexCoord2f(0, 0);
    glVertex3f(-2 * x, x, -2 * x);
    glEnd();

    //left
    glBegin(GL_QUADS);
    Vec3lf eye4 = calculate_normallf({-2 * x, 3 * x, -2 * x}, {-2 * x, 3 * x, 2 * x}, {-2 * x, x, 2 * x});
    glNormal3f(-eye4.x, -eye4.y, -eye4.z);
    glTexCoord2f(0, 1);
    glVertex3f(-2 * x, 3 * x, -2 * x);
    glTexCoord2f(1, 1);
    glVertex3f(-2 * x, 3 * x, 2 * x);
    glTexCoord2f(1, 0);
    glVertex3f(-2 * x, x, 2 * x);
    glTexCoord2f(0, 0);
    glVertex3f(-2 * x, x, -2 * x);
    glEnd();

    //right
    glBegin(GL_QUADS);
    Vec3lf eye5 = calculate_normallf({2 * x, 3 * x, -2 * x}, {2 * x, 3 * x, 2 * x}, {2 * x, x, 2 * x});
    glNormal3f(eye5.x, eye5.y, eye5.z);
    glTexCoord2f(0, 1);
    glVertex3f(2 * x, 3 * x, -2 * x);
    glTexCoord2f(1, 1);
    glVertex3f(2 * x, 3 * x, 2 * x);
    glTexCoord2f(1, 0);
    glVertex3f(2 * x, x, 2 * x);
    glTexCoord2f(0, 0);
    glVertex3f(2 * x, x, -2 * x);
    glEnd();
}

void drawRobotCheek(double x, Prop3D props)
{
    useTexture("shiny");
    //mouth

    //bottom
    glBegin(GL_QUADS);
    Vec3lf che1 = calculate_normallf({-x, -x, -x}, {x, -x, -x}, {x, -x, x});
    glNormal3f(che1.x, che1.y, che1.z);
    glTexCoord2f(0, 1);
    glVertex3f(-x, -x, -x);
    glTexCoord2f(1, 1);
    glVertex3f(x, -x, -x);
    glTexCoord2f(1, 0);
    glVertex3f(x, -x, x);
    glTexCoord2f(0, 0);
    glVertex3f(-x, -x, x);
    glEnd();

    //front
    glBegin(GL_QUADS);
    Vec3lf che2 = calculate_normallf({-2 * x, x, 1.5 * x}, {2 * x, x, 1.5 * x}, {x, -x, x});
    glNormal3f(-che2.x, -che2.y, -che2.z);
    glTexCoord2f(0, 1);
    glVertex3f(-2 * x, x, 1.5 * x);
    glTexCoord2f(1, 1);
    glVertex3f(2 * x, x, 1.5 * x);
    glTexCoord2f(1, 0);
    glVertex3f(x, -x, x);
    glTexCoord2f(0, 0);
    glVertex3f(-x, -x, x);
    glEnd();

    //back
    glBegin(GL_QUADS);
    Vec3lf che3 = calculate_normallf({2 * x, x, -2 * x}, {-2 * x, x, -2 * x}, {-x, -x, -x});
    glNormal3f(-che3.x, -che3.y, -che3.z);
    glTexCoord2f(0, 1);
    glVertex3f(2 * x, x, -2 * x);
    glTexCoord2f(1, 1);
    glVertex3f(-2 * x, x, -2 * x);
    glTexCoord2f(1, 0);
    glVertex3f(-x, -x, -x);
    glTexCoord2f(0, 0);
    glVertex3f(x, -x, -x);
    glEnd();

    //left
    glBegin(GL_QUADS);
    Vec3lf che4 = calculate_normallf({-2 * x, x, -2 * x}, {-2 * x, x, 1.5 * x}, {-x, -x, x});
    glNormal3f(-che4.x, -che4.y, -che4.z);
    glTexCoord2f(0, 1);
    glVertex3f(-2 * x, x, -2 * x);
    glTexCoord2f(1, 1);
    glVertex3f(-2 * x, x, 1.5 * x);
    glTexCoord2f(1, 0);
    glVertex3f(-x, -x, x);
    glTexCoord2f(0, 0);
    glVertex3f(-x, -x, -x);
    glEnd();

    //right
    glBegin(GL_QUADS);
    Vec3lf che5 = calculate_normallf({2 * x, x, -2 * x}, {2 * x, x, 1.5 * x}, {x, -x, x});
    glNormal3f(che5.x, che5.y, che5.z);
    glTexCoord2f(0, 1);
    glVertex3f(2 * x, x, -2 * x);
    glTexCoord2f(1, 1);
    glVertex3f(2 * x, x, 1.5 * x);
    glTexCoord2f(1, 0);
    glVertex3f(x, -x, x);
    glTexCoord2f(0, 0);
    glVertex3f(x, -x, -x);
    glEnd();
}

void drawRobotMouth(double x, Prop3D props)
{
    useTexture("armor");
    //mouth

    //front
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    Vec3lf mou1 = calculate_normallf({-0.5 * x, 0.75 * x, 2 * x}, {0.5 * x, 0.75 * x, 2 * x}, {0.5 * x, -0.75 * x, 2 * x});
    glNormal3f(-mou1.x, -mou1.y, -mou1.z);
    glTexCoord2f(0, 1);
    glVertex3f(-0.5 * x, 0.75 * x, 2 * x);
    glTexCoord2f(1, 1);
    glVertex3f(0.5 * x, 0.75 * x, 2 * x);
    glTexCoord2f(1, 0);
    glVertex3f(0.5 * x, -0.75 * x, 2 * x);
    glTexCoord2f(0, 0);
    glVertex3f(-0.5 * x, -0.75 * x, 2 * x);
    glEnd();

    //top
    glBegin(GL_QUADS);
    Vec3lf mou2 = calculate_normallf({-x, x, 1.5 * x}, {x, x, 1.5 * x}, {0.5 * x, 0.75 * x, 2 * x});
    glNormal3f(-mou2.x, -mou2.y, -mou2.z);
    glTexCoord2f(0, 1);
    glVertex3f(-x, x, 1.5 * x);
    glTexCoord2f(1, 1);
    glVertex3f(x, x, 1.5 * x);
    glTexCoord2f(1, 0);
    glVertex3f(0.5 * x, 0.75 * x, 2 * x);
    glTexCoord2f(0, 0);
    glVertex3f(-0.5 * x, 0.75 * x, 2 * x);
    glEnd();

    //bottom
    glBegin(GL_QUADS);
    Vec3lf mou3 = calculate_normallf({0.5 * x, -0.75 * x, 2 * x}, {-0.5 * x, -0.75 * x, 2 * x}, {-x, -x, x});
    glNormal3f(mou3.x, mou3.y, mou3.z);
    glTexCoord2f(0, 1);
    glVertex3f(0.5 * x, -0.75 * x, 2 * x);
    glTexCoord2f(1, 1);
    glVertex3f(-0.5 * x, -0.75 * x, 2 * x);
    glTexCoord2f(1, 0);
    glVertex3f(-x, -x, x);
    glTexCoord2f(0, 0);
    glVertex3f(x, -x, x);
    glEnd();

    //left
    glBegin(GL_QUADS);
    Vec3lf mou4 = calculate_normallf({-x, x, 1.5 * x}, {-0.5 * x, 0.75 * x, 2 * x}, {-0.5 * x, -0.75 * x, 2 * x});
    glNormal3f(-mou4.x, -mou4.y, -mou4.z);
    glTexCoord2f(0, 1);
    glVertex3f(-x, x, 1.5 * x);
    glTexCoord2f(1, 1);
    glVertex3f(-0.5 * x, 0.75 * x, 2 * x);
    glTexCoord2f(1, 0);
    glVertex3f(-0.5 * x, -0.75 * x, 2 * x);
    glTexCoord2f(0, 0);
    glVertex3f(-x, -x, x);
    glEnd();

    //right
    glBegin(GL_QUADS);
    Vec3lf mou5 = calculate_normallf({0.5 * x, 0.75 * x, 2 * x}, {x, x, 1.5 * x}, {x, -x, x});
    glNormal3f(-mou5.x, -mou5.y, -mou5.z);
    glTexCoord2f(0, 1);
    glVertex3f(0.5 * x, 0.75 * x, 2 * x);
    glTexCoord2f(1, 1);
    glVertex3f(x, x, 1.5 * x);
    glTexCoord2f(1, 0);
    glVertex3f(x, -x, x);
    glTexCoord2f(0, 0);
    glVertex3f(0.5 * x, -0.75 * x, 2 * x);
    glEnd();
}

void drawRobotForehead(double x, Prop3D props)
{
    useTexture("shiny");
    //forehead

    //top
    glBegin(GL_QUADS);
    Vec3lf fh1 = calculate_normallf({-x, 4 * x, -1.5 * x}, {x, 4 * x, -1.5 * x}, {x, 4 * x, 0.5 * x});
    glNormal3f(-fh1.x, -fh1.y, -fh1.z);
    glTexCoord2f(0, 1);
    glVertex3f(-x, 4 * x, -1.5 * x);
    glTexCoord2f(1, 1);
    glVertex3f(x, 4 * x, -1.5 * x);
    glTexCoord2f(1, 0);
    glVertex3f(x, 4 * x, 0.5 * x);
    glTexCoord2f(0, 0);
    glVertex3f(-x, 4 * x, 0.5 * x);
    glEnd();

    //front
    glBegin(GL_QUADS);
    Vec3lf fh2 = calculate_normallf({-x, 4 * x, 0.5 * x}, {x, 4 * x, 0.5 * x}, {2 * x, 3 * x, 1.5 * x});
    glNormal3f(-fh2.x, -fh2.y, -fh2.z);
    glTexCoord2f(0, 1);
    glVertex3f(-x, 4 * x, 0.5 * x);
    glTexCoord2f(1, 1);
    glVertex3f(x, 4 * x, 0.5 * x);
    glTexCoord2f(1, 0);
    glVertex3f(2 * x, 3 * x, 1.5 * x);
    glTexCoord2f(0, 0);
    glVertex3f(-2 * x, 3 * x, 1.5 * x);
    glEnd();

    //back
    glBegin(GL_QUADS);
    Vec3lf fh3 = calculate_normallf({x, 4 * x, -1.5 * x}, {-x, 4 * x, -1.5 * x}, {-2 * x, 3 * x, -2 * x});
    glNormal3f(-fh3.x, -fh3.y, -fh3.z);
    glTexCoord2f(0, 1);
    glVertex3f(x, 4 * x, -1.5 * x);
    glTexCoord2f(1, 1);
    glVertex3f(-x, 4 * x, -1.5 * x);
    glTexCoord2f(1, 0);
    glVertex3f(-2 * x, 3 * x, -2 * x);
    glTexCoord2f(0, 0);
    glVertex3f(2 * x, 3 * x, -2 * x);
    glEnd();

    //left
    glBegin(GL_QUADS);
    Vec3lf fh4 = calculate_normallf({-x, 4 * x, -1.5 * x}, {-x, 4 * x, 0.5 * x}, {-2 * x, 3 * x, 1.5 * x});
    glNormal3f(-fh4.x, -fh4.y, -fh4.z);
    glTexCoord2f(0, 1);
    glVertex3f(-x, 4 * x, -1.5 * x);
    glTexCoord2f(1, 1);
    glVertex3f(-x, 4 * x, 0.5 * x);
    glTexCoord2f(1, 0);
    glVertex3f(-2 * x, 3 * x, 1.5 * x);
    glTexCoord2f(0, 0);
    glVertex3f(-2 * x, 3 * x, -2 * x);
    glEnd();

    //right
    glBegin(GL_QUADS);
    Vec3lf fh5 = calculate_normallf({x, 4 * x, -1.5 * x}, {x, 4 * x, 0.5 * x}, {2 * x, 3 * x, 1.5 * x});
    glNormal3f(fh5.x, fh5.y, fh5.z);
    glTexCoord2f(0, 1);
    glVertex3f(x, 4 * x, -1.5 * x);
    glTexCoord2f(1, 1);
    glVertex3f(x, 4 * x, 0.5 * x);
    glTexCoord2f(1, 0);
    glVertex3f(2 * x, 3 * x, 1.5 * x);
    glTexCoord2f(0, 0);
    glVertex3f(2 * x, 3 * x, -2 * x);
    glEnd();

    //head_back
    glBegin(GL_QUADS);
    Vec3lf fh6 = calculate_normallf({-2 * x, 3 * x, -2 * x}, {2 * x, 3 * x, -2 * x}, {2 * x, x, -2 * x});
    glNormal3f(fh6.x, fh6.y, fh6.z);
    glTexCoord2f(0, 1);
    glVertex3f(-2 * x, 3 * x, -2 * x);
    glTexCoord2f(1, 1);
    glVertex3f(2 * x, 3 * x, -2 * x);
    glTexCoord2f(1, 0);
    glVertex3f(2 * x, x, -2 * x);
    glTexCoord2f(0, 0);
    glVertex3f(-2 * x, x, -2 * x);
    glEnd();
}

void drawRobotLeftEar(double x, Prop3D props)
{
    useTexture("armor");
    //left ear

    //front
    glBegin(GL_QUADS);
    Vec3lf le1 = calculate_normallf({-2.5 * x, 2.5 * x, -0.5 * x}, {-2.5 * x, 2.5 * x, 0.5 * x}, {-2.5 * x, 1.5 * x, 0.5 * x});
    glNormal3f(-le1.x, -le1.y, -le1.z);
    glTexCoord2f(0, 1);
    glVertex3f(-2.5 * x, 2.5 * x, -0.5 * x);
    glTexCoord2f(1, 1);
    glVertex3f(-2.5 * x, 2.5 * x, 0.5 * x);
    glTexCoord2f(1, 0);
    glVertex3f(-2.5 * x, 1.5 * x, 0.5 * x);
    glTexCoord2f(0, 0);
    glVertex3f(-2.5 * x, 1.5 * x, -0.5 * x);
    glEnd();

    //top
    glBegin(GL_QUADS);
    Vec3lf le2 = calculate_normallf({-2 * x, 3 * x, -2 * x}, {-2 * x, 3 * x, x}, {-2.5 * x, 2.5 * x, 0.5 * x});
    glNormal3f(-le2.x, -le2.y, -le2.z);
    glTexCoord2f(0, 1);
    glVertex3f(-2 * x, 3 * x, -2 * x);
    glTexCoord2f(1, 1);
    glVertex3f(-2 * x, 3 * x, x);
    glTexCoord2f(1, 0);
    glVertex3f(-2.5 * x, 2.5 * x, 0.5 * x);
    glTexCoord2f(0, 0);
    glVertex3f(-2.5 * x, 2.5 * x, -0.5 * x);
    glEnd();

    //bottom
    glBegin(GL_QUADS);
    Vec3lf le3 = calculate_normallf({-2.5 * x, 1.5 * x, -0.5 * x}, {-2.5 * x, 1.5 * x, 0.5 * x}, {-2 * x, x, x});
    glNormal3f(-le3.x, -le3.y, -le3.z);
    glTexCoord2f(0, 1);
    glVertex3f(-2.5 * x, 1.5 * x, -0.5 * x);
    glTexCoord2f(1, 1);
    glVertex3f(-2.5 * x, 1.5 * x, 0.5 * x);
    glTexCoord2f(1, 0);
    glVertex3f(-2 * x, x, x);
    glTexCoord2f(0, 0);
    glVertex3f(-2 * x, x, -2 * x);
    glEnd();

    //left
    glBegin(GL_QUADS);
    Vec3lf le4 = calculate_normallf({-2 * x, 3 * x, -2 * x}, {-2.5 * x, 2.5 * x, -0.5 * x}, {-2.5 * x, 1.5 * x, -0.5 * x});
    glNormal3f(-le4.x, -le4.y, -le4.z);
    glTexCoord2f(0, 1);
    glVertex3f(-2 * x, 3 * x, -2 * x);
    glTexCoord2f(1, 1);
    glVertex3f(-2.5 * x, 2.5 * x, -0.5 * x);
    glTexCoord2f(1, 0);
    glVertex3f(-2.5 * x, 1.5 * x, -0.5 * x);
    glTexCoord2f(0, 0);
    glVertex3f(-2 * x, x, -2 * x);
    glEnd();

    //left
    glBegin(GL_QUADS);
    Vec3lf le5 = calculate_normallf({-2.5 * x, 2.5 * x, 0.5 * x}, {-2 * x, 3 * x, x}, {-2 * x, x, x});
    glNormal3f(-le5.x, -le5.y, -le5.z);
    glTexCoord2f(0, 1);
    glVertex3f(-2.5 * x, 2.5 * x, 0.5 * x);
    glTexCoord2f(1, 1);
    glVertex3f(-2 * x, 3 * x, x);
    glTexCoord2f(1, 0);
    glVertex3f(-2 * x, x, x);
    glTexCoord2f(0, 0);
    glVertex3f(-2.5 * x, 1.5 * x, 0.5 * x);
    glEnd();
}

void drawRobotRightEar(double x, Prop3D props)
{
    useTexture("armor");
    //right ear

    //front
    glBegin(GL_QUADS);
    Vec3lf re1 = calculate_normallf({2.5 * x, 2.5 * x, 0.5 * x}, {2.5 * x, 2.5 * x, -0.5 * x}, {2.5 * x, 1.5 * x, -0.5 * x});
    glNormal3f(-re1.x, -re1.y, -re1.z);
    glTexCoord2f(0, 1);
    glVertex3f(2.5 * x, 2.5 * x, 0.5 * x);
    glTexCoord2f(1, 1);
    glVertex3f(2.5 * x, 2.5 * x, -0.5 * x);
    glTexCoord2f(1, 0);
    glVertex3f(2.5 * x, 1.5 * x, -0.5 * x);
    glTexCoord2f(0, 0);
    glVertex3f(2.5 * x, 1.5 * x, 0.5 * x);
    glEnd();

    //top
    glBegin(GL_QUADS);
    Vec3lf re2 = calculate_normallf({2 * x, 3 * x, x}, {2 * x, 3 * x, -2 * x}, {2.5 * x, 2.5 * x, -0.5 * x});
    glNormal3f(-re2.x, -re2.y, -re2.z);
    glTexCoord2f(0, 1);
    glVertex3f(2 * x, 3 * x, x);
    glTexCoord2f(1, 1);
    glVertex3f(2 * x, 3 * x, -2 * x);
    glTexCoord2f(1, 0);
    glVertex3f(2.5 * x, 2.5 * x, -0.5 * x);
    glTexCoord2f(0, 0);
    glVertex3f(2.5 * x, 2.5 * x, 0.5 * x);
    glEnd();

    //bottom
    glBegin(GL_QUADS);
    Vec3lf re3 = calculate_normallf({2.5 * x, 1.5 * x, 0.5 * x}, {2.5 * x, 1.5 * x, -0.5 * x}, {2 * x, x, -2 * x});
    glNormal3f(-re3.x, -re3.y, -re3.z);
    glTexCoord2f(0, 1);
    glVertex3f(2.5 * x, 1.5 * x, 0.5 * x);
    glTexCoord2f(1, 1);
    glVertex3f(2.5 * x, 1.5 * x, -0.5 * x);
    glTexCoord2f(1, 0);
    glVertex3f(2 * x, x, -2 * x);
    glTexCoord2f(0, 0);
    glVertex3f(2 * x, x, x);
    glEnd();

    //right
    glBegin(GL_QUADS);
    Vec3lf re4 = calculate_normallf({2.5 * x, 2.5 * x, -0.5 * x}, {2 * x, 3 * x, -2 * x}, {2 * x, x, -2 * x});
    glNormal3f(-re4.x, -re4.y, -re4.z);
    glTexCoord2f(0, 1);
    glVertex3f(2.5 * x, 2.5 * x, -0.5 * x);
    glTexCoord2f(1, 1);
    glVertex3f(2 * x, 3 * x, -2 * x);
    glTexCoord2f(1, 0);
    glVertex3f(2 * x, x, -2 * x);
    glTexCoord2f(0, 0);
    glVertex3f(2.5 * x, 1.5 * x, -0.5 * x);
    glEnd();

    //left
    glBegin(GL_QUADS);
    Vec3lf re5 = calculate_normallf({2 * x, 3 * x, x}, {2.5 * x, 2.5 * x, 0.5 * x}, {2.5 * x, 1.5 * x, 0.5 * x});
    glNormal3f(-re5.x, -re5.y, -re5.z);
    glTexCoord2f(0, 1);
    glVertex3f(2 * x, 3 * x, x);
    glTexCoord2f(1, 1);
    glVertex3f(2.5 * x, 2.5 * x, 0.5 * x);
    glTexCoord2f(1, 0);
    glVertex3f(2.5 * x, 1.5 * x, 0.5 * x);
    glTexCoord2f(0, 0);
    glVertex3f(2 * x, x, x);
    glEnd();
}

void drawRobotNeck(double x, Prop3D props)
{
    useTexture("shiny");
    GLUquadricObj *cylinder = NULL;
    cylinder = gluNewQuadric();
    gluQuadricTexture(cylinder, true);
    gluCylinder(cylinder, 0.75 * x, 0.75 * x, 3 * x, 50, 50);
    gluDeleteQuadric(cylinder);
}