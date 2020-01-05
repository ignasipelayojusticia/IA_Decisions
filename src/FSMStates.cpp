#include "FSMStates.h"
#include "Agent.h"
#include <iostream>

//WANDER -------------------------------------------------------------------------------------------------------------------------------------

WanderState::WanderState(Agent* agent)
{
	Enter(agent);
}

void WanderState::ShowStateOnConsole()
{
	std::cout << "Player State: Wander" << std::endl;
}

void WanderState::Enter(Agent* agent)
{
	if (agent->getEnemy() != NULL)
	{
		system("cls");
		ShowStateOnConsole();
		if (agent->getEnemy()->getHasGun())
			std::cout << "Enemy has gun" << std::endl;
		else
			std::cout << "Enemy doesn't have gun" << std::endl;
	}
}

FSMState* WanderState::Update(Agent* agent, float dt)
{
	if (agent->getEnemy() != NULL)
	{
		Vector2D enemyPosition = agent->getEnemy()->getPosition();
		Vector2D agentPosition = agent->getPosition();

		draw_circle(TheApp::Instance()->getRenderer(), (int)agentPosition.x, (int)agentPosition.y, 150, 255, 255, 255, 255);

		if (Vector2D::Distance(enemyPosition, agent->getPosition()) < 150)
			return new ChaseState(agent);
	}

	if (agent->pathIsEmpty())
		agent->createPathToRandomMazePoint();

	return NULL;
}

void WanderState::Exit(Agent* agent) {}

 //CHASE -------------------------------------------------------------------------------------------------------------------------------------

ChaseState::ChaseState(Agent* agent)
{
	Enter(agent);
}

void ChaseState::ShowStateOnConsole()
{
	std::cout << "Player State: Chase" << std::endl;
}

void ChaseState::Enter(Agent* agent)
{
	system("cls");
	ShowStateOnConsole();
	if (agent->getEnemy()->getHasGun())
		std::cout << "Enemy has gun" << std::endl;
	else
		std::cout << "Enemy doesn't have gun" << std::endl;

	agent->createPathToEnemy();
}

FSMState* ChaseState::Update(Agent* agent, float dt)
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)agent->getPosition().x, (int)agent->getPosition().y, 150, 0, 255, 0, 255);

	float distanceToEnemy = Vector2D::Distance(agent->getEnemy()->getPosition(), agent->getPosition());

	if (agent->getEnemy()->getHasGun())
		return new FleeState(agent);

	if (agent->pathIsEmpty() && distanceToEnemy < 150)
	{
		agent->createPathToEnemy();

		return NULL;
	}
	else if (agent->pathIsEmpty() && distanceToEnemy > 150)
		return new WanderState(agent);
}

void ChaseState::Exit(Agent* agent) {}

 //FLEE  -------------------------------------------------------------------------------------------------------------------------------------

FleeState::FleeState(Agent* agent)
{
	Enter(agent);
}

void FleeState::ShowStateOnConsole()
{
	std::cout << "Player State: Flee" << std::endl;
}

void FleeState::Enter(Agent* agent)
{
	system("cls");
	ShowStateOnConsole();
	if (agent->getEnemy()->getHasGun())
		std::cout << "Enemy has gun" << std::endl;
	else
		std::cout << "Enemy doesn't have gun" << std::endl;

	agent->clearPath();
}

FSMState* FleeState::Update(Agent* agent, float dt)
{
	draw_circle(TheApp::Instance()->getRenderer(), (int)agent->getPosition().x, (int)agent->getPosition().y, 200, 255, 0, 0, 255);

	float distanceToEnemy = Vector2D::Distance(agent->getEnemy()->getPosition(), agent->getPosition());

	if (!agent->getEnemy()->getHasGun() && distanceToEnemy < 200)
	{
		return new ChaseState(agent);
	}
	else if (distanceToEnemy > 150)
		return new WanderState(agent);

	if (agent->pathIsEmpty())
		agent->createPathFleeingEnemy();

	return NULL;
}

void FleeState::Exit(Agent* agent) {}