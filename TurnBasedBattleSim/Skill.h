#pragma once

#include <string>

class Character;


class Skill
{
private:
public:
	virtual void Activate(Character& user, Character& target) = 0;
	virtual ~Skill() = default;
	virtual std::string GetName() const = 0;
};


class BasicAttack : public Skill
{
public:
	void Activate(Character& user, Character& target) override;
	std::string GetName() const override;
};


class FireBall : public Skill
{
public:
	void Activate(Character& user, Character& target) override;
	std::string GetName() const override;
};


class Heal : public Skill
{
public:
	void Activate(Character& user, Character& target) override;
	std::string GetName() const override;
};


class PoisonArrow : public Skill
{
public:
	void Activate(Character& user, Character& target) override;
	std::string GetName() const override;
};


class StunningArrow : public Skill
{
public:
	void Activate(Character& user, Character& target) override;
	std::string GetName() const override;
};