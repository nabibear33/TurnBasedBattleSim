#include "Player.h"


Player::Player(std::string name_, int hp_, int attackPower_, int defense_, int critical_) : Character(name_, hp_, attackPower_, defense_, critical_)
{
	AddLearnedSkills(std::make_unique<BasicAttack>());
	AddAvailableSkills(std::make_unique<FireBall>());
	AddAvailableSkills(std::make_unique<Heal>());
	AddAvailableSkills(std::make_unique<PoisonArrow>());
	AddAvailableSkills(std::make_unique<StunningArrow>());
}
Player::~Player() {}