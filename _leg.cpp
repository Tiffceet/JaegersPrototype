#include <gl/freeglut.h>
#define _USE_MATH_DEFINES
#include "_leg.h"
#include "typedefs.h"
#include "primitives.h"
#include "texture.h"
#include "math.h"
int foot_frame = 0;
Prop3D lleg_leg_badge_props;
Prop3D lleg_upper_foot;
Prop3D lleg_foot_joint;
Prop3D lleg_lower_leg;
Prop3D lleg_base;
Prop3D lleg_blueball_1;
Prop3D lleg_blueball_2;
Prop3D rleg_leg_badge_props;
Prop3D rleg_upper_foot;
Prop3D rleg_foot_joint;
Prop3D rleg_lower_leg;
Prop3D rleg_base;
Prop3D rleg_blueball_1;
Prop3D rleg_blueball_2;
void drawRobotLeftLeg(Prop3D props)
{
    Prop3D clean;
    glPushMatrix();
    applyProps(props);

    drawLegBadge(lleg_leg_badge_props);

    glPushMatrix();

    applyProps(lleg_upper_foot);
    useTexture("shiny");
    drawCube(clean, {1.9, 5, 1.9});

    glPushMatrix();

    Prop3D lleg_ankle_pad;
    lleg_ankle_pad.pos = {-1.1, -3, 0};
    lleg_ankle_pad.rot = {0, -90, 0};
    drawAnklePad(lleg_ankle_pad);
    useTexture("armor");
    drawCylinder(lleg_foot_joint, 0.75, 0.75, 2, 30, 30);

    glPushMatrix();
    applyProps(lleg_lower_leg);
    useTexture("shiny");
    drawCube(clean, {1.9, 5, 1.9});

    useTexture("armor");
    drawTrapezoid(lleg_base);

    useTexture("water-b");
    drawSphere(lleg_blueball_1, 0.75, 30, 30);

    useTexture("water-b");
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

    drawLegBadge(rleg_leg_badge_props);

    glPushMatrix();

    applyProps(rleg_upper_foot);
    useTexture("shiny");
    drawCube(clean, {1.9, 5, 1.9});

    glPushMatrix();

    Prop3D rleg_ankle_pad;
    rleg_ankle_pad.pos = {-1.1, -3, 0};
    rleg_ankle_pad.rot = {0, -90, 0};
    drawAnklePad(rleg_ankle_pad);
    useTexture("armor");
    drawCylinder(rleg_foot_joint, 0.75, 0.75, 2, 30, 30);

    glPushMatrix();
    applyProps(rleg_lower_leg);
    useTexture("shiny");
    drawCube(clean, {1.9, 5, 1.9});

    useTexture("armor");
    drawTrapezoid(rleg_base);

    useTexture("water-b");
    drawSphere(rleg_blueball_1, 0.75, 30, 30);

    useTexture("water-b");
    drawSphere(rleg_blueball_2, 0.75, 30, 30);

    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}

void p(Vec3f v, std::string label)
{
    std::cout << label << ": " << v.x << ", " << v.y << ", " << v.z << std::endl;
}

void drawLegBadge(Prop3D props)
{
    glPushMatrix();
    applyProps(props);
    Prop3D badge_props;
    badge_props.pos = {0, 0, 0.5};
    useTexture("water-b");
    drawOctoid(badge_props, 0.2);

    Prop3D badge_cont_props;
    badge_cont_props.scale = {1.5, 1.5, 1.5};
    useTexture("armor");
    drawOctoid(badge_cont_props, 0.5);
    glPopMatrix();
}

void drawAnklePad(Prop3D props)
{
    glPushMatrix();
    applyProps(props);

    Prop3D frontCube;
    Prop3D leftCube;
    leftCube.origin = {-1, 0, -0.25};
    leftCube.pos = {-1, 0, 0.25};
    leftCube.rot.y = -80;
    Prop3D rightCube;
    rightCube.origin = {1, 0, -0.25};
    rightCube.pos = {1, 0, 0.25};
    rightCube.rot.y = 80;
    Prop3D topCube;
    topCube.origin = {0, 1, -0.25};
    topCube.pos = {0, 1, 0.25};
    topCube.rot.x = -10;
    Prop3D bottomCube;
    bottomCube.origin = {0, -1, -0.25};
    bottomCube.pos = {0, -1, 0.25};
    bottomCube.rot.x = 10;

    useTexture("armor");
    drawCube(frontCube, {2, 2, 0.5});
    drawCube(leftCube, {2, 2, 0.5});
    drawCube(rightCube, {2, 2, 0.5});
    drawCube(topCube, {2, 2, 0.5});
    drawCube(bottomCube, {2, 2, 0.5});

    glPopMatrix();
}