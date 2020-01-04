#include "AStar.h"

AStar::AStar()
{
}

AStar::~AStar()
{
}

Path AStar::calculatePath(int _initialNodeID, int _finalNodeID, Graph * graph, Grid* grid)
{
	int nodesExplored = 0;
	float pathCost = 0;

	Path tempPath;

	std::vector<std::pair<int, float>> frontier; // Creem la frontera
	frontier.push_back(std::pair<int, float>(_initialNodeID, 0)); // Li afegim el node inicial

	std::map<int, int> cameFrom;		// Ens creem un map per guardar de quin node venim
	cameFrom[_initialNodeID] = NULL;

	std::map<int, float> costSoFar;		// Ens creem un map per guardar el cost acumulat
	costSoFar[_initialNodeID] = 0;


	bool earlyExit = false;


	while (frontier.size() > 0 && !earlyExit)			// Recorrem la frontera dins que es buidi
	{
		nodesExplored++;

		std::sort(frontier.begin(), frontier.end(), [](auto &left, auto &right) { // Ordenem la frontera per cost
			return left.second < right.second;
		});

		std::pair<int, float> current = frontier.front();			// Agafem el primer node de la frontera

		if (current.first == _finalNodeID) // Si trobem el node al que volem arribar fem early exit
		{
			earlyExit = true;
			break;
		}

		for each (Connection* con in graph->map[current.first])	// Recorrem les seves connexions
		{
			auto it = cameFrom.find(con->nodeToID);				// Busquem si hem explorat el node abans

			float new_cost = costSoFar[current.first] + con->cost;	// Calculem el cost so far per aquell node
			float heuristic = calculateHeuristic(con->nodeToID, _finalNodeID, graph->w);

			if (it == cameFrom.end())							// Si no hem explorat aquell node abans
			{
				costSoFar[con->nodeToID] = new_cost;		// Assignem el nou cost so far
				frontier.push_back(std::pair<int, float>(con->nodeToID, new_cost + heuristic));	// Posem el node a la frontera
				cameFrom[con->nodeToID] = current.first;	// Assignem de quin node prové el nou node
			}
			else if (new_cost < costSoFar[con->nodeToID])		// Si ja l'hem explorat però trobem un camí més curt
			{
				costSoFar[con->nodeToID] = new_cost;	// Assignem el nou cost so far
				auto it2 = std::find_if(frontier.begin(), frontier.end() - 1,
					[&con](const std::pair<int, float>& element) { return element.first == con->nodeToID; }); // Busquem el node de la frontera antic
				frontier.erase(it2);	// Esborrem el node antic que té un cost més elevat
				frontier.push_back(std::pair<int, float>(con->nodeToID, new_cost + heuristic)); // Posem el node a la frontera amb el cost actualitzat
				cameFrom[con->nodeToID] = current.first; // Assignem de quin node prové el nou node
			}


		}

		frontier.erase(frontier.begin()); // Treiem el node que acabem de explorar
	}

	if (earlyExit) // Si hem trobat el node final
	{
		int current = _finalNodeID;
		pathCost = costSoFar[_finalNodeID];

		while (current != NULL)
		{
			tempPath.points.insert(tempPath.points.begin(), grid->cell2pix(GetNodeCoords(current, graph->w)));
			current = cameFrom[current];
		}
	}
	else
		tempPath.points.push_back(grid->cell2pix(GetNodeCoords(_initialNodeID, graph->w)));

	return tempPath;
}

float AStar::calculateHeuristic(int _currentNodeID, int _finalNodeID, int w)
{
	return Vector2D::Distance(GetNodeCoords(_currentNodeID, w), GetNodeCoords(_finalNodeID, w));
}