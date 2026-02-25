#pragma once

#include "Character.h"
#include "Skill.h"
#include <vector>


class Monster : public Character
{
private:
	std::vector<Skill*> skill_list;
public:
	Monster(int maxHp_, int hp_, int attackPower_);
	~Monster();

	void ActivateSkill(SkillIdx choice, Character& user, Character& target);
};