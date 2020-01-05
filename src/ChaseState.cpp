#include "ChaseState.h"
#include "WanderState.h"
#include <iostream>
#include "Agent.h"

ChaseState::ChaseState(Agent* agent)
{
	Enter(agent);
}

void ChaseState::Enter(Agent* agent)
{
	std::cout << "Chase enter" << std::endl;

	agent->createPathToEnemy();
}

FSMState* ChaseState::Update(Agent* agent, float dt)
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)agent->getPosition().x, (int)agent->getPosition().y, 150, 255, 0, 0, 255);

	float distanceToEnemy = Vector2D::Distance(agent->getEnemy()->getPosition(), agent->getPosition());

	if (agent->pathIsEmpty() &&  distanceToEnemy < 150)
	{
		agent->createPathToEnemy();
		return NULL;
	}
	else if(agent->pathIsEmpty() && distanceToEnemy > 150)
		return new WanderState(agent);

}

void ChaseState::Exit(Agent* agent)
{

}