#pragma once
#include <iostream>
#include <minmax.h>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_SimpleApp.h"
#include "Path.h"
#include "Pathfinding.h"
#include "Graph.h"
#include "Vector2D.h"
#include "utils.h"
#include <cstdlib>

class Agent
{
public:
	class SteeringBehavior
	{
	public:
		SteeringBehavior() {};
		virtual ~SteeringBehavior() {};
		virtual void applySteeringForce(Agent *agent, float dtime) {};
	};
	
	class DecisionMaking
	{
	public:
		DecisionMaking() {};
		virtual ~DecisionMaking() {};
		virtual void Update(Agent* agent, float dtime) {};
	};

private:
	SteeringBehavior *steering_behaviour;
	Vector2D position;
	Vector2D velocity;
	Vector2D target;

	//Enemy
	Agent* enemy;
	bool hasGun;

	//Pathfinding
	Pathfinding* pathfinding_Algorithm;
	Graph* graph;
	int currentTargetIndex;
	Path path;
	Grid* grid;

	//Decision Making
	DecisionMaking* brain;

	float mass;
	float orientation;
	float max_force;
	float max_velocity;

	SDL_Texture *sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;

public:

	Agent();
	~Agent();
	Vector2D getPosition();
	Vector2D getTarget();
	Vector2D getVelocity();
	float getMaxVelocity();
	float getMaxForce();
	float getMass();
	void setBehavior(SteeringBehavior *behavior);
	void setPathFindingAlgorithm(Pathfinding *algorithm);
	void setPosition(Vector2D position);
	void setTarget(Vector2D target);
	void setVelocity(Vector2D velocity);
	void setGraph(Graph* graph);
	void setGrid(Grid* grid);
	void setDecisionMaking(DecisionMaking* decisionMaking);
	void setEnemy(Agent* agent);
	void setHasGun(bool hasGun);
	void addPathPoint(Vector2D point);
	void setCurrentTargetIndex(int idx);
	void calculatePath(int _initialNodeID, int _finalNodeID, Grid* grid);
	void calculatePath(int _finalNodeID);
	void calculateMultiplePath(int _initialNodeID, int _finalNodeID, std::vector<int> _vID, Grid* grid);
	void addEnemyCost(int _enemyPosID, Grid* grid);
	void addCostToNode(int _nodeID, float costToAdd);
	int getCurrentTargetIndex();
	int getPathSize();
	Graph* getGraph();
	Vector2D getPathPoint(int idx);
	int getRandomMazePoint();
	Agent* getEnemy();
	bool getHasGun();
	void createPathToRandomMazePoint();
	void clearPath();
	bool pathIsEmpty();
	void update(float dtime, SDL_Event *event);
	void draw();
	bool Agent::loadSpriteTexture(char* filename, int num_frames=1);	
};
