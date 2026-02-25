#include <iostream>

#include "Character.h"
#include "Monster.h"
#include "Player.h"
#include "Skill.h"


int main()
{
	std::cout << "Turn-based Battle Simulation\n\n";

	Player player(100, 100, 10);
	Monster monster(50, 50, 5);

	int turn = 0;
	while (true)
	{
		std::cout << "Turn " << turn << "\n";
		std::cout << "Your Current HP: " << player.GetHp() << ", Monster Current HP: " << monster.GetHp() << "\n";
		std::cout << "Choose Your Skill\n";
		std::cout << "1. Basic Attack   2. Fireball   3. Heal\n";
		std::cout << "Activated Skill: ";

		int choiceSkillRaw;
		std::cin >> choiceSkillRaw;
		SkillIdx choiceSkill = static_cast<SkillIdx>(choiceSkillRaw - 1);

		std::cout << "\n";

		// player attacks first
		player.ActivateSkill(choiceSkill, player, monster);

		if (monster.IsDead())
		{
			std::cout << "You Win!\n";
			break;
		}

		// monster attack is always basic attack
		monster.ActivateSkill(SkillIdx::BASIC_ATTACK, monster, player);

		if (player.IsDead())
		{
			std::cout << "You Lose...\n";
			break;
		}
		
		turn = turn + 1;
	}
	
	return 0;
}