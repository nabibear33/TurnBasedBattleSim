#include "Character.h"
#include <algorithm>

Character::Character(int maxHp_, int hp_, int attackPower_) : maxHp(maxHp_), hp(hp_), attackPower(attackPower_) {}
Character::~Character() {}

int Character::GetHp()
{
	return hp;
}

int Character::GetAttackPower()
{
	return attackPower;
}


void Character::TakeDamage(int dmg)
{
	hp = std::max(hp - dmg, 0);
}


void Character::GetHeal(int amt)
{
	hp = std::min(hp + amt, maxHp);
}


bool Character::IsDead()
{
	return hp <= 0;
}