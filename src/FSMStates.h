#pragma once
#include "FSMState.h"

class WanderState : public FSMState
{
public:
	WanderState(Agent* agent);
	void ShowStateOnConsole();
	void Enter(Agent* agent);
	FSMState* Update(Agent* agent, float dt);
	void Exit(Agent* agent);
};

class ChaseState : public FSMState
{
public:
	ChaseState(Agent* agent);
	void ShowStateOnConsole();
	void Enter(Agent* agent);
	FSMState* Update(Agent* agent, float dt);
	void Exit(Agent* agent);
};

class FleeState : public FSMState
{
public:
	FleeState(Agent* agent);
	void ShowStateOnConsole();
	void Enter(Agent* agent);
	FSMState* Update(Agent* agent, float dt);
	void Exit(Agent* agent);
};