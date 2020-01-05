#pragma once
#include "Connection.h"

Connection::Connection() {

}

Connection::Connection(float _cost, int _nodeFrom, int _nodeTo) {
	cost = _cost;
	nodeFromID = _nodeFrom;
	nodeToID = _nodeTo;
}

Connection::~Connection() {

}