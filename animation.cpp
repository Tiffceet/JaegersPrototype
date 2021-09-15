#include "animation.h"
#include "_hand.h"
bool _state_LeftArmGrab = false;
void InitObjectsPosition()
{
    InitLeftHandPosition();
}

void InitLeftHandPosition()
{
    lhand_upper_joint.origin.y = -2.5;
    lhand_upper_joint.rot.z = 30;

    lhand_upper_arm.pos = {2.5, -4, 0};
    lhand_upper_arm.rot.x = 90;

    lhand_lower_arm.pos = {2.5, -8, 0};
    lhand_lower_arm.rot.x = 90;

    lhand_palm.rot.x = 90;
    lhand_palm.pos = {2.5, -12, 0};

    lhand_fing_1.pos = {-1.1, 0, 2};
    lhand_fing_2.pos = {-0.4, 0, 2};
    lhand_fing_3.pos = {0.3, 0, 2};
    lhand_fing_4.pos = {1, 0, 2};

    lhand_fing_5.rot.y = 30;
    lhand_fing_5.pos = {1, 0, 2};
}

void ProcessAnimation() {
    LeftArmGrab();
}

void LeftArmGrab() {
    if(!_state_LeftArmGrab) {
        return;
    }

    if(lhand_upper_joint.rot.x < 30) {
        lhand_upper_joint.rot.x++;
    }
}