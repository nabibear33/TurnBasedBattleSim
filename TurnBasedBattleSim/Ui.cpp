#include <iostream>

#include "Ui.h"
#include "Character.h"


void Ui::PrintSkillResult(const SkillInfo& result)
{
    switch (result.type) {
    case SkillType::DAMAGE:
        std::cout << result.casterName << "이(가) " << result.targetName
			<< "에게 " << result.value << ((result.isCritical) ? " 크리티컬" : "") << " 데미지!\n";
        break;
    case SkillType::HEAL:
        std::cout << result.casterName << "이(가) "
            << (result.casterName == result.targetName ? "자신을" : result.targetName + "을")
            << " " << result.value << " 회복!\n";
        break;
    }
}


void Ui::PrintAvailableSkills(const Character& user)
{
	const std::vector<std::unique_ptr<Skill>>& availableSkills = user.GetAvailableSkills();
	for (int i = 0; i < availableSkills.size(); i++)
	{
		std::cout << i << ". " << availableSkills[i]->GetName() << "    ";
	}
	std::cout << "\n";
}


void Ui::PrintLearnedSkills(const Character& user)
{
	const std::vector<std::unique_ptr<Skill>>& learnedSkills = user.GetLearnedSkills();
	for (int i = 0; i < learnedSkills.size(); i++)
	{
		std::cout << i << ". " << learnedSkills[i]->GetName() << "    ";
	}
	std::cout << "\n";
}


void Ui::PrintStatusEffects(const Character& user)
{
	const std::vector<std::unique_ptr<StatusEffect>>& statusEffects = user.GetStatusEffects();
	for (int i = 0; i < statusEffects.size(); i++)
	{
		int turns = statusEffects[i]->GetRemainingTurns();
		std::string plural = (turns > 1) ? "s" : "";
		std::cout << statusEffects[i]->GetName() << "(left " << turns << " turn" << plural << ")" << "    ";
	}
	std::cout << "\n";
}