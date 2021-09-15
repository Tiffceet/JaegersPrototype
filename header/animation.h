#ifndef _ANIMATION_H_
#define _ANIMATION_H_
#include <iostream>
extern bool _state_LeftArmGrab;
void InitObjectsPosition();
void InitAnimationSequencesState();
void PlaySequence(std::string seq_name);
void InitLeftHandPosition();
void ProcessAnimation();
void LeftArmGrab();
#endif