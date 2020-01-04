#pragma once
#include "FSM.h"
#include <iostream>

FSM::FSM(Agent* agent)
{
	std::cout << "created FSM" << std::endl;
	current_state = new WanderState(agent);
}

FSM::~FSM()
{

}

void FSM::Update(Agent* agent, float dtime)
{
	current_state->Update(agent, dtime);
}

void FSM::ChangeState(FSMState* new_state)
{
	std::cout << "Change state" << std::endl;
	delete current_state;
	current_state = new_state;
}