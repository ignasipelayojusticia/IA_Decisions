#pragma once
#include "Path.h"
#include "Graph.h"


class Pathfinding
{
public:
	Pathfinding() {};
	virtual ~Pathfinding() {};

	virtual Path calculatePath(int _initialNodeID, int _finalNodeID, Graph* graph, Grid* grid) { return Path(); };
	virtual Path calculateMultiplePath(int _initialNodeID, int _finalNodeID, std::vector<int> _VID, Graph* graph, Grid* grid) { return Path(); };
};