#include "animation.h"
#include "_hand.h"
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
    } else {
        flip = true;
        lhand_arm.rot.x--;
        lhand_lower_arm.rot.x--;
        if(lhand_arm.rot.x < -30) {
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