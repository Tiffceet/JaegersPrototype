#ifndef _ANIMATION_H_
#define _ANIMATION_H_
#include <iostream>
#include "typedefs.h"
extern Prop3D MainRobotProps;
extern bool animation_playing;
void InitObjectsPosition();
void InitAnimationSequencesState();
void PlaySequence(std::string seq_name);
void InitLeftHandPosition();
void ProcessAnimation();
void LeftArmGrab_1();
void LeftArmGrab_2();
void LeftArmGrab_3();
void RobotWalk_1();
void RobotWalk_2();
void RobotWalk_3();
void RobotWalk_4();
void InitLegPosition();
#endif