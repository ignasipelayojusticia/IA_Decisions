#include "WanderState.h"
#include <iostream>
#include "Agent.h"

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
	if (agent->pathIsEmpty())
		agent->createPathToRandomMazePoint();
}

void WanderState::Exit(Agent* agent)
{

}