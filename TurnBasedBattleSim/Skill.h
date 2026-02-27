#pragma once

#include <string>

#include "Types.h"

class Character;


class Skill
{
private:
public:
	virtual SkillInfo Activate(Character& user, Character& target) = 0;
	virtual ~Skill() = default;
	virtual std::string GetName() const = 0;
};


class BasicAttack : public Skill
{
public:
	SkillInfo Activate(Character& user, Character& target) override;
	std::string GetName() const override;
};


class FireBall : public Skill
{
public:
	SkillInfo Activate(Character& user, Character& target) override;
	std::string GetName() const override;
};


class Heal : public Skill
{
public:
	SkillInfo Activate(Character& user, Character& target) override;
	std::string GetName() const override;
};


class PoisonArrow : public Skill
{
public:
	SkillInfo Activate(Character& user, Character& target) override;
	std::string GetName() const override;
};


class StunningArrow : public Skill
{
public:
	SkillInfo Activate(Character& user, Character& target) override;
	std::string GetName() const override;
};