#pragma once

#include <vector>
#include <memory>

#include "Skill.h"
#include "StatusEffect.h"

class Character
{
private:
	int maxHp;
	int hp;
	int attackPower;
	std::vector<std::unique_ptr<Skill>> learnedSkills;
	std::vector<std::unique_ptr<Skill>> availableSkills;
	std::vector<std::unique_ptr<StatusEffect>> statusEffects;

public:
	Character(int maxHp_, int hp_, int attackPower_);
	~Character();

	// getter
	int GetHp();
	int GetAttackPower();

	// setter
	void SetAvailableSkills(std::unique_ptr<Skill> skill);
	void SetLearnedSkills(std::unique_ptr<Skill> skill);
	void AddStatusEffect(std::unique_ptr<StatusEffect> statusEffect);

	// change status
	void TakeDamage(int dmg);
	void RestoreHp(int amt);
	void StatusEffectOnTurnStart();

	// get status
	bool IsDead();

	// skill
	void LearnSkill(int choice);
	void ActivateSkill(int choice, Character& user, Character& target);

	// ui
	void PrintLearnedSkills();
	void PrintAvailableSkills();
};