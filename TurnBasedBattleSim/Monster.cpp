#include "Monster.h"


Monster::Monster(int maxHp_, int hp_, int attackPower_) : Character(maxHp_, hp_, attackPower_)
{
	skill_list.push_back(new BasicAttack());

}
Monster::~Monster()
{
	for (auto s : skill_list)
	{
		delete s;
	}
}


void Monster::ActivateSkill(SkillIdx choice, Character& user, Character& target)
{
	int idx = static_cast<int>(choice);
	Skill* selectedSkill = skill_list[idx];
	selectedSkill->Activate(user, target);
}