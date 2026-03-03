#pragma once

#include <string>
#include <random>

#include "Types.h"

class Character;


class Skill
{
private:
	std::random_device rd;
public:
	virtual SkillInfo Activate(Character& user, Character& target) = 0;
	virtual ~Skill() = default;
	virtual std::string GetName() const = 0;
	double GetUniformRandomValue(double s, double e);
	DamageResult CalculateDamage(Character& user, Character& target, int rawDamage);
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