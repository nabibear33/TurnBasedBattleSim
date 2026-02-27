#include "Monster.h"


Monster::Monster(int maxHp_, int hp_, int attackPower_) : Character(maxHp_, hp_, attackPower_)
{
	SetLearnedSkills(std::make_unique<BasicAttack>());
}
Monster::~Monster() {}