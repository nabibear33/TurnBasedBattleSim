#include <algorithm>
#include <iostream>

#include "Character.h"


Character::Character(int maxHp_, int hp_, int attackPower_) : maxHp(maxHp_), hp(hp_), attackPower(attackPower_) {}
Character::~Character() {}

int Character::GetHp()
{
	return hp;
}

int Character::GetAttackPower()
{
	return attackPower;
}


void Character::TakeDamage(int dmg)
{
	hp = std::max(hp - dmg, 0);
}


void Character::RestoreHp(int amt)
{
	hp = std::min(hp + amt, maxHp);
}


void Character::LearnSkill(int choice)
{
	learnedSkills.push_back(std::move(availableSkills[choice]));
	availableSkills.erase(availableSkills.begin() + choice);
}


bool Character::IsDead()
{
	return hp <= 0;
}


void Character::ActivateSkill(int choice, Character& user, Character& target)
{
	Skill* selectedSkill = learnedSkills[choice].get();
	selectedSkill->Activate(user, target);
}


void Character::SetAvailableSkills(std::unique_ptr<Skill> skill)
{
	availableSkills.push_back(std::move(skill));
}


void Character::SetLearnedSkills(std::unique_ptr<Skill> skill)
{
	learnedSkills.push_back(std::move(skill));
}


void Character::AddStatusEffect(std::unique_ptr<StatusEffect> statusEffect)
{
	statusEffect->Apply(*this);
	statusEffects.push_back(std::move(statusEffect));
}


void Character::PrintAvailableSkills()
{
	for (int i = 0; i < availableSkills.size(); i++)
	{
		std::cout << i << ". " << availableSkills[i]->GetName() << "    ";
	}
	std::cout << "\n";
}


void Character::PrintLearnedSkills()
{
	for (int i = 0; i < learnedSkills.size(); i++)
	{
		std::cout << i << ". " << learnedSkills[i]->GetName() << "    ";
	}
	std::cout << "\n";
}


void Character::StatusEffectOnTurnStart()
{
	for (int i = 0; i < statusEffects.size(); i++)
	{
		statusEffects[i]->OnTurnStart(*this);
	}
}