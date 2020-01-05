#pragma once
#include "FSM.h"
#include <iostream>

FSM::FSM(Agent* _agent)
{
	std::cout << "created FSM" << std::endl;
	agent = _agent;
	current_state = new WanderState(agent);
}

FSM::~FSM()
{

}

void FSM::Update(Agent* agent, float dtime)
{
	current_state->Update(agent, dtime);
		//std::cout << "no change" << std::endl;
}

//void FSM::ChangeState(FSMState* new_state)
//{
//	std::cout << "Change state" << std::endl;
//	current_state->Exit(agent);
//	delete current_state;
//	current_state = new_state;
//}