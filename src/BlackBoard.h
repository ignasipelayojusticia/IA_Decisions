#pragma once
#include <vector>
#include <iostream>

class BlackBoard
{
public:
	BlackBoard();
	~BlackBoard();

	//Getters & Setters of gameState
	void SetAgentIsAlive(bool);
	bool GetAgentIsAlive();
	void SetAgentHasGun(bool);
	bool GetAgentHasGun();
	void SetWeaponReloaded(bool);
	bool GetWeaponReloaded();
	void SetAgentHasBomb(bool);
	bool GetAgentHasBomb();
	void SetEnemyIsVisible(bool);
	bool GetEnemyIsVisible();
	void SetEnemyIsAligned(bool);
	bool GetEnemyIsAligned();
	void SetEnemyIsClose(bool);
	bool GetEnemyIsClose();
	void SetEnemyIsAlive(bool);
	bool GetEnemyIsAlive();

private:
	struct GameState
	{
		bool agentIsAlive;
		bool agentHasGun;
		bool weaponReloaded;
		bool agentHasBomb;
		bool enemyIsVisible;
		bool enemyIsAligned;
		bool enemyIsClose;
		bool enemyIsAlive;

		GameState()
		{
			agentIsAlive = agentHasGun = weaponReloaded = agentHasBomb = enemyIsVisible =
				enemyIsAligned = enemyIsClose = enemyIsAlive = false;
		}

		int convertBoolToBinary();
		int convertBinaryToInt(int);
	};

	class GOAPState
	{
	public:
		GOAPState() {};
		virtual void Enter(Agent* agent) = 0;
		virtual bool Update(Agent* agent, float dt) = 0;
		virtual void Exit(Agent* agent) = 0;
	};

	GameState gameState;
};