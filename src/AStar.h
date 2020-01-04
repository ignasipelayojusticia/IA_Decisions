#pragma once
#include <vector>
#include <algorithm>
#include <map>
#include "Pathfinding.h"


class AStar : public Pathfinding {
public:
	AStar();
	~AStar();

	Path calculatePath(int _initialNodeID, int _finalNodeID, Graph* graph, Grid* grid) override;
	float calculateHeuristic(int _currentNodeID, int _finalNodeID, int w);
};