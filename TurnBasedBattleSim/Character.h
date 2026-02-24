#pragma once

class Character
{
private:
	int hp;
	int attackPower;

public:
	Character(int hp_, int attackPower_);
	~Character();

	void TakeDamage(int dmg);
	bool IsDead();
};