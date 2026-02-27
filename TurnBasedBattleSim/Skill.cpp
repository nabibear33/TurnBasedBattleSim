#include "Skill.h"
#include "Character.h"
#include "StatusEffect.h"


void BasicAttack::Activate(Character& user, Character& target)
{
	target.TakeDamage(user.GetAttackPower());
}


std::string BasicAttack::GetName() const
{
	return "Basic Attack";
}


void FireBall::Activate(Character& user, Character& target)
{
	target.TakeDamage(2 * user.GetAttackPower());
	target.AddStatusEffect(std::make_unique<Burn>());
}


std::string FireBall::GetName() const
{
	return "FireBall";
}


void Heal::Activate(Character& user, Character& target)
{
	user.RestoreHp(user.GetAttackPower());
}


std::string Heal::GetName() const
{
	return "Heal";
}


void PoisonArrow::Activate(Character& user, Character& target)
{
	target.TakeDamage(user.GetAttackPower());
	target.AddStatusEffect(std::make_unique<Poison>());
}


std::string PoisonArrow::GetName() const
{
	return "Poison Arrow";
}


void StunningArrow::Activate(Character& user, Character& target)
{
	target.TakeDamage(user.GetAttackPower());
	target.AddStatusEffect(std::make_unique<Stun>());
}


std::string StunningArrow::GetName() const
{
	return "Stunning Arrow";
}