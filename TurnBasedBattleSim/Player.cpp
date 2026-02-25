#include "Player.h"


Player::Player(int maxHp_, int hp_, int attackPower_) : Character(maxHp_, hp_, attackPower_)
{
	skill_list.push_back(new BasicAttack());
	skill_list.push_back(new FireBall());
	skill_list.push_back(new Heal());

}
Player::~Player()
{
	for (auto s : skill_list)
	{
		delete s;
	}
}


void Player::ActivateSkill(SkillIdx choice, Character& user, Character& target)
{
	int idx = static_cast<int>(choice);
	Skill* selectedSkill = skill_list[idx];
	selectedSkill->Activate(user, target);
}