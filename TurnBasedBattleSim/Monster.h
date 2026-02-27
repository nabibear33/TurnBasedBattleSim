#pragma once

#include "Character.h"


class Monster : public Character
{
private:

public:
	Monster(int maxHp_, int hp_, int attackPower_);
	~Monster();
};