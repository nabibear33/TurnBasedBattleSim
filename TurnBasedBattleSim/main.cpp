#include <iostream>
#include <memory>

#include "Character.h"
#include "Monster.h"
#include "Player.h"
#include "Skill.h"


enum class ActionIdx
{
	USE_SKILL = 1,
	LEARN_SKILL
};


int main()
{
	std::cout << "Turn-based Battle Simulation\n\n";

	Player player(100, 100, 10);
	Monster monster(50, 50, 5);

	int turn = 0;
	while (true)
	{
		std::cout << "Turn " << turn << "\n";

		player.StatusEffectOnTurnStart();
		monster.StatusEffectOnTurnStart();

		std::cout << "Your Current HP: " << player.GetHp() << ", Monster Current HP: " << monster.GetHp() << "\n";
		std::cout << "Choose Your Action\n";
		std::cout << "1. Use Skill   2. Learn Skill\n";
		std::cout << "Your Action: ";

		int choiceActionRaw;
		std::cin >> choiceActionRaw;
		ActionIdx choiceAction = static_cast<ActionIdx>(choiceActionRaw);
		
		int choiceSkill;
		switch(choiceAction)
		{
		case ActionIdx::LEARN_SKILL:
			std::cout << "Choose Skill which you will learn\n";
			player.PrintAvailableSkills();
			std::cout << "Take Skill: ";

			std::cin >> choiceSkill;
			player.LearnSkill(choiceSkill);

			break;

		case ActionIdx::USE_SKILL:
			std::cout << "Choose Your Skill\n";
			player.PrintLearnedSkills();
			std::cout << "Activated Skill: ";

			std::cin >> choiceSkill;
			player.ActivateSkill(choiceSkill, player, monster);

			break;
		}


		if (monster.IsDead())
		{
			std::cout << "You Win!\n";
			break;
		}

		monster.ActivateSkill(0, monster, player);

		if (player.IsDead())
		{
			std::cout << "You Lose...\n";
			break;
		}
		
		turn = turn + 1;
	}
	
	return 0;
}