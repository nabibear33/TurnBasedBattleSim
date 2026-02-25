#pragma once

class Character
{
private:
	int maxHp;
	int hp;
	int attackPower;

public:
	Character(int maxHp_, int hp_, int attackPower_);
	~Character();

	int GetHp();
	int GetAttackPower();
	void TakeDamage(int dmg);
	void GetHeal(int amt);
	bool IsDead();
};