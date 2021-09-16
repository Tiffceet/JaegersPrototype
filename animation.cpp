#include "animation.h"
#include "_hand.h"
#include "_leg.h"
#include <map>
#include "primitives.h"

std::map<std::string, bool> animation_sequences;
void InitAnimationSequencesState()
{
    animation_sequences["LeftArmGrab"] = false;
}

void PlaySequence(std::string seq_name)
{
    InitObjectsPosition();
    animation_sequences[seq_name] = true;
}

// =============================================
// Init Functions
// =============================================

void InitObjectsPosition()
{
    InitLeftHandPosition();
    InitLegPosition();
}

void InitLeftHandPosition()
{
    clearProps(lhand_upper_joint);
    clearProps(lhand_arm);
    clearProps(lhand_upper_arm);
    clearProps(lhand_lower_arm);
    clearProps(lhand_palm);
    clearProps(lhand_fing_1);
    clearProps(lhand_fing_2);
    clearProps(lhand_fing_3);
    clearProps(lhand_fing_4);
    clearProps(lhand_fing_5);
    lhand_upper_joint.origin.y = -2.5;
    lhand_upper_joint.rot.z = 30;

    lhand_upper_arm.pos = {2.5, -4, 0};
    lhand_upper_arm.rot.x = 90;

    lhand_lower_arm.pos = {0, 0, 4};
    // lhand_lower_arm.rot.x = 90;

    // lhand_palm.rot.x = 90;
    // lhand_palm.pos = {2.5, -12, 0};
    lhand_palm.pos = {0, 0, 4};

    lhand_fing_1.pos = {-1.1, 0, 2};
    lhand_fing_2.pos = {-0.4, 0, 2};
    lhand_fing_3.pos = {0.3, 0, 2};
    lhand_fing_4.pos = {1, 0, 2};
    lhand_fing_5.rot.y = 30;
    lhand_fing_5.pos = {1, 0, 2};
}

void InitLegPosition()
{
    clearProps(lleg_leg_badge_props);
    clearProps(lleg_upper_foot);
    clearProps(lleg_foot_joint);
    clearProps(lleg_lower_leg);
    clearProps(lleg_base);
    clearProps(lleg_blueball_1);
    clearProps(lleg_blueball_2);
    clearProps(rleg_leg_badge_props);
    clearProps(rleg_upper_foot);
    clearProps(rleg_foot_joint);
    clearProps(rleg_lower_leg);
    clearProps(rleg_base);
    clearProps(rleg_blueball_1);
    clearProps(rleg_blueball_2);
    lleg_leg_badge_props.pos = {0, 6, 1};
    lleg_upper_foot.origin = {0, -2.5, 0};
    lleg_upper_foot.pos = {0, 5.5, 0};
    lleg_foot_joint.pos = {0, -3, -1};
    lleg_lower_leg.pos = {1, -3, 0};
    lleg_lower_leg.origin = {-1, -2.5, 0};
    lleg_base.scale = {2, 2, 2};
    lleg_base.pos = {-0.5, -1.75, 0};
    lleg_blueball_1.pos = {0.2, -3.5, 0.75};
    lleg_blueball_2.pos = {0.2, -3.5, -0.75};

    rleg_leg_badge_props.pos = {0, 6, -1};
    rleg_leg_badge_props.rot.y = 180;
    rleg_upper_foot.origin = {0, -2.5, 0};
    rleg_upper_foot.pos = {0, 5.5, 0};
    rleg_foot_joint.pos = {0, -3, -1};
    rleg_lower_leg.pos = {1, -3, 0};
    rleg_lower_leg.origin = {-1, -2.5, 0};
    rleg_base.scale = {2, 2, 2};
    rleg_base.pos = {-0.5, -1.75, 0};
    rleg_blueball_1.pos = {0.2, -3.5, 0.75};
    rleg_blueball_2.pos = {0.2, -3.5, -0.75};
}
// =============================================
// =============================================

// =============================================
// Animation Functions
// =============================================

void ProcessAnimation()
{
    LeftArmGrab();
}

bool flip = false;
void LeftArmGrab()
{
    if (!animation_sequences["LeftArmGrab"])
    {
        return;
    }

    if (!flip && lhand_arm.rot.x < 30)
    {
        lhand_arm.rot.x++;
        lhand_lower_arm.rot.x++;
        lhand_palm.rot.x++;
    }
    else
    {
        flip = true;
        lhand_arm.rot.x--;
        lhand_lower_arm.rot.x--;
        lhand_palm.rot.x--;
        if (lhand_arm.rot.x < -30)
        {
            flip = false;
        }
    }

    if (lhand_arm.rot.x > 30)
    {
        animation_sequences["LeftArmGrab"] = true;
    }
}
// =============================================
// =============================================