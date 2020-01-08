#include "BlackBoard.h"

BlackBoard::BlackBoard()
{
}

BlackBoard::~BlackBoard()
{

}

void GameState::PrintGameState()
{
	std::cout << "Agent is Alive:            ";
	if (agentIsAlive == Condition::TRUE) std::cout << "YES\n";
	else if (agentIsAlive == Condition::FALSE) std::cout << "NO\n";
	else std::cout << "NVM\n";

	std::cout << "Agent Has Gun:             ";
	if (agentHasGun == Condition::TRUE) std::cout << "YES\n";
	else if (agentHasGun == Condition::FALSE) std::cout << "NO\n";
	else std::cout << "NVM\n";

	std::cout << "Weapon Reloaded:           ";
	if (weaponReloaded == Condition::TRUE) std::cout << "YES\n";
	else if (weaponReloaded == Condition::FALSE) std::cout << "NO\n";
	else std::cout << "NVM\n";

	std::cout << "Agent Has Bomb:            ";
	if (agentHasBomb == Condition::TRUE) std::cout << "YES\n";
	else if (agentHasBomb == Condition::FALSE) std::cout << "NO\n";
	else std::cout << "NVM\n";

	std::cout << "Enemy Is Visible:          ";
	if (enemyIsVisible == Condition::TRUE) std::cout << "YES\n";
	else if (enemyIsVisible == Condition::FALSE) std::cout << "NO\n";
	else std::cout << "NVM\n";

	std::cout << "Enemy Is Aligned:          ";
	if (enemyIsAligned == Condition::TRUE) std::cout << "YES\n";
	else if (enemyIsAligned == Condition::FALSE) std::cout << "NO\n";
	else std::cout << "NVM\n";

	std::cout << "Enemy Is Close:            ";
	if (enemyIsClose == Condition::TRUE) std::cout << "YES\n";
	else if (enemyIsClose == Condition::FALSE) std::cout << "NO\n";
	else std::cout << "NVM\n";

	std::cout << "Enemy Is Alive:            ";
	if (enemyIsAlive == Condition::TRUE) std::cout << "YES\n";
	else if (enemyIsAlive == Condition::FALSE) std::cout << "NO\n";
	else std::cout << "NVM\n";
}


SearchEnemy::SearchEnemy()
{
	actionName = "Search Enemy";

	preconditions = GameState(Condition::TRUE, Condition::NVM, Condition::NVM, Condition::NVM, Condition::FALSE, Condition::NVM, Condition::NVM, Condition::TRUE);
	effects = GameState(Condition::NVM, Condition::NVM, Condition::NVM, Condition::NVM, Condition::TRUE, Condition::NVM, Condition::NVM, Condition::NVM);
}

SearchWeapon::SearchWeapon()
{
	actionName = "Search Weapon";

	preconditions = GameState(Condition::TRUE, Condition::FALSE, Condition::NVM, Condition::NVM, Condition::NVM, Condition::NVM, Condition::NVM, Condition::NVM);
	effects = GameState(Condition::NVM, Condition::TRUE, Condition::NVM, Condition::NVM, Condition::NVM, Condition::NVM, Condition::NVM, Condition::NVM);
}

Chase::Chase()
{
	actionName = "Chase";

	preconditions = GameState(Condition::TRUE, Condition::TRUE, Condition::TRUE, Condition::NVM, Condition::TRUE, Condition::NVM, Condition::FALSE, Condition::TRUE);
	effects = GameState(Condition::NVM, Condition::NVM, Condition::NVM, Condition::NVM, Condition::NVM, Condition::NVM, Condition::TRUE, Condition::NVM);
}

Aim::Aim()
{
	actionName = "Aim";

	preconditions = GameState(Condition::TRUE, Condition::TRUE, Condition::TRUE, Condition::NVM, Condition::TRUE, Condition::FALSE, Condition::TRUE, Condition::TRUE);
	effects = GameState(Condition::NVM, Condition::NVM, Condition::NVM, Condition::NVM, Condition::NVM, Condition::TRUE, Condition::NVM, Condition::NVM);
}

Shoot::Shoot()
{
	actionName = "Shoot";

	preconditions = GameState(Condition::TRUE, Condition::TRUE, Condition::TRUE, Condition::NVM, Condition::TRUE, Condition::TRUE, Condition::TRUE, Condition::TRUE);
	effects = GameState(Condition::NVM, Condition::NVM, Condition::FALSE, Condition::NVM, Condition::FALSE, Condition::FALSE, Condition::FALSE, Condition::FALSE);
}

DetonateBomb::DetonateBomb()
{
	actionName = "Detonate Bomb";

	preconditions = GameState(Condition::TRUE, Condition::NVM, Condition::NVM, Condition::TRUE, Condition::NVM, Condition::NVM, Condition::TRUE, Condition::TRUE);
	effects = GameState(Condition::FALSE, Condition::NVM, Condition::NVM, Condition::FALSE, Condition::FALSE, Condition::FALSE, Condition::FALSE, Condition::FALSE);
}

Flee::Flee()
{
	actionName = "Flee";

	preconditions = GameState(Condition::TRUE, Condition::FALSE, Condition::NVM, Condition::NVM, Condition::TRUE, Condition::NVM, Condition::TRUE, Condition::TRUE);
	effects = GameState(Condition::NVM, Condition::NVM, Condition::NVM, Condition::NVM, Condition::FALSE, Condition::NVM, Condition::FALSE, Condition::NVM);
}