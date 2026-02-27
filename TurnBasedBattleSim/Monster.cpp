#include "Monster.h"


Monster::Monster(std::string name_, int hp_, int attackPower_) : Character(name_, hp_, attackPower_)
{
	AddLearnedSkills(std::make_unique<BasicAttack>());
}
Monster::~Monster() {}