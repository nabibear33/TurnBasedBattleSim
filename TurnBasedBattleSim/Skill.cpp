#include "Skill.h"
#include "Character.h"
#include "StatusEffect.h"


SkillInfo BasicAttack::Activate(Character& user, Character& target)
{
	int amount = user.GetAttackPower();

	target.TakeDamage(amount);

	SkillInfo skillInfo;
	skillInfo.type = SkillType::DAMAGE;
	skillInfo.skillName = this->GetName();
	skillInfo.casterName = user.GetName();
	skillInfo.targetName = target.GetName();
	skillInfo.value = amount;
	return skillInfo;
}


std::string BasicAttack::GetName() const
{
	return "Basic Attack";
}


SkillInfo FireBall::Activate(Character& user, Character& target)
{
	int amount = 2 * user.GetAttackPower();
	
	target.TakeDamage(amount);
	target.AddStatusEffect(std::make_unique<Burn>(2));
	
	SkillInfo skillInfo;
	skillInfo.type = SkillType::DAMAGE;
	skillInfo.skillName = this->GetName();
	skillInfo.casterName = user.GetName();
	skillInfo.targetName = target.GetName();
	skillInfo.value = amount;
	return skillInfo;
}


std::string FireBall::GetName() const
{
	return "FireBall";
}


SkillInfo Heal::Activate(Character& user, Character& target)
{
	int amount = user.GetAttackPower();

	user.RestoreHp(amount);

	SkillInfo skillInfo;
	skillInfo.type = SkillType::HEAL;
	skillInfo.skillName = this->GetName();
	skillInfo.casterName = user.GetName();
	skillInfo.targetName = user.GetName();
	skillInfo.value = amount;
	return skillInfo;
}


std::string Heal::GetName() const
{
	return "Heal";
}


SkillInfo PoisonArrow::Activate(Character& user, Character& target)
{
	int amount = user.GetAttackPower();

	target.TakeDamage(amount);
	target.AddStatusEffect(std::make_unique<Poison>(3));

	SkillInfo skillInfo;
	skillInfo.type = SkillType::DAMAGE;
	skillInfo.skillName = this->GetName();
	skillInfo.casterName = user.GetName();
	skillInfo.targetName = target.GetName();
	skillInfo.value = amount;
	return skillInfo;
}


std::string PoisonArrow::GetName() const
{
	return "Poison Arrow";
}


SkillInfo StunningArrow::Activate(Character& user, Character& target)
{
	int amount = user.GetAttackPower();

	target.TakeDamage(amount);
	target.AddStatusEffect(std::make_unique<Stun>(1));
	target.SetIsStunned(true);

	SkillInfo skillInfo;
	skillInfo.type = SkillType::DAMAGE;
	skillInfo.skillName = this->GetName();
	skillInfo.casterName = user.GetName();
	skillInfo.targetName = target.GetName();
	skillInfo.value = amount;
	return skillInfo;
}


std::string StunningArrow::GetName() const
{
	return "Stunning Arrow";
}