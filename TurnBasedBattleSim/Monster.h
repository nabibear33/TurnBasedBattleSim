#pragma once

#include "Character.h"


class Monster : public Character
{
private:

public:
	Monster(std::string name_, int hp_, int attackPower_, int defense_, int critical_);
	~Monster();
};