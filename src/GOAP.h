#pragma once
#include "Agent.h"

class GOAP : public Agent::DecisionMaking
{
public:
	GOAP(Agent* agent);
	~GOAP();
	void Update(Agent* agent, float dtime);
};
