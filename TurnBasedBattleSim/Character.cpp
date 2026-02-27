#include <algorithm>
#include <iostream>

#include "Character.h"


Character::Character(std::string name_, int hp_, int attackPower_) : name(name_), maxHp(hp_), hp(hp_), attackPower(attackPower_) {}
Character::~Character() {}

int Character::GetHp()
{
	return hp;
}

int Character::GetAttackPower()
{
	return attackPower;
}


bool Character::GetIsStunned()
{
	return isStunned;
}


std::vector<std::unique_ptr<Skill>>& Character::GetLearnedSkills()
{
	return learnedSkills;
}


std::vector<std::unique_ptr<Skill>>& Character::GetAvailableSkills()
{
	return availableSkills;
}


std::vector<std::unique_ptr<StatusEffect>>& Character::GetStatusEffects()
{
	return statusEffects;
}


std::string Character::GetName()
{
	return name;
}


void Character::TakeDamage(int dmg)
{
	hp = std::max(hp - dmg, 0);
}


void Character::RestoreHp(int amt)
{
	hp = std::min(hp + amt, maxHp);
}


void Character::SetIsStunned(bool flag)
{
	isStunned = flag;
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


SkillInfo Character::ActivateSkill(int choice, Character& user, Character& target)
{
	Skill* selectedSkill = learnedSkills[choice].get();
	SkillInfo skillInfo = selectedSkill->Activate(user, target);
	return skillInfo;
}


void Character::AddAvailableSkills(std::unique_ptr<Skill> skill)
{
	availableSkills.push_back(std::move(skill));
}


void Character::AddLearnedSkills(std::unique_ptr<Skill> skill)
{
	learnedSkills.push_back(std::move(skill));
}


void Character::AddStatusEffect(std::unique_ptr<StatusEffect> statusEffect)
{
	statusEffect->Apply(*this);
	statusEffects.push_back(std::move(statusEffect));
}


void Character::UpdateStatusEffects()
{
	for (int i = 0; i < statusEffects.size(); i++)
	{
		statusEffects[i]->OnTurnStart(*this);
	}

	for (auto& effect : statusEffects)
	{
		effect->DecrementTurn();
		if (effect->IsExpired()) {
			effect->OnExpire(*this);
		}
	}

	statusEffects.erase(
		std::remove_if(
			statusEffects.begin(),
			statusEffects.end(),
			[](const std::unique_ptr<StatusEffect>& e) { return e->IsExpired(); }
		),
		statusEffects.end()
	);
}