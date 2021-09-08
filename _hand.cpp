#include "_hand.h"
#include <gl/freeglut.h>
#include "typedefs.h"
#include "primitives.h"
#include "texture.h"

void drawRobotHand(Prop3D props) {
    glPushMatrix();
    useTexture(-1);
    // applyProps(props);
    drawCube(props, {1,1,1});
    glPopMatrix();
}