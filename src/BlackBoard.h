#pragma once
#include <vector>
#include <iostream>
#include <string>

enum class Condition { TRUE, FALSE, NVM };

class GameState
{
public:
	Condition agentIsAlive;
	Condition agentHasGun;
	Condition weaponReloaded;
	Condition agentHasBomb;
	Condition enemyIsVisible;
	Condition enemyIsAligned;
	Condition enemyIsClose;
	Condition enemyIsAlive;

	GameState()
	{
		agentIsAlive = enemyIsAlive = Condition::TRUE;

		agentHasGun = (Condition)(rand() % 2);
		weaponReloaded = (Condition)(rand() % 2);
		agentHasBomb = (Condition)(rand() % 2);
		enemyIsVisible = (Condition)(rand() % 2);
		enemyIsAligned = (Condition)(rand() % 2);
		enemyIsClose = (Condition)(rand() % 2);

		system("cls");
		std::cout << "---------------------------------------" << std::endl;
		PrintGameState();
		std::cout << "---------------------------------------" << std::endl;
	}

	GameState(Condition _agentIsAlive, Condition _agentHasGun, Condition _weaponReloaded, Condition _agentHasBomb, Condition _enemyIsVisible,
		Condition _enemyIsAligned, Condition _enemyIsClose, Condition _enemyIsAlive) : agentIsAlive(_agentIsAlive), agentHasGun(_agentHasGun),
		weaponReloaded(_weaponReloaded), agentHasBomb(_agentHasBomb), enemyIsVisible(_enemyIsVisible), enemyIsAligned(_enemyIsAligned),
		enemyIsClose(_enemyIsClose), enemyIsAlive(_enemyIsAlive)
	{}

	GameState(Condition condition)
	{

	}

	GameState operator + (GameState const& gS)
	{

	}

private:
	void PrintGameState();
};

class GOAPState
{
public:
	GOAPState() {};
	~GOAPState() {};
	std::string actionName;
	GameState preconditions;
	GameState effects;
};

class BlackBoard
{
public:
	BlackBoard();
	~BlackBoard();

private:
	GameState gameState;
	std::vector <GOAPState> GOAPStates;
};

class SearchEnemy : GOAPState
{
	SearchEnemy();
};

class SearchWeapon : GOAPState
{
	SearchWeapon();
};

class Chase : GOAPState
{
	Chase();
};

class Aim : GOAPState
{
	Aim();
};

class Shoot : GOAPState
{
	Shoot();
};

class Reload : GOAPState
{
	Reload();
};

class DetonateBomb : GOAPState
{
	DetonateBomb();
};

class Flee : GOAPState
{
	Flee();
};