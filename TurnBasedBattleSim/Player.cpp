#include "Player.h"


Player::Player(int maxHp_, int hp_, int attackPower_) : Character(maxHp_, hp_, attackPower_)
{
	SetLearnedSkills(std::make_unique<BasicAttack>());
	SetAvailableSkills(std::make_unique<FireBall>());
	SetAvailableSkills(std::make_unique<Heal>());
	SetAvailableSkills(std::make_unique<PoisonArrow>());
	SetAvailableSkills(std::make_unique<StunningArrow>());
}
Player::~Player() {}