#pragma once

#include <vector>
#include <memory>

#include "Skill.h"
#include "StatusEffect.h"

class Character
{
private:
	std::string name;
	int maxHp;
	int hp;
	int attackPower;
	bool isStunned = false;
	std::vector<std::unique_ptr<Skill>> learnedSkills;
	std::vector<std::unique_ptr<Skill>> availableSkills;
	std::vector<std::unique_ptr<StatusEffect>> statusEffects;

public:
	Character(std::string name_, int hp_, int attackPower_);
	~Character();

	// getter
	int GetHp();
	int GetAttackPower();
	bool GetIsStunned();
	std::string GetName();
	std::vector<std::unique_ptr<Skill>>& GetLearnedSkills();
	std::vector<std::unique_ptr<Skill>>& GetAvailableSkills();
	std::vector<std::unique_ptr<StatusEffect>>& GetStatusEffects();

	// setter
	void SetIsStunned(bool flag);

	// vector handling
	void AddAvailableSkills(std::unique_ptr<Skill> skill);
	void AddLearnedSkills(std::unique_ptr<Skill> skill);
	void AddStatusEffect(std::unique_ptr<StatusEffect> statusEffect);

	// update status
	void TakeDamage(int dmg);
	void RestoreHp(int amt);
	void UpdateStatusEffects();

	// get status
	bool IsDead();

	// skill
	void LearnSkill(int choice);
	SkillInfo ActivateSkill(int choice, Character& user, Character& target);
};