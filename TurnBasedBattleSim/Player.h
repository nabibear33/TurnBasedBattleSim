#pragma once

#include "Character.h"
#include "Skill.h"
#include <vector>

class Player : public Character
{
private:
	std::vector<Skill*> skill_list;
public:
	Player(int maxHp_, int hp_, int attackPower_);
	~Player();

	void ActivateSkill(SkillIdx choice, Character& user, Character& target);

};