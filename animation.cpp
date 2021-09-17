#include "animation.h"
#include "_hand.h"
#include "_leg.h"
#include <map>
#include "primitives.h"
#include "spawnable_object.h"

Prop3D MainRobotProps;
Vec3f RobotFacing = {0, 0, 1};
bool animation_playing = false;

std::map<std::string, bool> animation_sequences;
void InitAnimationSequencesState()
{
    animation_sequences["LeftArmGrab_1"] = false;
    animation_sequences["LeftArmGrab_2"] = false;
    animation_sequences["LeftArmGrab_3"] = false;
    animation_sequences["RobotWalk_1"] = false;
    animation_sequences["RobotWalk_2"] = false;
    animation_sequences["RobotWalk_3"] = false;
    animation_sequences["RobotWalk_4"] = false;
    animation_sequences["RobotTurn90_1"] = false;
    animation_sequences["ShootLazer_1"] = false;
}

void PlaySequence(std::string seq_name)
{
    InitObjectsPosition();
    if (!animation_playing)
    {
        animation_sequences[seq_name] = true;
    }
}

// =============================================
// Init Functions
// =============================================

void InitObjectsPosition()
{
    InitSpawnables();
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
    lhand_fing_1_lower_rot = {0, 0, 0};
    lhand_fing_1_upper_rot = {0, 0, 0};
    clearProps(lhand_fing_2);
    lhand_fing_2_lower_rot = {0, 0, 0};
    lhand_fing_2_upper_rot = {0, 0, 0};
    clearProps(lhand_fing_3);
    lhand_fing_3_lower_rot = {0, 0, 0};
    lhand_fing_3_upper_rot = {0, 0, 0};
    clearProps(lhand_fing_4);
    lhand_fing_4_lower_rot = {0, 0, 0};
    lhand_fing_4_upper_rot = {0, 0, 0};
    clearProps(lhand_fing_5);
    lhand_fing_5_lower_rot = {0, 0, 0};
    lhand_fing_5_upper_rot = {0, 0, 0};
    clearProps(rhand_upper_joint);
    clearProps(rhand_arm);
    clearProps(rhand_upper_arm);
    clearProps(rhand_lower_arm);
    clearProps(rhand_palm);
    clearProps(rhand_fing_1);
    rhand_fing_1_lower_rot = {0, 0, 0};
    rhand_fing_1_upper_rot = {0, 0, 0};
    clearProps(rhand_fing_2);
    rhand_fing_2_lower_rot = {0, 0, 0};
    rhand_fing_2_upper_rot = {0, 0, 0};
    clearProps(rhand_fing_3);
    rhand_fing_3_lower_rot = {0, 0, 0};
    rhand_fing_3_upper_rot = {0, 0, 0};
    clearProps(rhand_fing_4);
    rhand_fing_4_lower_rot = {0, 0, 0};
    rhand_fing_4_upper_rot = {0, 0, 0};
    clearProps(rhand_fing_5);
    rhand_fing_5_lower_rot = {0, 0, 0};
    rhand_fing_5_upper_rot = {0, 0, 0};

    lhand_upper_joint.origin.y = -2.5;
    lhand_upper_joint.rot.z = 30;

    lhand_upper_arm.pos = {2.5, -4, 0};
    lhand_upper_arm.rot.x = 90;

    lhand_lower_arm.pos = {0, 0, 4};
    lhand_palm.pos = {0, 0, 4};

    lhand_fing_1.pos = {-1.1, 0, 2};
    lhand_fing_2.pos = {-0.4, 0, 2};
    lhand_fing_3.pos = {0.3, 0, 2};
    lhand_fing_4.pos = {1, 0, 2};
    lhand_fing_5.rot.y = 30;
    lhand_fing_5.pos = {1, 0, 2};
    lhand_fing_5_upper_rot.y = -30;
    lhand_shoulder_pad.pos = {1, 1, 0};
    lhand_shoulder_pad.scale = {1.3, 1.3, 1.3};
    lhand_shoulder_pad.rot = {-90, 0, -30};

    rhand_upper_joint.origin.y = -2.5;
    rhand_upper_joint.rot.z = -30;

    rhand_upper_arm.pos = {-2.5, -4, 0};
    rhand_upper_arm.rot.x = 90;

    rhand_lower_arm.pos = {0, 0, 4};
    rhand_palm.pos = {0, 0, 4};

    rhand_fing_1.pos = {-1.1, 0, 2};
    rhand_fing_2.pos = {-0.4, 0, 2};
    rhand_fing_3.pos = {0.3, 0, 2};
    rhand_fing_4.pos = {1, 0, 2};
    rhand_fing_5.rot.y = -30;
    rhand_fing_5.pos = {-1, 0, 2};
    rhand_fing_5_upper_rot.y = 30;
    rhand_shoulder_pad.pos = {-1, 1, 0};
    rhand_shoulder_pad.scale = {1.3, 1.3, 1.3};
    rhand_shoulder_pad.rot = {-90, 0, 30};
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
    LeftArmGrab_1();
    LeftArmGrab_2();
    LeftArmGrab_3();
    RobotWalk_1();
    RobotWalk_2();
    RobotWalk_3();
    RobotWalk_4();
    RobotTurn90_1();
    ShootLazer_1();
}

void LeftArmGrab_1()
{
    if (!animation_sequences["LeftArmGrab_1"])
    {
        return;
    }
    animation_playing = true;

    if (lhand_arm.rot.x > -30)
    {
        lhand_arm.rot.x--;
        lhand_lower_arm.rot.x--;
        lhand_palm.rot.x--;
    }

    if (lhand_arm.rot.x <= -30)
    {
        animation_sequences["LeftArmGrab_1"] = false;

        // Spawn a Sphere
        spawn_state["sphere"] = true;
        Prop3D spawn_sphere;
        spawn_sphere.scale = {0.5, 0.5, 0.5};
        spawn_sphere.pos = {4.5, 5, 3.5};
        spawnables_props["sphere"] = spawn_sphere;

        animation_sequences["LeftArmGrab_2"] = true;
    }
}

void LeftArmGrab_2()
{
    if (!animation_sequences["LeftArmGrab_2"])
    {
        return;
    }

    float target_pos = 1.5;

    if (spawnables_props["sphere"].pos.y > target_pos)
    {
        spawnables_props["sphere"].pos.y -= 0.05;
    }

    if (spawnables_props["sphere"].pos.y <= target_pos)
    {
        animation_sequences["LeftArmGrab_2"] = false;
        animation_sequences["LeftArmGrab_3"] = true;
    }
}

void LeftArmGrab_3()
{
    if (!animation_sequences["LeftArmGrab_3"])
    {
        return;
    }

    if (lhand_fing_1_lower_rot.x > -50)
    {
        lhand_fing_1_lower_rot.x--;
        lhand_fing_2_lower_rot.x--;
        lhand_fing_3_lower_rot.x--;
        lhand_fing_4_lower_rot.x--;
        lhand_fing_5_lower_rot.x--;
    }
    else
    {
        if (lhand_fing_1_upper_rot.x > -90)
        {
            lhand_fing_1_upper_rot.x--;
            lhand_fing_2_upper_rot.x--;
            lhand_fing_3_upper_rot.x--;
            lhand_fing_4_upper_rot.x--;
            lhand_fing_5_upper_rot.x--;
        }
    }

    if (lhand_fing_1_upper_rot.x <= -90)
    {
        animation_sequences["LeftArmGrab_3"] = false;
        animation_playing = false;
    }
}

void RobotWalk_1()
{
    if (!animation_sequences["RobotWalk_1"])
    {
        return;
    }

    animation_playing = true;

    if (lleg_upper_foot.rot.z > -45)
    {
        lleg_upper_foot.rot.z--;
        lleg_lower_leg.rot.z++;
    }

    if (lleg_upper_foot.rot.z <= -45)
    {
        animation_sequences["RobotWalk_1"] = false;
        animation_sequences["RobotWalk_2"] = true;
    }
}
void RobotWalk_2()
{
    if (!animation_sequences["RobotWalk_2"])
    {
        return;
    }

    if (lleg_upper_foot.rot.z <= 0)
    {
        MainRobotProps.pos.z += RobotFacing.z * 0.05;
        MainRobotProps.pos.x += RobotFacing.x * 0.05;
        lleg_upper_foot.rot.z++;
        lleg_lower_leg.rot.z--;
    }

    if (lleg_upper_foot.rot.z > 0)
    {
        animation_sequences["RobotWalk_2"] = false;
        animation_sequences["RobotWalk_3"] = true;
    }
}
void RobotWalk_3()
{
    if (!animation_sequences["RobotWalk_3"])
    {
        return;
    }

    if (rleg_upper_foot.rot.z > -45)
    {
        rleg_upper_foot.rot.z--;
        rleg_lower_leg.rot.z++;
    }

    if (rleg_upper_foot.rot.z <= -45)
    {
        animation_sequences["RobotWalk_3"] = false;
        animation_sequences["RobotWalk_4"] = true;
    }
}
void RobotWalk_4()
{
    if (!animation_sequences["RobotWalk_4"])
    {
        return;
    }

    if (rleg_upper_foot.rot.z <= 0)
    {
        MainRobotProps.pos.z += RobotFacing.z * 0.05;
        MainRobotProps.pos.x += RobotFacing.x * 0.05;
        rleg_upper_foot.rot.z++;
        rleg_lower_leg.rot.z--;
    }

    if (rleg_upper_foot.rot.z > 0)
    {
        animation_sequences["RobotWalk_4"] = false;
        animation_playing = false;
    }
}

int rotate_counter;
int turn_counter = 0;
void RobotTurn90_1()
{
    if (!animation_sequences["RobotTurn90_1"])
    {
        return;
    }
    animation_playing = true;

    Vec3f compass[4];
    compass[0] = {0, 0, 1};
    compass[1] = {1, 0, 0};
    compass[2] = {0, 0, -1};
    compass[3] = {-1, 0, 0};

    if ((rotate_counter % 91) < 90)
    {
        MainRobotProps.rot.y++;
        rotate_counter++;
    }

    if ((rotate_counter % 91) >= 90)
    {
        animation_sequences["RobotTurn90_1"] = false;
        rotate_counter = 0;
        turn_counter++;
        animation_playing = false;
        RobotFacing = compass[turn_counter % 4];
    }
}

void ShootLazer_1()
{
    if (!animation_sequences["ShootLazer_1"])
    {
        return;
    }
    spawnables_props["lazer"].scale = {0.1, 0.1, 0.1};
    spawnables_props["lazer"].pos.y = 15;
    animation_playing = true;
    spawn_state["lazer"] = true;
    if (spawnables_props["lazer"].pos.z < 1000)
    {
        spawnables_props["lazer"].pos.z += 10;
    }

    if (spawnables_props["lazer"].pos.z >= 1000)
    {
        animation_sequences["ShootLazer_1"] = false;
        animation_playing = false;
        spawn_state["lazer"] = false;
    }
}
// =============================================
// =============================================