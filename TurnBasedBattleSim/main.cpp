#include <iostream>
#include <memory>

#include "Character.h"
#include "Monster.h"
#include "Player.h"
#include "Skill.h"
#include "Ui.h"


enum class ActionIdx
{
	USE_SKILL = 1,
	LEARN_SKILL
};


int main()
{
	std::cout << "Turn-based Battle Simulation\n\n";

	Ui ui;
	Player player("플레이어", 100, 5);
	Monster monster("몬스터1", 100, 5);

	int turn = 1;
	while (true)
	{
		std::cout << "---------------- Turn " << turn << " ----------------" << "\n";

		player.UpdateStatusEffects();
		monster.UpdateStatusEffects();

		std::cout << "Your Status: ";
		ui.PrintStatusEffects(player);
		std::cout << "Monster Status: ";
		ui.PrintStatusEffects(monster);
		std::cout << "\n";

		std::cout << "Your Current HP: " << player.GetHp() << ", Monster Current HP: " << monster.GetHp() << "\n\n";
		std::cout << "Choose Your Action\n";
		std::cout << "1. Use Skill   2. Learn Skill\n";
		std::cout << "Your Action: ";

		int choiceActionRaw;
		std::cin >> choiceActionRaw;
		ActionIdx choiceAction = static_cast<ActionIdx>(choiceActionRaw);
		
		std::cout << "\n";

		if (!player.GetIsStunned())
		{
			int choiceSkill;
			switch(choiceAction)
			{
			case ActionIdx::LEARN_SKILL:
				std::cout << "Choose Skill which you will learn\n";
				ui.PrintAvailableSkills(player);
				std::cout << "Take Skill: ";

				std::cin >> choiceSkill;
				player.LearnSkill(choiceSkill);

				break;

			case ActionIdx::USE_SKILL:
				std::cout << "Choose Your Skill\n";
				ui.PrintLearnedSkills(player);
				std::cout << "Activated Skill: ";

				std::cin >> choiceSkill;
				SkillInfo skillInfo = player.ActivateSkill(choiceSkill, player, monster);

				std::cout << "\n";

				ui.PrintSkillResult(skillInfo);

				break;
			}
		}
		else
		{
			std::cout << "Player Get Stunned... Pass the turn\n";
		}


		if (monster.IsDead())
		{
			std::cout << "You Win!\n";
			break;
		}

		if (!monster.GetIsStunned())
		{
			SkillInfo skillInfo = monster.ActivateSkill(0, monster, player);

			std::cout << "\n";

			ui.PrintSkillResult(skillInfo);
		}
		else
		{
			std::cout << "Monster Get Stunned!\n";
		}


		if (player.IsDead())
		{
			std::cout << "You Lose...\n";
			break;
		}
		
		turn = turn + 1;
		std::cout << "\n";
	}
	
	return 0;
}