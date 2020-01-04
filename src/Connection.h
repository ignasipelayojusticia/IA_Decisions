#pragma once
#include "Node.h"

class Connection {
public:
	Connection();
	Connection(float cost, int nodeFrom, int nodeTo);
	~Connection();
	float cost;
	int nodeFromID;
	int nodeToID;
};