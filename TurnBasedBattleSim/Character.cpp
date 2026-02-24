#include "Character.h"
#include <algorithm>

Character::Character(int hp_, int attackPower_) : hp(hp_), attackPower(attackPower_) {}
Character::~Character() {}

void Character::TakeDamage(int dmg)
{
	hp = std::max(hp - dmg, 0);
}

bool Character::IsDead()
{
	return hp <= 0;
}