#pragma once

class Character
{
private:
	int hp;
	int attackPower;

public:
	Character(int hp_, int attackPower_);
	~Character();

	int GetHp();
	int GetAttackPower();
	void TakeDamage(int dmg);
	bool IsDead();
};