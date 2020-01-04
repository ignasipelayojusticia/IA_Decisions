#pragma once
#include "Node.h"

Vector2D GetNodeCoords(int nodeID, int w)
{
	int x = nodeID % w;
	int y = (nodeID - x) / w;
	return Vector2D(x, y);
}

int GetNodeID(Vector2D nodeCoords, int w)
{
	return nodeCoords.x + nodeCoords.y * w;
}