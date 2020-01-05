#pragma once
#include "FSMState.h"

class WanderState : public FSMState
{
public:
	WanderState(Agent* agent);
    void Enter(Agent* agent);
	FSMState* Update(Agent* agent, float dt);
	void Exit(Agent* agent);

private:
	bool followingEnemy;
};