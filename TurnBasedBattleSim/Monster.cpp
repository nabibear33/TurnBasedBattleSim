#include "Monster.h"


Monster::Monster(std::string name_, int hp_, int attackPower_, int defense_, int critical_) : Character(name_, hp_, attackPower_, defense_, critical_)
{
	AddLearnedSkills(std::make_unique<BasicAttack>());
}
Monster::~Monster() {}