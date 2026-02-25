#pragma once

#include "Character.h"

enum class SkillIdx
{
	BASIC_ATTACK = 0,
	FIREBALL,
	HEAL
};


class Skill
{
private:
public:
	virtual void Activate(Character& user, Character& target) = 0;
	virtual ~Skill() = default;
};


class BasicAttack : public Skill
{
	void Activate(Character& user, Character& target);
};


class FireBall : public Skill
{
	void Activate(Character& user, Character& target);
};


class Heal : public Skill
{
	void Activate(Character& user, Character& target);
};