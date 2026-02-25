#include "Skill.h"


void BasicAttack::Activate(Character& user, Character& target)
{
	target.TakeDamage(user.GetAttackPower());
}


void FireBall::Activate(Character& user, Character& target)
{
	target.TakeDamage(2 * user.GetAttackPower());
}


void Heal::Activate(Character& user, Character& target)
{
	user.GetHeal(user.GetAttackPower());
}