#include "WanderState.h"
#include <iostream>

WanderState::WanderState(Agent* agent)
{
	Enter(agent);
}

void WanderState::Enter(Agent* agent)
{
	std::cout << "Wander enter" << std::endl;
}

void WanderState::Update(Agent* agent, float dt)
{
	std::cout << "Wander update" << std::endl;
}

void WanderState::Exit(Agent* agent)
{

}