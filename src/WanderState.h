#pragma once
#include "FSMState.h"

class WanderState : public FSMState
{
public:
	WanderState(Agent* agent);
	void Enter(Agent* agent);
	void Update(Agent* agent, float dt);
	void Exit(Agent* agent);
};