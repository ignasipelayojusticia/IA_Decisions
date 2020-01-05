#pragma once
#include "Agent.h"
#include "FSMState.h"
#include "WanderState.h"

class FSM : public Agent::DecisionMaking
{
private:
	FSMState* current_state;
	Agent* agent;
public:
	FSM(Agent* agent);
	~FSM();
	void Update(Agent* agent, float dtime);
	//void ChangeState(FSMState* new_state);
};