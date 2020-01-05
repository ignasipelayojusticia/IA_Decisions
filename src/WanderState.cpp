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

FSMState* WanderState::Update(Agent* agent, float dt)
{
	if (agent->pathIsEmpty())
		followingEnemy = false;

	if (agent->getEnemy() != NULL)
	{
		Vector2D enemyPosition = agent->getEnemy()->getPosition();
		Vector2D agentPosition = agent->getPosition();

		draw_circle(TheApp::Instance()->getRenderer(), (int)agentPosition.x, (int)agentPosition.y, 150, 255, 255, 255, 255);

		if (Vector2D::Distance(enemyPosition, agent->getPosition()) < 150 && !followingEnemy && !agent->getEnemy()->getHasGun())
		{
			return new WanderState(agent);
			followingEnemy = true;
			agent->createPathToEnemy();
			std::cout << "path to enemy" << std::endl;
		}

		if (agent->getEnemy()->getHasGun())
		{

		}
	}

	if (agent->pathIsEmpty() && !followingEnemy)
		agent->createPathToRandomMazePoint();

	return NULL;
}

void WanderState::Exit(Agent* agent)
{

}