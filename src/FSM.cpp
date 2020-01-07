#pragma once
#include "FSM.h"
#include <iostream>

FSM::FSM(Agent* agent)
{
	current_state = new WanderState(agent);
}

FSM::~FSM()
{
	delete current_state;
}

void FSM::Update(Agent* agent, float dtime)
{
	ChangeState(current_state->Update(agent, dtime));
}

void FSM::ChangeState(FSMState* new_state)
{
	if (new_state == NULL)
		return;

	delete current_state;
	current_state = new_state;
}