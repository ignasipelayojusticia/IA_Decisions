#pragma once
#include "Vector2D.h"
#include "Path.h"

class Agent;

class FSMState
{
public:
	FSMState() {}
	virtual void ShowStateOnConsole() = 0;
	virtual void Enter(Agent* agent) = 0;
	virtual FSMState* Update(Agent* agent, float dt) = 0;
	virtual void Exit(Agent* agent) = 0;
};