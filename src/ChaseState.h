#pragma once
#include "FSMState.h"

class ChaseState : public FSMState
{
public:
	ChaseState(Agent* agent);
	void Enter(Agent* agent);
	FSMState* Update(Agent* agent, float dt);
	void Exit(Agent* agent);
};