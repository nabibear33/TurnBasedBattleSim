#include "Skill.h"
#include "Character.h"
#include "StatusEffect.h"


double Skill::GetUniformRandomValue(double s, double e)
{
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(s, e);
	return dist(gen);
}


DamageResult Skill::CalculateDamage(Character& user, Character& target, int rawDamage)
{
	const double defense = target.GetDefense();
	double defenseMultiplier = 100.0 / (100.0 + defense);
	
	double critRoll = GetUniformRandomValue(0.0, 1.0);
	bool isCritical = critRoll < (user.GetCritical() / 100.0);
	double criticalMultiplier = (isCritical) ? 2.0 : 1.0;
	
	double randomMultiplier = GetUniformRandomValue(0.9, 1.1);

	DamageResult damageResult{ static_cast<int>(rawDamage * defenseMultiplier * criticalMultiplier * randomMultiplier), isCritical };
	return damageResult;
}


SkillInfo BasicAttack::Activate(Character& user, Character& target)
{
	DamageResult result = CalculateDamage(user, target, user.GetAttackPower());

	target.TakeDamage(result.damage);

	SkillInfo skillInfo{
		SkillType::DAMAGE,
		this->GetName(),
		user.GetName(),
		target.GetName(),
		result.isCritical,
		result.damage,
	};
	return skillInfo;
}


std::string BasicAttack::GetName() const
{
	return "Basic Attack";
}


SkillInfo FireBall::Activate(Character& user, Character& target)
{
	DamageResult result = CalculateDamage(user, target, 2 * user.GetAttackPower());

	target.TakeDamage(result.damage);
	target.AddStatusEffect(std::make_unique<Burn>(2));

	SkillInfo skillInfo{
		SkillType::DAMAGE,
		this->GetName(),
		user.GetName(),
		target.GetName(),
		result.isCritical,
		result.damage,
	};
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

	SkillInfo skillInfo{
		SkillType::HEAL,
		this->GetName(),
		user.GetName(),
		user.GetName(),
		amount
	};
	return skillInfo;
}


std::string Heal::GetName() const
{
	return "Heal";
}


SkillInfo PoisonArrow::Activate(Character& user, Character& target)
{
	DamageResult result = CalculateDamage(user, target, user.GetAttackPower());

	target.TakeDamage(result.damage);
	target.AddStatusEffect(std::make_unique<Poison>(3));

	SkillInfo skillInfo{
		SkillType::DAMAGE,
		this->GetName(),
		user.GetName(),
		target.GetName(),
		result.isCritical,
		result.damage,
	};
	return skillInfo;
}


std::string PoisonArrow::GetName() const
{
	return "Poison Arrow";
}


SkillInfo StunningArrow::Activate(Character& user, Character& target)
{
	DamageResult result = CalculateDamage(user, target, user.GetAttackPower());

	target.TakeDamage(result.damage);
	target.AddStatusEffect(std::make_unique<Stun>(1));

	SkillInfo skillInfo{
		SkillType::DAMAGE,
		this->GetName(),
		user.GetName(),
		target.GetName(),
		result.isCritical,
		result.damage,
	};
	return skillInfo;
}


std::string StunningArrow::GetName() const
{
	return "Stunning Arrow";
}