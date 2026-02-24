#include <iostream>

#include "Character.h"
#include "Monster.h"
#include "Player.h"
#include "Skill.h"


enum class Action
{
	ATTACK = 1
};


int main()
{
	std::cout << "Turn-based Battle Simulation\n\n";

	Player player(100, 10);
	Monster monster(50, 5);

	int turn = 0;
	while (true)
	{
		std::cout << "Turn " << turn << "\n";
		std::cout << "Your Current HP: " << player.GetHp() << ", Monster Current HP: " << monster.GetHp() << "\n";
		std::cout << "Choose Action\n";
		std::cout << "1. Attack\n";
		std::cout << "Your Action: ";

		int action_raw;
		std::cin >> action_raw;
		Action action = static_cast<Action>(action_raw);

		std::cout << "\n";

		switch (action)
		{
		case Action::ATTACK:
			monster.TakeDamage(player.GetAttackPower());
			break;
		}

		if (monster.IsDead())
		{
			std::cout << "You Win!\n";
			break;
		}

		player.TakeDamage(monster.GetAttackPower());

		if (player.IsDead())
		{
			std::cout << "You Lose...\n";
			break;
		}
		
		turn = turn + 1;
	}
	
	return 0;
}