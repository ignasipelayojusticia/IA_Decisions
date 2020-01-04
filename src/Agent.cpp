#include "Agent.h"

using namespace std;

Agent::Agent() : sprite_texture(0),
                 position(Vector2D(100, 100)),
	             target(Vector2D(1000, 100)),
	             velocity(Vector2D(0,0)),
	             currentTargetIndex(-1),
				 mass(0.1f),
				 max_force(150),
				 max_velocity(200),
				 orientation(0),
				 sprite_num_frames(0),
	             sprite_w(0),
	             sprite_h(0),
	             draw_sprite(false)
{
}

Agent::~Agent()
{
	if (sprite_texture)
		SDL_DestroyTexture(sprite_texture);
	if (steering_behaviour)
		delete (steering_behaviour);
}

void Agent::setBehavior(SteeringBehavior *behavior)
{
	steering_behaviour = behavior;
}

void Agent::setPathFindingAlgorithm(Pathfinding * algorithm)
{
	pathfinding_Algorithm = algorithm;
}

Vector2D Agent::getPosition()
{
	return position;
}

Vector2D Agent::getTarget()
{
	return target;
}

Vector2D Agent::getVelocity()
{
	return velocity;
}

float Agent::getMaxVelocity()
{
	return max_velocity;
}

float Agent::getMaxForce()
{
	return max_force;
}

float Agent::getMass()
{
	return mass;
}

void Agent::setPosition(Vector2D _position)
{
	position = _position;
}

void Agent::setTarget(Vector2D _target)
{
	target = _target;
}

void Agent::setVelocity(Vector2D _velocity)
{
	velocity = _velocity;
}

void Agent::setGraph(Graph* _graph) {
	graph = _graph;
}

void Agent::setGrid(Grid* _grid)
{
	grid = _grid;
}

void Agent::setDecisionMaking(DecisionMaking* decisionMaking)
{
	brain = decisionMaking;
}

void Agent::setHasGun(bool _hasGun)
{
	hasGun = _hasGun;
}

void Agent::update(float dtime, SDL_Event *event)
{
	//cout << "agent update:" << endl;

	switch (event->type) {
		/* Keyboard & Mouse events */
	case SDL_KEYDOWN:
		if (event->key.keysym.scancode == SDL_SCANCODE_SPACE)
			draw_sprite = !draw_sprite;
		break;
	default:
		break;
	}

	// Apply the steering behavior
	steering_behaviour->applySteeringForce(this, dtime);

	//Apply decision making algorithm
	brain->Update(this, dtime);
	
	// Update orientation
	if (velocity.Length())
		orientation = (float)(atan2(velocity.y, velocity.x) * RAD2DEG);

	// Trim position values to window size
	if (position.x < 0) position.x = TheApp::Instance()->getWinSize().x;
	if (position.y < 0) position.y = TheApp::Instance()->getWinSize().y;
	if (position.x > TheApp::Instance()->getWinSize().x) position.x = 0;
	if (position.y > TheApp::Instance()->getWinSize().y) position.y = 0;
}


void Agent::addPathPoint(Vector2D point)
{
	if (path.points.size() > 0)
		if (path.points[path.points.size() - 1] == point)
			return;

	path.points.push_back(point);
}


int Agent::getCurrentTargetIndex()
{
	return currentTargetIndex;
}

int Agent::getPathSize()
{
	return path.points.size();
}

Graph* Agent::getGraph() {
	return graph;
}

Vector2D Agent::getPathPoint(int idx)
{
	return path.points[idx];
}

int Agent::getRandomMazePoint()
{
	auto it = graph->map.begin();
	std::advance(it, rand() % graph->map.size());
	int newMazePoint = it->first;
	return newMazePoint;
}

Agent* Agent::getEnemy()
{
	return enemy;
}

bool Agent::getHasGun()
{
	return hasGun;
}

void Agent::createPathToRandomMazePoint()
{
	calculatePath(getRandomMazePoint());
}

void Agent::clearPath()
{
	setCurrentTargetIndex(-1);
	path.points.clear();
}

void Agent::setCurrentTargetIndex(int idx)
{
	currentTargetIndex = idx;
}

void Agent::setEnemy(Agent* agent)
{
	enemy = agent;
}

void Agent::calculatePath(int _initialNodeID, int _finalNodeID, Grid* _grid)
{
	clearPath();
	path = pathfinding_Algorithm->calculatePath(_initialNodeID, _finalNodeID, graph, _grid);
}

void Agent::calculatePath(int _finalNodeID)
{
	clearPath();
	int initialNodeID = GetNodeID(grid->pix2cell(getPosition()), graph->w);
	path = pathfinding_Algorithm->calculatePath(initialNodeID, _finalNodeID, graph, grid);
}

void Agent::calculateMultiplePath(int _initialNodeID, int _finalNodeID, std::vector<int> _vID, Grid* grid) 
{
	clearPath();
	path = pathfinding_Algorithm->calculateMultiplePath(_initialNodeID, _finalNodeID, _vID, graph, grid);
}

bool Agent::pathIsEmpty()
{
	return path.points.size() == 0;
}

void Agent::addEnemyCost(int _enemyPosID, Grid* grid)
{
	//Afegim el cost al node on està l'enemic amb un cost molt alt
	addCostToNode(_enemyPosID, 200);
	auto it = graph->map.find(_enemyPosID);
	if (it != graph->map.end())
	{
		for each (Connection* connection in it->second)
		{
			auto it2 = graph->map.find(it->first);
			for each (Connection* childConnection in it2->second)
			{
				//Expandim la frontera del cost als veins més llunyans
				addCostToNode(childConnection->nodeToID, 5);
			}
			//Expandim la frontera del cost als veins mes propers
			addCostToNode(connection->nodeToID, 10);
		}
	}

	if (path.points.size() > 0) // Estem recorrent un path
	{
		calculatePath( GetNodeID(grid->pix2cell(getPosition()), graph->w) , GetNodeID(grid->pix2cell(path.points[path.points.size()-1]), graph->w), grid);
	}
}

void Agent::addCostToNode(int _nodeID, float costToAdd)
{
	auto it = graph->map.find(_nodeID);
	if (it != graph->map.end())
	{
		for each (Connection * c in it->second)
		{
			auto it2 = graph->map.find(c->nodeToID);
			for each (Connection * c2 in it2->second)
			{
				if (c2->nodeToID == _nodeID)
				{
					c2->cost *= costToAdd;
					break;
				}
			}
		}
	}
}

void Agent::draw()
{
	// Path
	
	/*for (int i = 0; i < (int)path.points.size(); i++)
	{
		draw_circle(TheApp::Instance()->getRenderer(), (int)(path.points[i].x), (int)(path.points[i].y), 15, 255, 255, 0, 255);
		if (i > 0)
			SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), (int)(path.points[i - 1].x), (int)(path.points[i - 1].y), (int)(path.points[i].x), (int)(path.points[i].y));
	}*/

	if (draw_sprite)
	{
		Uint32 sprite;
		
		if (velocity.Length() < 5.0)
			sprite = 1;
		else
			sprite = (int)(SDL_GetTicks() / (-0.1*velocity.Length() + 250)) % sprite_num_frames;
		
		SDL_Rect srcrect = { (int)sprite * sprite_w, 0, sprite_w, sprite_h };
		SDL_Rect dstrect = { (int)position.x - (sprite_w / 2), (int)position.y - (sprite_h / 2), sprite_w, sprite_h };
		SDL_Point center = { sprite_w / 2, sprite_h / 2 };
		SDL_RenderCopyEx(TheApp::Instance()->getRenderer(), sprite_texture, &srcrect, &dstrect, orientation+90, &center, SDL_FLIP_NONE);
	}
	else 
	{
		draw_circle(TheApp::Instance()->getRenderer(), (int)position.x, (int)position.y, 15, 255, 255, 255, 255);
		SDL_RenderDrawLine(TheApp::Instance()->getRenderer(), (int)position.x, (int)position.y, (int)(position.x+15*cos(orientation*DEG2RAD)), (int)(position.y+15*sin(orientation*DEG2RAD)));
	}
}

bool Agent::loadSpriteTexture(char* filename, int _num_frames)
{
	if (_num_frames < 1) return false;

	SDL_Surface *image = IMG_Load(filename);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	sprite_texture = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	sprite_num_frames = _num_frames;
	sprite_w = image->w / sprite_num_frames;
	sprite_h = image->h;
	draw_sprite = true;

	if (image)
		SDL_FreeSurface(image);

	return true;
}
