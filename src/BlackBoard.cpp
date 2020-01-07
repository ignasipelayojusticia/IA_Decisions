#include "BlackBoard.h"

BlackBoard::BlackBoard()
{
	std::cout << gameState.convertIntToBinary(10) << std::flush << std::endl;
}

BlackBoard::~BlackBoard()
{

}

void BlackBoard::SetAgentIsAlive(bool value)
{
	gameState.agentIsAlive = value;
}

bool BlackBoard::GetAgentIsAlive()
{
	return gameState.agentIsAlive;
}

void BlackBoard::SetAgentHasGun(bool value)
{
	gameState.agentHasGun = value;
}

bool BlackBoard::GetAgentHasGun()
{
	return gameState.agentHasGun;
}

void BlackBoard::SetWeaponReloaded(bool value)
{
	gameState.weaponReloaded = value;
}

bool BlackBoard::GetWeaponReloaded()
{
	return gameState.weaponReloaded;
}

void BlackBoard::SetAgentHasBomb(bool value)
{
	gameState.agentHasBomb = value;
}

bool BlackBoard::GetAgentHasBomb()
{
	return gameState.agentHasBomb;
}

void BlackBoard::SetEnemyIsVisible(bool value)
{
	gameState.enemyIsVisible = value;
}

bool BlackBoard::GetEnemyIsVisible()
{
	return gameState.enemyIsVisible;
}

void BlackBoard::SetEnemyIsAligned(bool value)
{
	gameState.enemyIsAligned = value;
}

bool BlackBoard::GetEnemyIsAligned()
{
	return gameState.enemyIsAligned;
}

void BlackBoard::SetEnemyIsClose(bool value)
{
	gameState.enemyIsClose = value;
}

bool BlackBoard::GetEnemyIsClose()
{
	return gameState.enemyIsClose;
}

void BlackBoard::SetEnemyIsAlive(bool value)
{
	gameState.agentIsAlive = value;
}

bool BlackBoard::GetEnemyIsAlive()
{
	return gameState.enemyIsAlive;
}

int BlackBoard::GameState::convertBoolToBinary()
{
	int currentGameState[8];
	currentGameState[0] = agentIsAlive;
	currentGameState[1] = agentHasGun * 10;
	currentGameState[2] = weaponReloaded * 100;
	currentGameState[3] = agentHasBomb * 1000;
	currentGameState[4] = enemyIsVisible * 10000;
	currentGameState[5] = enemyIsAligned * 100000;
	currentGameState[6] = enemyIsClose * 10000000;
	currentGameState[7] = enemyIsAlive * 100000000;

	int totalBinary = 0;

	for (int i = 0; i < 8; i++)
		totalBinary += currentGameState[i];

	return totalBinary;
}

int BlackBoard::GameState::convertBinaryToInt(int binary)
{
	int binaryNumber = binary;
	int decValue = 0;

	int base = 1;

	int temp = binaryNumber;
	while (temp)
	{
		int lastDigit = temp % 10;
		temp = temp / 10;

		decValue += lastDigit * base;
		base = base * 2;
	}
	return decValue;
}

