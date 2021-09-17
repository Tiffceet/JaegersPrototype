#ifndef _LEG_H_
#define _LEG_H_
#include "typedefs.h"

extern Prop3D lleg_leg_badge_props;
extern Prop3D lleg_upper_foot;
extern Prop3D lleg_foot_joint;
extern Prop3D lleg_lower_leg;
extern Prop3D lleg_base;
extern Prop3D lleg_blueball_1;
extern Prop3D lleg_blueball_2;
extern Prop3D rleg_leg_badge_props;
extern Prop3D rleg_upper_foot;
extern Prop3D rleg_foot_joint;
extern Prop3D rleg_lower_leg;
extern Prop3D rleg_base;
extern Prop3D rleg_blueball_1;
extern Prop3D rleg_blueball_2;

void drawRobotLeftLeg(Prop3D props);
void drawRobotRightLeg(Prop3D props);
void drawTrapezoid(Prop3D props);
void drawOctoid(Prop3D props, float thickness);
void drawLegBadge(Prop3D props);
void drawAnklePad(Prop3D props);

#endif