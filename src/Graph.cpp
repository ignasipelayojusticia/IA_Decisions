#pragma once
#include <iostream>
#include "Graph.h"

Graph::Graph() {

}

Graph::Graph(Grid* grid) {
	map.clear();
	w = grid->getNumCellX();

	for (int i = 0; i < grid->getNumCellY(); i++)
	{
		for (int j = 0; j < grid->getNumCellX(); j++)
		{
			if (grid->isValidCell(Vector2D(j, i))) //Si la meva posició és vàlida
			{
				float cellKey = GetNodeID(Vector2D(j, i), w);
				map.insert(std::pair<int,std::vector<Connection*>>(cellKey, std::vector<Connection*>())); //Insertem el node al map amb les connexions buides

				//Comprovem les seves conexions circundants
				//Adjacent superior
				if (grid->isValidCell(Vector2D(j, i - 1)))
					map[cellKey].push_back(new Connection(1, cellKey, GetNodeID(Vector2D(j, i - 1), w)));

				//Adjacent inferior
				if (grid->isValidCell(Vector2D(j, i + 1)))
					map[cellKey].push_back(new Connection(1, cellKey, GetNodeID(Vector2D(j, i + 1), w)));

				//Adjacent esquerra
				if (grid->isValidCell(Vector2D(j - 1, i)))
					map[cellKey].push_back(new Connection(1, cellKey, GetNodeID(Vector2D(j - 1, i), w)));

				//Adjacent dreta
				if (grid->isValidCell(Vector2D(j + 1, i)))
					map[cellKey].push_back(new Connection(1, cellKey, GetNodeID(Vector2D(j + 1, i), w)));

				//Cantonada superior esquerra
				if (grid->isValidCell(Vector2D(j - 1, i - 1)))
					map[cellKey].push_back(new Connection(std::sqrt(2), cellKey, GetNodeID(Vector2D(j - 1, i - 1), w)));

				//Cantonada superior dreta
				if (grid->isValidCell(Vector2D(j + 1, i - 1)))
					map[cellKey].push_back(new Connection(std::sqrt(2), cellKey, GetNodeID(Vector2D(j + 1, i - 1), w)));

				//Cantonada inferior esquerra
				if (grid->isValidCell(Vector2D(j - 1, i + 1)))
					map[cellKey].push_back(new Connection(std::sqrt(2), cellKey, GetNodeID(Vector2D(j - 1, i + 1), w)));

				//Cantonada inferior dreta
				if (grid->isValidCell(Vector2D(j + 1, i + 1)))
					map[cellKey].push_back(new Connection(std::sqrt(2), cellKey, GetNodeID(Vector2D(j + 1, i + 1), w)));
			}
		}
	}
}

Graph::~Graph() {

}